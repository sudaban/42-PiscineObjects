#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "Crankshaft.hpp"
#include "ExplosionChamber.hpp"
#include "Injector.hpp"

#include <vector>


class Transmission;

class Motor
{
private:
    std::vector<Injector*> m_injectors;
    ExplosionChamber* m_chamber;
    Crankshaft* m_crankshaft;

public:
    Motor();
    ~Motor();
    void ConnectToTransmission(Transmission* p_transmission);
    void AddInjector(Injector* p_injector);
    ExplosionChamber* GetChamber();
    Crankshaft* GetCrankshaft();
};


#endif
