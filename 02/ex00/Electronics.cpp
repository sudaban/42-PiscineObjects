#include "Electronics.hpp"


Electronics::Electronics() : m_dae(0)
{
}

DAE* Electronics::GetDae()
{
    return m_dae;
}

void Electronics::SetDae(DAE* p_dae)
{
    m_dae = p_dae;
}
