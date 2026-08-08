#include "ExplosionChamber.hpp"

#include "Crankshaft.hpp"

#include <iostream>


ExplosionChamber::ExplosionChamber() : m_crankshaft(0)
{
}

void ExplosionChamber::Fill(float p_volume)
{
    std::cout << "[ExplosionChamber] fill volume=" << p_volume << std::endl;
    if (m_crankshaft != 0)
    {
        m_crankshaft->ReceiveForce(p_volume);
    }
}

void ExplosionChamber::SetCrankshaft(Crankshaft* p_crankshaft)
{
    m_crankshaft = p_crankshaft;
}
