#pragma once
class Sketch;

#include "component.hpp"
#include "port_in.hpp"
#include "port_out.hpp"

#include <cereal/cereal.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <memory>
#include <vector>

using namespace std;

typedef unique_ptr<Component> Component_up;
typedef shared_ptr<PortIn> PortIn_p;
typedef shared_ptr<PortOut> PortOut_p;

class Sketch {
public:
  vector<Component_up> coms;
  vector<PortIn_p> int_ins;
  vector<PortOut_p> int_outs;
  bool onSim;

  Sketch();
  void appendCom(Component *com);
  void removeCom(Component *rm);
  void clearCom();
  void upInterface();
  void onSimStart();
  void onChangeTime(double dt);
  void onSimEnd();
  void exportExtends();

  template <class Archive> void serialize(Archive &archive) {
    vector<Component> coms;

    for (Component_up &com : this->coms) {
      coms.push_back(*com);
    }
    archive(CEREAL_NVP(coms));
  }
};
