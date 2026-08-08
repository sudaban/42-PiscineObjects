#include "DAE.hpp"

#include "Direction.hpp"

#include <cmath>
#include <iostream>


DAE::DAE() : m_direction(0), m_force(0.0f)
{
}

void DAE::Use(float p_angle)
{
    m_force = std::fabs(p_angle) * 5.0f;
    std::cout << "[DAE] use angle=" << p_angle << " force=" << m_force << std::endl;
    if (m_direction != 0)
    {
        m_direction->Turn(p_angle);
    }
}

void DAE::SetDirection(Direction* p_direction)
{
    m_direction = p_direction;
}

float DAE::GetForce() const
{
    return m_force;
}

void DAE::SetForce(float p_force)
{
    m_force = p_force;
}
