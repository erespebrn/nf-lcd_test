#ifndef INSTRSCREENPRESENTER_HPP
#define INSTRSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class InstrScreenView;

class InstrScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    InstrScreenPresenter(InstrScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~InstrScreenPresenter() {}

private:
    InstrScreenPresenter();

    InstrScreenView& view;
};

#endif // INSTRSCREENPRESENTER_HPP
