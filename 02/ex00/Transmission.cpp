#include "Transmission.hpp"

#include <iostream>


void Transmission::AddWheel(Wheel* p_wheel)
{
    if (p_wheel != 0)
    {
        m_wheels.push_back(p_wheel);
    }
}

void Transmission::Activate(float p_force)
{
    std::cout << "[Transmission] activate force=" << p_force
              << " on " << m_wheels.size() << " wheel(s)" << std::endl;
    for (std::size_t i = 0; i < m_wheels.size(); ++i)
    {
        m_wheels[i]->ExecuteRotation(p_force);
    }
}
