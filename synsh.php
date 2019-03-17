<?php
$synthcore = proc_open(dirname(__FILE__).'/synth', [
    '0' => ['pipe', 'r'],   // stdin
    '1' => ['pipe', 'w'],   // stdout
    '2' => ['pipe', 'w']    // stderr
], $pipes);

if (is_resource($synthcore)) {
    $stdin = $pipes[0];
    $stdout = $pipes[1];
    $stderr = $pipes[2];
    stream_set_blocking($stderr, false);

    while (($commandStr = readline('> '))!==false) {
        readline_add_history($commandStr);
        $commandStr = preg_replace('/#.*/', '', $commandStr);
        $args = preg_split('/\s/', $commandStr, -1, PREG_SPLIT_NO_EMPTY);
        execute($args);

        echo stream_get_contents($stderr);

        $responseJson = "";
        while (($ch = fgetc($stdout))!=="\0") {
            $responseJson .= $ch;
        }
        receive(json_decode($responseJson)->response);

        echo stream_get_contents($stderr);
    }

    fclose($stdin);
    fclose($stdout);
    fclose($stderr);
    proc_close($synthcore);
}

function execute($args)
{
    global $stdin;

    fwrite($stdin, json_encode(['request' => ['args' => $args]])."\0");
}

function receive($response)
{
    if (isset($response->error)) {
        echo $response->error."\n";
    } else {
        printResponse($response, 0);
    }
}

function printResponse($response, $level)
{
    foreach ($response as $key => $value) {
        for ($i = 0; $i < $level; $i++) {
            echo " ";
        }
        echo "${key}: ";
        if (is_array($value) || is_object($value)) {
            echo "\n";
            printResponse($value, $level + 2);
        } else {
            echo print_r($value, true)."\n";
        }
    }
}
