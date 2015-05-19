#ifndef ALARMS_ALARMWIDGET_HPP
#define ALARMS_ALARMWIDGET_HPP

#include <memory>
#include <boost/format.hpp>

#include <ui/Widget.hpp>

#ifdef __EMSCRIPTEN__
  #include <emscripten.h>
  #include <emscripten/bind.h>
#endif

namespace alarms {

  /**
   * \brief Supports rendering an alarm from Alarm instances.
   */
  class AlarmWidget : public ui::Widget {
    public:
      AlarmWidget(std::shared_ptr<SDL_Surface> surface, const std::vector<Alarm> &alarms) 
        : m_surface(surface),
          m_alarms(alarms) {}

      virtual void draw() const override {
        // Clear the target container surface
        boxColor(m_surface.get(), 0, 0, m_surface->w, m_surface->h, 0xffffffff);

        draw_triangle();
        draw_alarm_text();

        SDL_UpdateRect(m_surface.get(), 0, 0, 0, 0);
      }

      virtual void onClick() override {
        ++current_alarm;
        if (current_alarm >= m_alarms.size()) {
          current_alarm = 0;
        }
      }

      unsigned int current_alarm = 0;

    private:
      std::shared_ptr<SDL_Surface> m_surface;
      std::vector<Alarm> m_alarms;

      void draw_triangle() const {

        lineColor(m_surface.get(), 15, 10, 20, 20, 0xff0000ff);
        lineColor(m_surface.get(), 20, 20, 10, 20, 0xff0000ff);
        lineColor(m_surface.get(), 10, 20, 15, 10, 0xff0000ff);
      }

      void draw_alarm_text() const {
        TTF_Init();
        TTF_Font *font = TTF_OpenFont("Arial", 16);

        SDL_Color color = { 0xff, 0x99, 0x00, 0xff };
        auto alarm_txt = str(boost::format("%1% - Severity : %2% - Ack : %3%")
            % m_alarms[current_alarm].text
            % m_alarms[current_alarm].severity
            % m_alarms[current_alarm].acknowledged);

        SDL_Surface *text = TTF_RenderText_Solid(font, alarm_txt.data(), color);
        SDL_Rect dest{30, 10, 0,0};
        SDL_BlitSurface (text, NULL, m_surface.get(), &dest);
        SDL_FreeSurface(text);

        SDL_Surface *text2 = TTF_RenderText_Solid(font, "+ See next", color);
        SDL_Rect dest2{60, 30, 0,0};
        SDL_BlitSurface (text2, NULL, m_surface.get(), &dest2);
        SDL_FreeSurface(text2);
      }
  };

#ifdef __EMSCRIPTEN__
  using namespace emscripten;

  EMSCRIPTEN_BINDINGS(AlarmWidget) {
    class_<AlarmWidget>("AlarmWidget")
      .smart_ptr_constructor("AlarmWidgetSmartPtr", 
          &std::make_shared<AlarmWidget, 
                            std::shared_ptr<SDL_Surface> ,
                            const std::vector<Alarm>& >)
      .function("draw", &AlarmWidget::draw)
      .function("onClick", &AlarmWidget::onClick)
      .property("current_alarm", &AlarmWidget::current_alarm)
      ;
  }
#endif

}


#endif
