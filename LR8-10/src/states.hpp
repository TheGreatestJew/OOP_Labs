#ifndef STATES_HPP
#define STATES_HPP

#include "estate.hpp"
#include <QList>
#include <QObject>

class States : public QObject {
    Q_OBJECT
private:
    QList<Estate*> array;
    Estate* actualData;

public:
    explicit States(QObject* parent = nullptr);
    ~States();

    void undo();
    bool hasStates() const;
    Estate* getActualData() const;
    void add(Estate* state);

signals:
    void notifyObservers();
};

#endif // STATES_HPP
