#ifndef GEAR_HPP
#define GEAR_HPP


class Gear
{
private:
    int m_demultiplier;

public:
    Gear();
    Gear(int p_demultiplier);
    int GetDemultiplier() const;
    void SetDemultiplier(int p_demultiplier);
};


#endif
