#include <gui/loadscreen_screen/LoadScreenView.hpp>
#include <gui/loadscreen_screen/LoadScreenPresenter.hpp>

LoadScreenPresenter::LoadScreenPresenter(LoadScreenView& v)
    : view(v)
{

}

void LoadScreenPresenter::activate()
{

}

void LoadScreenPresenter::deactivate()
{

}

void LoadScreenPresenter::updateProgress(uint32_t progress)
{
  view.updateProgbar(progress);
}
