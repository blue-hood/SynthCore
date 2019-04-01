[![Build Status](https://travis-ci.org/blue-hood/synth.svg?branch=master)](https://travis-ci.org/blue-hood/synth)
[![Release](https://img.shields.io/github/release/blue-hood/synth.svg)](https://github.com/blue-hood/synth/releases/latest)
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE)

# synth
シンセサイザーで音作りをすることから、シンセサイザーそのものを作ることまで幅広く応用できます。

## 使い方
`$ ./synth`

ただし、synth の操作は標準入出力にて JSON 形式で行います。
ユーザーからの直接入力は想定していません。
コマンドラインで操作するには [synsh](https://github.com/blue-hood/synsh) をインストールしてください。

## インストール
1. `git clone --recursive` でリポジトリをダウンロードします。
2. synth ディレクトリで `make` します。
