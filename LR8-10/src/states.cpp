#include "states.hpp"

States::States(QObject* parent)
    : QObject(parent)
    , actualData(nullptr)
{
}

States::~States()
{
    if (actualData) {
        array.removeAll(actualData);
        delete actualData;
        actualData = nullptr;
    }

    qDeleteAll(array);
    array.clear();
}

void States::undo()
{
    if (hasStates()) {
        actualData = array.takeFirst();
    } else {
        actualData = nullptr;
    }
}

bool States::hasStates() const
{
    return !array.empty();
}

Estate* States::getActualData() const
{
    return actualData;
}

void States::add(Estate* state)
{
    if (!state)
        return;
    array.push_front(state);
}
