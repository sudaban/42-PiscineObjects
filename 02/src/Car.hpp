#ifndef CAR_HPP
#define CAR_HPP

#include "BrakeController.hpp"
#include "Cockpit.hpp"
#include "Direction.hpp"
#include "Electronics.hpp"
#include "Motor.hpp"
#include "Transmission.hpp"

#include <vector>


class Car
{
private:
    BrakeController* m_brake_controller;
    Direction* m_direction;
    Transmission* m_transmission;
    Motor* m_motor;
    Electronics* m_electronics;
    Cockpit* m_cockpit;
    std::vector<Wheel*> m_wheels;

public:
    Car();
    ~Car();
    void Drive();
    BrakeController* GetBrakeController() const;
    Direction* GetDirection() const;
    Transmission* GetTransmission() const;
    Motor* GetMotor() const;
    Electronics* GetElectronics() const;
    Cockpit* GetCockpit() const;
};


#endif
