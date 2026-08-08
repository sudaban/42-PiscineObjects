#include "SteerWheel.hpp"

#include "DAE.hpp"

#include <iostream>


SteerWheel::SteerWheel() : m_dae(0)
{
}

void SteerWheel::Turn(float p_angle)
{
    std::cout << "[SteerWheel] turn angle=" << p_angle << std::endl;
    if (m_dae != 0)
    {
        m_dae->Use(p_angle);
    }
}

void SteerWheel::SetDae(DAE* p_dae)
{
    m_dae = p_dae;
}
