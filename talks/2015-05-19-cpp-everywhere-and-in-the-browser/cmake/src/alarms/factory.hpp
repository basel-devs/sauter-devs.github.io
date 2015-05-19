#ifndef ALARMS_FACTORY_HPP
#define ALARMS_FACTORY_HPP

#include <vector>

#ifdef __EMSCRIPTEN__
  #include <emscripten.h>
  #include <emscripten/bind.h>
#endif

#include <alarms/Alarm.hpp>

namespace alarms {

  std::vector<Alarm> from_file(const std::string &path) {
    std::vector<Alarm> alarms = {
      Alarm{1, "Bananas are frozen", false},
      Alarm{2, "It's raining men !", false},
      Alarm{1, "Fire in the hole", false}
    };

    return alarms;
  }

#ifdef __EMSCRIPTEN__
  using namespace emscripten;

  EMSCRIPTEN_BINDINGS(stl_wrappers) {
      register_vector<Alarm>("VectorAlarm");
  }

  EMSCRIPTEN_BINDINGS(alarms) {
    function("from_file", &from_file);
  }
#endif


}

#endif
