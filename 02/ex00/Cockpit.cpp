#include "Cockpit.hpp"

#include <iostream>


Cockpit::Cockpit()
    : m_pedal_accelerator(0), m_pedal_brake(0), m_steer_wheel(0), m_gear_lever(0)
{
    m_pedal_accelerator = new Pedal();
    m_pedal_brake = new Pedal();
    m_steer_wheel = new SteerWheel();
    m_gear_lever = GearLever::GetInstance();
}

Cockpit::~Cockpit()
{
    delete m_pedal_accelerator;
    delete m_pedal_brake;
    delete m_steer_wheel;
}

void Cockpit::Accelerate(float p_pression)
{
    std::cout << "[Cockpit] accelerate pression=" << p_pression << std::endl;
    if (m_pedal_accelerator != 0)
    {
        m_pedal_accelerator->Use(p_pression);
    }
}

void Cockpit::Brake(float p_pression)
{
    std::cout << "[Cockpit] brake pression=" << p_pression << std::endl;
    if (m_pedal_brake != 0)
    {
        m_pedal_brake->Use(p_pression);
    }
}

void Cockpit::TurnSteerWheel(float p_angle)
{
    std::cout << "[Cockpit] steer angle=" << p_angle << std::endl;
    if (m_steer_wheel != 0)
    {
        m_steer_wheel->Turn(p_angle);
    }
}

void Cockpit::ChangeGear()
{
    std::cout << "[Cockpit] change gear" << std::endl;
    if (m_gear_lever != 0)
    {
        m_gear_lever->Change();
    }
}

Pedal* Cockpit::GetAcceleratorPedal() const
{
    return m_pedal_accelerator;
}

Pedal* Cockpit::GetBrakePedal() const
{
    return m_pedal_brake;
}

SteerWheel* Cockpit::GetSteerWheel() const
{
    return m_steer_wheel;
}

GearLever* Cockpit::GetGearLever() const
{
    return m_gear_lever;
}
