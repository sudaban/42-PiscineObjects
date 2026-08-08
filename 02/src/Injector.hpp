#ifndef INJECTOR_HPP
#define INJECTOR_HPP

#include "LinkablePart.hpp"


class ExplosionChamber;

class Injector : public LinkablePart
{
private:
    ExplosionChamber* m_chamber;

public:
    Injector();
    void Execute(float p_pression);
    void SetChamber(ExplosionChamber* p_chamber);
};


#endif
