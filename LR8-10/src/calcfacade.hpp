#ifndef CALCFACADE_HPP
#define CALCFACADE_HPP

#include "calcfactorycottage.hpp"
#include "calcfactoryeconom.hpp"
#include "calcfactorylux.hpp"
#include "calcfactorytownhouse.hpp"
#include "estate.hpp"

class CalcFacade {
private:
    static CalcFactoryCottage m_cottageFactory;
    static CalcFactoryEconom m_economFactory;
    static CalcFactoryLux m_luxFactory;
    static CalcFactoryTownHouse m_townHouseFactory;

public:
    static int getCost(Estate* value);
};

#endif // CALCFACADE_HPP
