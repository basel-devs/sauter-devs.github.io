#ifndef UI_WIDGETSRENDERER_HPP
#define UI_WIDGETSRENDERER_HPP

#include <memory>
#include <functional>

#ifdef __EMSCRIPTEN__
  #include <emscripten.h>
  #include <emscripten/bind.h>
#endif

#include <ui/Widget.hpp>

namespace ui {

  std::shared_ptr<SDL_Surface> create_rendering_surface(int width, int height) { 
    return std::shared_ptr<SDL_Surface>(SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE));
  }

#ifdef __EMSCRIPTEN__
  using namespace emscripten;

  EMSCRIPTEN_BINDINGS(smart_pointers) {
    class_<SDL_Surface>("SDL_Surface")
        .constructor<>()
        .smart_ptr<std::shared_ptr<SDL_Surface>>("SDL_SurfaceSmartPtr")
        ;
  }

  EMSCRIPTEN_BINDINGS(ui) {
    function("create_rendering_surface", &create_rendering_surface);
  }
#endif


  class WidgetsRenderer {
    public:
      void registerWidget(const std::shared_ptr<Widget> widget) {
        m_widgets.push_back(widget);
      }

      void run() {

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
          switch(event.type) {
            case SDL_QUIT:
              std::exit(0);
              break;

            case SDL_MOUSEBUTTONUP:
              SDL_MouseButtonEvent* m = reinterpret_cast<SDL_MouseButtonEvent*>(&event);
              for (auto widget : m_widgets) { 
                widget->onClick();
              }

              break;
                                    
          }
        }

        for (auto widget : m_widgets) { 
          widget->draw();
        }
      }

    private:
      std::vector<std::shared_ptr<Widget>> m_widgets;
      

  };
}

#endif
