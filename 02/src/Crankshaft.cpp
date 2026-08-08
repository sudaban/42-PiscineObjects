#include "Crankshaft.hpp"

#include "Transmission.hpp"

#include <iostream>


Crankshaft::Crankshaft() : m_transmission(0)
{
}

void Crankshaft::ReceiveForce(float p_volume)
{
    std::cout << "[Crankshaft] receive force volume=" << p_volume << std::endl;
    if (m_transmission != 0)
    {
        m_transmission->Activate(p_volume);
    }
}

void Crankshaft::SetTransmission(Transmission* p_transmission)
{
    m_transmission = p_transmission;
}
