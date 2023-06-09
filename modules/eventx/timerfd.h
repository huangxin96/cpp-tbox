#ifndef TBOX_EVENTX_ACCURATE_TIMER_H_20230607
#define TBOX_EVENTX_ACCURATE_TIMER_H_20230607

#include <functional>
#include <chrono>
#include <tbox/event/timer_event.h>
#include <tbox/event/fd_event.h>

namespace tbox {
namespace eventx {
class TimerFd : public tbox::event::Event {
  public:
    TimerFd(tbox::event::Loop *loop, const std::string &what);
    ~TimerFd();

    virtual bool isEnabled() const override;
    virtual bool enable() override;
    virtual bool disable() override;
    virtual tbox::event::Loop* getLoop() const override;

    virtual bool initialize(const std::chrono::nanoseconds &time_span, Mode mode);

    using CallbackFunc = std::function<void ()>;
    virtual void setCallback(CallbackFunc &&cb);

  private:
    void onEvent(short events);

  private:
    CallbackFunc cb_{ nullptr };
    tbox::event::Loop *loop_{ nullptr };
    tbox::event::FdEvent *timer_fd_event_{ nullptr };
    int timer_fd_{ -1 };
    bool is_inited_{ false };
    bool is_enabled_{ false };
    std::chrono::milliseconds interval_ { 0 };
    Mode mode_{ Mode::kOneshot };
};
}
}
#endif