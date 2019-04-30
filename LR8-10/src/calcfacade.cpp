#include "calcfacade.hpp"
#include "cottagecalc.hpp"
#include "economcalc.hpp"
#include "luxcalc.hpp"
#include "townhousecalc.hpp"

int CalcFacade::getCost(Estate* value)
{
    auto type = value->getType();

    switch (type) {
    case Estate::ECONOM:
        return EconomCalc::getCost(value);
    case Estate::LUXURIOUS:
        return LuxCalc::getCost(value);
    case Estate::TOWN_HOUSE:
        return TownHouseCalc::getCost(value);
    case Estate::COTTAGE:
        return CottageCalc::getCost(value);
    }
    return -1;
}
