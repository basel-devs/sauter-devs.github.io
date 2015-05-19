#ifndef UI_WIDGET_HPP
#define UI_WIDGET_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_ttf.h>

namespace ui {

  class Widget {
    public:
        virtual void draw() const = 0;

        virtual void onClick() = 0;

        virtual ~Widget(){};
  };

}

#endif
