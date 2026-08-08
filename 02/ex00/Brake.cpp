#include "Brake.hpp"

#include "Wheel.hpp"

#include <iostream>


Brake::Brake() : m_wheel(0)
{
}

void Brake::Execute(float p_force)
{
    std::cout << "[Brake] execute force=" << p_force << std::endl;
    if (m_wheel != 0)
    {
        m_wheel->ExecuteRotation(p_force);
    }
}

void Brake::AttackWheel(Wheel* p_wheel)
{
    m_wheel = p_wheel;
    std::cout << "[Brake] attached to wheel" << std::endl;
}

Wheel* Brake::GetWheel() const
{
    return m_wheel;
}
