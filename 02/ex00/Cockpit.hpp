#ifndef COCKPIT_HPP
#define COCKPIT_HPP

#include "GearLever.hpp"
#include "Pedal.hpp"
#include "SteerWheel.hpp"


class Cockpit
{
private:
    Pedal* m_pedal_accelerator;
    Pedal* m_pedal_brake;
    SteerWheel* m_steer_wheel;
    GearLever* m_gear_lever;

public:
    Cockpit();
    ~Cockpit();
    void Accelerate(float p_pression);
    void Brake(float p_pression);
    void TurnSteerWheel(float p_angle);
    void ChangeGear();
    Pedal* GetAcceleratorPedal() const;
    Pedal* GetBrakePedal() const;
    SteerWheel* GetSteerWheel() const;
    GearLever* GetGearLever() const;
};


#endif
