#ifndef BRAKE_CONTROLLER_HPP
#define BRAKE_CONTROLLER_HPP

#include "Brake.hpp"
#include "LinkablePart.hpp"


class BrakeController : public LinkablePart
{
private:
    static const int m_brake_count = 4;
    Brake m_brakes[m_brake_count];

public:
    BrakeController();
    void Execute(float p_pression);
    Brake* GetBrakes();
    int GetBrakeCount() const;
};


#endif
