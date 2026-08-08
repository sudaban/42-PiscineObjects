#include "Direction.hpp"

#include <cmath>
#include <iostream>


Direction::Direction() : m_angle(0.0f)
{
}

void Direction::Turn(float p_angle)
{
    m_angle = p_angle;
    std::cout << "[Direction] turn angle=" << p_angle << std::endl;
    float force = std::fabs(p_angle) * 10.0f;
    for (int i = 0; i < m_wheel_count; ++i)
    {
        m_wheels[i].ExecuteRotation(force);
    }
}

Wheel* Direction::GetWheels()
{
    return m_wheels;
}

int Direction::GetWheelCount() const
{
    return m_wheel_count;
}
