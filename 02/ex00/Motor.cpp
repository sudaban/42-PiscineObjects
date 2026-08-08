#include "Motor.hpp"

#include "Transmission.hpp"

#include <iostream>


Motor::Motor() : m_chamber(0), m_crankshaft(0)
{
    m_chamber = new ExplosionChamber();
    m_crankshaft = new Crankshaft();
    m_chamber->SetCrankshaft(m_crankshaft);
}

Motor::~Motor()
{
    delete m_chamber;
    delete m_crankshaft;
}

void Motor::ConnectToTransmission(Transmission* p_transmission)
{
    std::cout << "[Motor] connected to transmission" << std::endl;
    if (p_transmission != 0)
    {
        m_crankshaft->SetTransmission(p_transmission);
    }
}

void Motor::AddInjector(Injector* p_injector)
{
    if (p_injector != 0)
    {
        p_injector->SetChamber(m_chamber);
        m_injectors.push_back(p_injector);
    }
}

ExplosionChamber* Motor::GetChamber()
{
    return m_chamber;
}

Crankshaft* Motor::GetCrankshaft()
{
    return m_crankshaft;
}
