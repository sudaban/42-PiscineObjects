#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include "Wheel.hpp"

#include <vector>


class Transmission
{
private:
    std::vector<Wheel*> m_wheels;

public:
    void AddWheel(Wheel* p_wheel);
    void Activate(float p_force);
};


#endif
