#ifndef ELECTRONICS_HPP
#define ELECTRONICS_HPP

#include "DAE.hpp"


class Electronics
{
private:
    DAE* m_dae;

public:
    Electronics();
    DAE* GetDae();
    void SetDae(DAE* p_dae);
};


#endif
