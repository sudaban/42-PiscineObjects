#include "Gear.hpp"


Gear::Gear() : m_demultiplier(1)
{
}

Gear::Gear(int p_demultiplier) : m_demultiplier(p_demultiplier)
{
}

int Gear::GetDemultiplier() const
{
    return m_demultiplier;
}

void Gear::SetDemultiplier(int p_demultiplier)
{
    m_demultiplier = p_demultiplier;
}
