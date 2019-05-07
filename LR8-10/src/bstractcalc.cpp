#include "bstractcalc.hpp"
#include <stdexcept>

bstractCalc::bstractCalc(Estate* state)
    : m_state(state)
{
    if (!m_state) {
        throw std::runtime_error("state is null");
    }
}
