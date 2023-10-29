#ifndef INSTRSCREENVIEW_HPP
#define INSTRSCREENVIEW_HPP

#include <gui_generated/instrscreen_screen/InstrScreenViewBase.hpp>
#include <gui/instrscreen_screen/InstrScreenPresenter.hpp>

class InstrScreenView : public InstrScreenViewBase
{
public:
    InstrScreenView();
    virtual ~InstrScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTRSCREENVIEW_HPP
