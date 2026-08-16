#ifndef SPEEDOMETER_HPP
# define SPEEDOMETER_HPP

class Speedometer
{
public:
	enum
	{
		MAX_SPEED = 300
	};

	Speedometer();

	void Accelerate(int amount);
	void Decelerate(int amount);
	void Reset();
	int GetSpeed() const;

private:
	int m_speed;
};

Speedometer::Speedometer() : m_speed(0) {}

void Speedometer::Accelerate(int amount)
{
	if (amount < 0)
		amount = 0;
	m_speed += amount;
	if (m_speed > MAX_SPEED)
		m_speed = MAX_SPEED;
}

void Speedometer::Decelerate(int amount)
{
	if (amount < 0)
		amount = 0;
	m_speed -= amount;
	if (m_speed < 0)
		m_speed = 0;
}

void Speedometer::Reset()
{
	m_speed = 0;
}

int Speedometer::GetSpeed() const
{
	return m_speed;
}

#endif
