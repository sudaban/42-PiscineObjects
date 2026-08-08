#include "Injector.hpp"

#include "ExplosionChamber.hpp"

#include <iostream>


Injector::Injector() : m_chamber(0)
{
}

void Injector::Execute(float p_pression)
{
    std::cout << "[Injector] execute pression=" << p_pression << std::endl;
    if (m_chamber != 0)
    {
        m_chamber->Fill(p_pression);
    }
}

void Injector::SetChamber(ExplosionChamber* p_chamber)
{
    m_chamber = p_chamber;
}
