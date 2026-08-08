#ifndef BRAKE_HPP
#define BRAKE_HPP


class Wheel;

class Brake
{
private:
    Wheel* m_wheel;

public:
    Brake();
    void Execute(float p_force);
    void AttackWheel(Wheel* p_wheel);
    Wheel* GetWheel() const;
};


#endif
