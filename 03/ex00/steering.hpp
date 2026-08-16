#ifndef STEERING_HPP
# define STEERING_HPP

class Steering
{
public:
	enum
	{
		MAX_ANGLE = 45
	};

	Steering();

	void Turn(int angle);
	void Straighten();
	int GetAngle() const;
	bool IsStraight() const;

private:
	int m_angle;
};

Steering::Steering() : m_angle(0) {}

void Steering::Turn(int angle)
{
	m_angle += angle;
	if (m_angle > MAX_ANGLE)
		m_angle = MAX_ANGLE;
	if (m_angle < -MAX_ANGLE)
		m_angle = -MAX_ANGLE;
}

void Steering::Straighten()
{
	m_angle = 0;
}

int Steering::GetAngle() const
{
	return m_angle;
}

bool Steering::IsStraight() const
{
	return m_angle == 0;
}

#endif
