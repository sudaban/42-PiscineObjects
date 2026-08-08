#include "BrakeController.hpp"

#include <iostream>


BrakeController::BrakeController()
{
}

void BrakeController::Execute(float p_pression)
{
    std::cout << "[BrakeController] execute pression=" << p_pression
              << " on " << m_brake_count << " brake(s)" << std::endl;
    for (int i = 0; i < m_brake_count; ++i)
    {
        m_brakes[i].Execute(p_pression);
    }
}

Brake* BrakeController::GetBrakes()
{
    return m_brakes;
}

int BrakeController::GetBrakeCount() const
{
    return m_brake_count;
}
