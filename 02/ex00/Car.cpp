#include "Car.hpp"

#include "DAE.hpp"

#include <iostream>


Car::Car()
    : m_brake_controller(0), m_direction(0), m_transmission(0),
      m_motor(0), m_electronics(0), m_cockpit(0)
{
    m_brake_controller = new BrakeController();
    m_direction = new Direction();
    m_transmission = new Transmission();
    m_motor = new Motor();
    m_electronics = new Electronics();
    m_cockpit = new Cockpit();

    m_wheels.resize(4);
    for (int i = 0; i < 4; ++i)
    {
        m_wheels[i] = new Wheel();
    }
    for (int i = 0; i < 4; ++i)
    {
        m_transmission->AddWheel(m_wheels[i]);
    }

    m_brake_controller->GetBrakes()[0].AttackWheel(m_wheels[0]);
    m_brake_controller->GetBrakes()[1].AttackWheel(m_wheels[1]);
    m_brake_controller->GetBrakes()[2].AttackWheel(m_wheels[2]);
    m_brake_controller->GetBrakes()[3].AttackWheel(m_wheels[3]);

    m_motor->ConnectToTransmission(m_transmission);

    Injector* injector = new Injector();
    m_motor->AddInjector(injector);

    m_cockpit->GetAcceleratorPedal()->SetTarget(injector);
    m_cockpit->GetBrakePedal()->SetTarget(m_brake_controller);

    DAE* dae = new DAE();
    dae->SetDirection(m_direction);
    m_electronics->SetDae(dae);
    m_cockpit->GetSteerWheel()->SetDae(dae);
}

Car::~Car()
{
    delete m_cockpit;
    delete m_electronics;
    delete m_motor;
    delete m_transmission;
    delete m_direction;
    delete m_brake_controller;
    for (std::size_t i = 0; i < m_wheels.size(); ++i)
    {
        delete m_wheels[i];
    }
}

void Car::Drive()
{
    std::cout << "=== Car driving scenario ===" << std::endl;

    m_cockpit->ChangeGear();
    m_cockpit->ChangeGear();

    m_cockpit->Accelerate(3.5f);

    m_cockpit->TurnSteerWheel(15.0f);

    m_cockpit->Brake(2.0f);
}

BrakeController* Car::GetBrakeController() const
{
    return m_brake_controller;
}

Direction* Car::GetDirection() const
{
    return m_direction;
}

Transmission* Car::GetTransmission() const
{
    return m_transmission;
}

Motor* Car::GetMotor() const
{
    return m_motor;
}

Electronics* Car::GetElectronics() const
{
    return m_electronics;
}

Cockpit* Car::GetCockpit() const
{
    return m_cockpit;
}
