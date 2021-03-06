// Copyright 2019 BlueHood

#include "component.hpp"

#include <string>
#include <vector>

using std::string, std::vector;

static vector<string> g_com_names;
static vector<Component *(*)(string)> g_new_com_funcs;

#define registerComponent(Com)                                                 \
  do {                                                                         \
    g_com_names.push_back(string(#Com));                                       \
    g_new_com_funcs.push_back([](string com_name) -> Component * {             \
      return com_name == string(#Com) ? new Com() : nullptr;                   \
    });                                                                        \
  } while (0)

void initCom() {
  g_com_names.clear();
  g_new_com_funcs.clear();

  registerComponent(Speaker);
  registerComponent(Sine);
  registerComponent(Amplifier);
}

Component *newCom(string com_name) {
  for (Component *(*func)(string) : g_new_com_funcs) {
    Component *com = func(com_name);

    if (com != nullptr) {
      return com;
    }
  }

  return nullptr;
}
