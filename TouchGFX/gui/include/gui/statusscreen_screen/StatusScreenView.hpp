#ifndef STATUSSCREENVIEW_HPP
#define STATUSSCREENVIEW_HPP

#include <gui_generated/statusscreen_screen/StatusScreenViewBase.hpp>
#include <gui/statusscreen_screen/StatusScreenPresenter.hpp>

class StatusScreenView : public StatusScreenViewBase
{
public:
    StatusScreenView();
    virtual ~StatusScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STATUSSCREENVIEW_HPP
