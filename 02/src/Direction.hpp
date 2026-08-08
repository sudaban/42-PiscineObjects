#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include "Wheel.hpp"


class Direction
{
private:
    static const int m_wheel_count = 4;
    Wheel m_wheels[m_wheel_count];
    float m_angle;

public:
    Direction();
    void Turn(float p_angle);
    Wheel* GetWheels();
    int GetWheelCount() const;
};


#endif
