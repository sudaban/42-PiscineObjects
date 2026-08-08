#ifndef EXPLOSION_CHAMBER_HPP
#define EXPLOSION_CHAMBER_HPP


class Crankshaft;

class ExplosionChamber
{
private:
    Crankshaft* m_crankshaft;

public:
    ExplosionChamber();
    void Fill(float p_volume);
    void SetCrankshaft(Crankshaft* p_crankshaft);
};


#endif
