#ifndef GEARBOX_HPP
# define GEARBOX_HPP

class Gearbox
{
public:
	enum
	{
		REVERSE_GEAR = -1,
		NEUTRAL_GEAR = 0,
		MAX_GEAR = 5
	};

	Gearbox();

	bool ShiftUp();
	bool ShiftDown();
	bool EngageReverse();
	bool IsInReverse() const;
	int GetCurrentGear() const;

private:
	int m_current_gear;
};

Gearbox::Gearbox() : m_current_gear(NEUTRAL_GEAR) {}

bool Gearbox::ShiftUp()
{
	if (m_current_gear >= MAX_GEAR)
		return false;
	m_current_gear++;
	return true;
}

bool Gearbox::ShiftDown()
{
	if (m_current_gear <= NEUTRAL_GEAR)
		return false;
	m_current_gear--;
	return true;
}

bool Gearbox::EngageReverse()
{
	if (m_current_gear > NEUTRAL_GEAR)
		return false;
	m_current_gear = REVERSE_GEAR;
	return true;
}

bool Gearbox::IsInReverse() const
{
	return m_current_gear == REVERSE_GEAR;
}

int Gearbox::GetCurrentGear() const
{
	return m_current_gear;
}

#endif
