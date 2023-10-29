#ifndef ROBOTSCREENVIEW_HPP
#define ROBOTSCREENVIEW_HPP

#include <gui_generated/robotscreen_screen/RobotScreenViewBase.hpp>
#include <gui/robotscreen_screen/RobotScreenPresenter.hpp>

class RobotScreenView : public RobotScreenViewBase
{
public:
    RobotScreenView();
    virtual ~RobotScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ROBOTSCREENVIEW_HPP
