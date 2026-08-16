#include <iostream>
#include "car.hpp"

void PrintCarState(const Car& car)
{
	std::cout << "engine:" << (car.IsEngineRunning() ? "on" : "off")
		<< " speed:" << car.GetSpeed()
		<< " gear:" << car.GetCurrentGear()
		<< " wheel:" << car.GetWheelAngle()
		<< " brakeForce:" << car.GetBrakeForce()
		<< std::endl;
}

int main()
{
	Car car;

	PrintCarState(car);
	car.accelerate(30);
	PrintCarState(car);
	car.start();
	car.shift_gears_up();
	car.accelerate(30);
	car.shift_gears_up();
	car.accelerate(30);
	PrintCarState(car);
	car.turn_wheel(30);
	PrintCarState(car);
	car.turn_wheel(30);
	PrintCarState(car);
	car.straighten_wheels();
	PrintCarState(car);
	car.apply_force_on_brakes(50);
	PrintCarState(car);
	car.shift_gears_down();
	car.shift_gears_down();
	car.reverse();
	PrintCarState(car);
	car.apply_emergency_brakes();
	car.reverse();
	PrintCarState(car);
	car.stop();
	PrintCarState(car);
	return 0;
}
