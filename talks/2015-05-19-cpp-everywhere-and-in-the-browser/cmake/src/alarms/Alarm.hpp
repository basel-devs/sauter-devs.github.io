#ifndef ALARMS_ALARM_HPP
#define ALARMS_ALARM_HPP

#include <string>

namespace alarms { 
  
  /**
   * \Brief represents an alarm
   */
  struct Alarm {
    Alarm(int severity, const std::string& text, bool acknowledged)
      : severity(severity), text(text), acknowledged(acknowledged) {
    }

    int severity = 0;
    std::string text = "N/A";
    bool acknowledged = false;
  };
}

#endif
