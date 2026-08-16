#ifndef CAR_HPP
# define CAR_HPP

# include "engine.hpp"
# include "gearbox.hpp"
# include "brakeSystem.hpp"
# include "steering.hpp"
# include "speedometer.hpp"

class Car
{
public:
	void start();
	void stop();
	void accelerate(int speed);
	void shift_gears_up();
	void shift_gears_down();
	void reverse();
	void turn_wheel(int angle);
	void straighten_wheels();
	void apply_force_on_brakes(int force);
	void apply_emergency_brakes();

	bool IsEngineRunning() const;
	int GetCurrentGear() const;
	bool IsInReverse() const;
	int GetSpeed() const;
	int GetWheelAngle() const;
	int GetBrakeForce() const;

private:
	Engine m_engine;
	Gearbox m_gearbox;
	BrakeSystem m_brakes;
	Steering m_steering;
	Speedometer m_speedometer;
};

void Car::start()
{
	m_engine.Start();
}

void Car::stop()
{
	m_engine.Stop();
	m_speedometer.Decelerate(m_brakes.ApplyEmergency());
}

void Car::accelerate(int speed)
{
	if (m_engine.IsRunning())
		m_speedometer.Accelerate(speed);
}

void Car::shift_gears_up()
{
	if (m_engine.IsRunning())
		m_gearbox.ShiftUp();
}

void Car::shift_gears_down()
{
	if (m_engine.IsRunning())
		m_gearbox.ShiftDown();
}

void Car::reverse()
{
	if (m_engine.IsRunning() && m_speedometer.GetSpeed() == 0)
		m_gearbox.EngageReverse();
}

void Car::turn_wheel(int angle)
{
	m_steering.Turn(angle);
}

void Car::straighten_wheels()
{
	m_steering.Straighten();
}

void Car::apply_force_on_brakes(int force)
{
	m_speedometer.Decelerate(m_brakes.ApplyForce(force));
}

void Car::apply_emergency_brakes()
{
	m_speedometer.Decelerate(m_brakes.ApplyEmergency());
}

bool Car::IsEngineRunning() const
{
	return m_engine.IsRunning();
}

int Car::GetCurrentGear() const
{
	return m_gearbox.GetCurrentGear();
}

bool Car::IsInReverse() const
{
	return m_gearbox.IsInReverse();
}

int Car::GetSpeed() const
{
	return m_speedometer.GetSpeed();
}

int Car::GetWheelAngle() const
{
	return m_steering.GetAngle();
}

int Car::GetBrakeForce() const
{
	return m_brakes.GetAppliedForce();
}

#endif
