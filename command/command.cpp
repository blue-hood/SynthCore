#include "command.hpp"

void addcomHandler(vector<string> &args);
void lscomHandler(vector<string> &args);
void lsportHandler(vector<string> &args);
void connectHandler(vector<string> &args);
void playHandler(vector<string> &args);
void stopHandler(vector<string> &args);
void callHandler(vector<string> &args);
void rmcomHandler(vector<string> &args);
void disconnHandler(vector<string> &args);

#define registerCommand(name)                                                  \
  { #name, name##Handler }

vector<Command> g_commands = {
    registerCommand(addcom),  registerCommand(lscom), registerCommand(lsport),
    registerCommand(connect), registerCommand(play),  registerCommand(stop),
    registerCommand(call),    registerCommand(rmcom), registerCommand(disconn),
};
