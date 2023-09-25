#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include <stm32f7xx_hal.h>
#endif

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
  if (m_progressActive)
  {
    uint32_t diff = HAL_GetTick() - m_progressTick;
    if (diff > 20)
    {
      m_progressTick = HAL_GetTick();
      modelListener->updateProgress(++m_progressCnt);

      if (m_progressCnt > 100)
      {
        m_progressActive = false;
      }
    }
  }
#endif
}
