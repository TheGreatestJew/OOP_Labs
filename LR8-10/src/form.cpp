#include "form.hpp"
#include "calcfacade.hpp"
#include <QMessageBox>
#include <cfloat>
#include <climits>

Form::Form(QWidget* parnet)
    : QWidget(parnet)
    , m_ui(nullptr)
{
    m_ui = new Ui::Form();
    m_ui->setupUi(this);

    m_ui->age->setValidator(new QIntValidator(0, INT_MAX, this));
    m_ui->residents->setValidator(new QIntValidator(0, INT_MAX, this));
    m_ui->area->setValidator(new QDoubleValidator(0, DBL_MAX, 2, this));

    connect(&info, &States::notifyObservers, this, &Form::update);
    connect(m_ui->btnCalc, &QPushButton::clicked, this, &Form::btnCalcPressed);
    connect(m_ui->btnUndo, &QPushButton::clicked, this, &Form::btnUndoPressed);
}

Form::~Form()
{
    delete m_ui;
}

void Form::update()
{
    auto value = info.getActualData();
    if (value != nullptr) {
        fillForm(value);
        showCost(value);
    } else {
        // resetFields();
    }
}

void Form::btnCalcPressed()
{
    auto state = processForm();
    info.add(state);
}

void Form::btnUndoPressed()
{
    if (!info.hasStates()) {
        QMessageBox::warning(this, "Ошибка", "Больше нет состояний.");
        return;
    }
    info.undo();
}

Estate* Form::processForm() const
{
    auto owner = m_ui->owner->text();
    auto age = m_ui->age->text().toInt();
    auto classOfHome = static_cast<Estate::EstateType>(m_ui->estateType->currentIndex());
    auto res = m_ui->residents->text().toInt();
    auto area = m_ui->area->text().toDouble();
    auto months = (1 + m_ui->period->currentIndex()) * 6;

    return new Estate(age, area, res, months, classOfHome, owner);
}

void Form::fillForm(Estate* state)
{
    if (!state) {
        return;
    }

    auto owner = state->getOwner();
    m_ui->owner->setText(owner);

    auto age = QString("%1").arg(state->getAge());
    m_ui->age->setText(age);

    auto classOfHomeCode = static_cast<int>(state->getType());
    m_ui->estateType->setCurrentIndex(classOfHomeCode);

    auto res = QString("%1").arg(state->getResidents());
    m_ui->residents->setText(res);

    auto area = QString("%1").arg(state->getArea());
    m_ui->area->setText(area);

    auto months = state->getMonths() / 6 - 1;
    m_ui->period->setCurrentIndex(months);

    showCost(state);
}

void Form::showCost(Estate* state)
{
    auto cost = CalcFacade::getCost(state);
    m_ui->cost->setText(QString("%1").arg(cost));
}
