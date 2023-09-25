#include <gui/loadscreen_screen/LoadScreenView.hpp>

LoadScreenView::LoadScreenView()
{

}

void LoadScreenView::setupScreen()
{
    LoadScreenViewBase::setupScreen();
}

void LoadScreenView::tearDownScreen()
{
    LoadScreenViewBase::tearDownScreen();
}

void LoadScreenView::updateProgbar(uint32_t progress)
{
  m_initProgressBar.setValue(progress);

  if (progress >= 100)
  {
    application().gotoMenuScreenScreenCoverTransitionEast();
  }
}
