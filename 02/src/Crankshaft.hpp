#ifndef CRANKSHAFT_HPP
#define CRANKSHAFT_HPP


class Transmission;

class Crankshaft
{
private:
    Transmission* m_transmission;

public:
    Crankshaft();
    void ReceiveForce(float p_volume);
    void SetTransmission(Transmission* p_transmission);
};


#endif
