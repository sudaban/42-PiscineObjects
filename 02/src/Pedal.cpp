#include "Pedal.hpp"

#include "LinkablePart.hpp"

#include <iostream>


Pedal::Pedal() : m_target(0)
{
}

void Pedal::SetTarget(LinkablePart* p_part)
{
    m_target = p_part;
}

void Pedal::Use(float p_pression)
{
    std::cout << "[Pedal] use pression=" << p_pression << std::endl;
    if (m_target != 0)
    {
        m_target->Execute(p_pression);
    }
}
