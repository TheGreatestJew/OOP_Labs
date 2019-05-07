#include "calcfacade.hpp"

CalcFactoryLux CalcFacade::m_luxFactory = CalcFactoryLux();
CalcFactoryEconom CalcFacade::m_economFactory = CalcFactoryEconom();
CalcFactoryCottage CalcFacade::m_cottageFactory = CalcFactoryCottage();
CalcFactoryTownHouse CalcFacade::m_townHouseFactory = CalcFactoryTownHouse();

int CalcFacade::getCost(Estate* value)
{
    auto type = value->getType();

    bstractCalc* calc = nullptr;

    switch (type) {
    case Estate::ECONOM:
        calc = CalcFacade::m_economFactory.FactoryMethod(value);
        break;
    case Estate::LUXURIOUS:
        calc = CalcFacade::m_luxFactory.FactoryMethod(value);
        break;
    case Estate::TOWN_HOUSE:
        calc = CalcFacade::m_townHouseFactory.FactoryMethod(value);
        break;
    case Estate::COTTAGE:
        calc = CalcFacade::m_cottageFactory.FactoryMethod(value);
        break;
    }

    if (calc) {
        auto cost = calc->getCost();
        delete calc;
        return cost;
    }
    return -1;
}
