// Copyright 2019 BlueHood

#include "command.hpp"

#include <core/core.hpp>
#include <io.hpp>

using std::vector, std::string;

void lscomHandler(const vector<string> &args) {
  LscomResponse response;

  for (Component_up &com : g_sketch.coms) {
    LscomResponse::Component comResponse;

    comResponse.uuid = uuidStr(com->id);
    comResponse.type = com->com_name;
    response.components.push_back(comResponse);
  }

  respond(response);
}
