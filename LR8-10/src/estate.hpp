#ifndef ESTATE_HPP
#define ESTATE_HPP

#include <QObject>
#include <QString>

class Estate : public QObject {
    Q_OBJECT
public:
    enum EstateType {
        ECONOM,
        LUXURIOUS,
        TOWN_HOUSE,
        COTTAGE
    };

private:
    int age;
    double area;
    int residents;
    int months;
    EstateType type;
    QString owner;

public:
    Estate(QObject* parent = nullptr);
    Estate(int age, double area, int residents, int months, EstateType type, QString owner, QObject* parent = nullptr);
    Estate(const Estate&) = default;

    int getAge() const;
    double getArea() const;
    int getResidents() const;
    int getMonths() const;
    EstateType getType() const;
    QString getOwner() const;
};

#endif // ESTATE_HPP
