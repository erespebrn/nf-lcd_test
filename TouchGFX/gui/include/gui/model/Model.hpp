#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

protected:
    ModelListener* modelListener;

private:
    uint32_t m_progressCnt = 0;
    uint32_t m_progressTick = 1;
    bool m_progressActive = true;
};

#endif // MODEL_HPP
