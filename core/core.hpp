// Copyright 2019 BlueHood

#pragma once

#include <uuid/uuid.h>

#include <string>

#include "component.hpp"
#include "in_port.hpp"
#include "out_port.hpp"
#include "sketch.hpp"

extern double g_spout;
extern int g_spcount;
extern Sketch g_sketch;

std::string uuidStr(uuid_t uuid);
int parseUuid(const std::string &uuid_str, uuid_t *uuid);
Component *searchCom(uuid_t uuid);
InPort *searchInPort(uuid_t uuid);
OutPort *searchOutPort(uuid_t uuid);
