#ifndef BRAKESYSTEM_HPP
# define BRAKESYSTEM_HPP

class BrakeSystem
{
public:
	enum
	{
		MAX_FORCE = 200
	};

	BrakeSystem();

	int ApplyForce(int force);
	int ApplyEmergency();
	void Release();
	int GetAppliedForce() const;

private:
	int m_applied_force;
};

BrakeSystem::BrakeSystem() : m_applied_force(0) {}

int BrakeSystem::ApplyForce(int force)
{
	if (force < 0)
		force = 0;
	if (force > MAX_FORCE)
		force = MAX_FORCE;
	m_applied_force = force;
	return m_applied_force;
}

int BrakeSystem::ApplyEmergency()
{
	m_applied_force = MAX_FORCE;
	return m_applied_force;
}

void BrakeSystem::Release()
{
	m_applied_force = 0;
}

int BrakeSystem::GetAppliedForce() const
{
	return m_applied_force;
}

#endif
