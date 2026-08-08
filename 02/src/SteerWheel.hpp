#ifndef STEER_WHEEL_HPP
#define STEER_WHEEL_HPP


class DAE;

class SteerWheel
{
private:
    DAE* m_dae;

public:
    SteerWheel();
    void Turn(float p_angle);
    void SetDae(DAE* p_dae);
};


#endif
