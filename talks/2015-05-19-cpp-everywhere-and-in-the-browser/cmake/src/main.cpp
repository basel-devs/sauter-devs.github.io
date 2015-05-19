#include <iostream>
#include <string>

#include <boost/bind.hpp>
#include <boost/function.hpp>

#include <ui/WidgetsRenderer.hpp>

#include <alarms/factory.hpp>
#include <alarms/AlarmWidget.hpp>

boost::function<void()> mainloop_function;
void mainloop() {
  mainloop_function();
}

int nomain() {
  SDL_Init(SDL_INIT_VIDEO);

  auto screen_surface = ui::create_rendering_surface(400, 200);


  auto alarm_widget = std::make_shared<alarms::AlarmWidget>(screen_surface, alarms::from_file(""));

  ui::WidgetsRenderer renderer;
  renderer.registerWidget(alarm_widget);

  mainloop_function = boost::bind(&ui::WidgetsRenderer::run, renderer);

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(mainloop, 0, 0);
#else
  while(1) {
    mainloop();
    SDL_Delay(33);
  }

  SDL_Quit();
#endif

  return 1;
}
