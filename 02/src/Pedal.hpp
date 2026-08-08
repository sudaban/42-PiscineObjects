#ifndef PEDAL_HPP
#define PEDAL_HPP


class LinkablePart;

class Pedal
{
private:
    LinkablePart* m_target;

public:
    Pedal();
    void SetTarget(LinkablePart* p_part);
    void Use(float p_pression);
};


#endif
