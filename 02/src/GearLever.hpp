#ifndef GEAR_LEVER_HPP
#define GEAR_LEVER_HPP

#include "Gear.hpp"
#include "Singleton.hpp"


class GearLever : public Singleton<GearLever>
{
    friend class Singleton<GearLever>;

private:
    static const int m_gear_count = 5;
    Gear m_gears[m_gear_count];
    int m_level;

    GearLever();

public:
    void Change();
    Gear* ActiveGear();
    int GetLevel() const;
};


#endif
