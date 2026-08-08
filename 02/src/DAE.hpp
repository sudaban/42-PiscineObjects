#ifndef DAE_HPP
#define DAE_HPP


class Direction;

class DAE
{
private:
    Direction* m_direction;
    float m_force;

public:
    DAE();
    void Use(float p_angle);
    void SetDirection(Direction* p_direction);
    float GetForce() const;
    void SetForce(float p_force);
};


#endif
