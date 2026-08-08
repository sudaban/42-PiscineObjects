#include "GearLever.hpp"

#include <iostream>


GearLever::GearLever() : m_level(0)
{
    m_gears[0].SetDemultiplier(1);
    m_gears[1].SetDemultiplier(2);
    m_gears[2].SetDemultiplier(3);
    m_gears[3].SetDemultiplier(4);
    m_gears[4].SetDemultiplier(5);
}

void GearLever::Change()
{
    m_level = (m_level + 1) % m_gear_count;
    std::cout << "[GearLever] level -> " << m_level
              << " (demultiplier=" << m_gears[m_level].GetDemultiplier() << ")" << std::endl;
}

Gear* GearLever::ActiveGear()
{
    return &m_gears[m_level];
}

int GearLever::GetLevel() const
{
    return m_level;
}
