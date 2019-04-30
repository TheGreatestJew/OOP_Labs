#ifndef FORM_HPP
#define FORM_HPP

#include "states.hpp"
#include "ui_form.h"
#include <QWidget>

class Form : public QWidget {
    Q_OBJECT

private:
    Ui::Form* m_ui;
    States states;

public:
    explicit Form(QWidget* parnet = nullptr);
    Form(const Form&) = delete;
    ~Form();

public slots:
    void btnCalcPressed();
    void btnUndoPressed();

private:
    void setState(Estate* state);
    void resetFields();

    void calcCost(Estate* state);
};

#endif // FORM_HPP
