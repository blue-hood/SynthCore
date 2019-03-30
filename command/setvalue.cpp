#include "command.hpp"

#include <core/core.hpp>
#include <io.hpp>

void setvalueHandler(vector<string> &args) {
  if (args.size() != 3) {
    throw runtime_error("構文: setvalue (InPort UUID) (value)");
  }

  uuid_t uuid;
  if (parseUuid(args[1], &uuid)) {
    throw runtime_error("不正な InPort UUID です。");
  }

  PortIn_p in = searchPortIn(uuid);
  if (!in) {
    throw runtime_error("存在しない InPort です。");
  }

  in->val = stod(args[2]);

  EmptyResponse response;
  respond(response);
}