#ifndef FORM_HPP
#define FORM_HPP

#include "states.hpp"
#include "ui_form.h"
#include <QWidget>

class Form : public QWidget {
    Q_OBJECT

private:
    Ui::Form* m_ui;
    States info;

public:
    explicit Form(QWidget* parnet = nullptr);
    Form(const Form&) = delete;
    ~Form();

public slots:
    void update();
private slots:
    void btnCalcPressed();
    void btnUndoPressed();

private:
    Estate* processForm() const;
    void fillForm(Estate* state);

    void showCost(Estate* state);
};

#endif // FORM_HPP
