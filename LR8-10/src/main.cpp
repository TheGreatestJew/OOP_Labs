#include "form.hpp"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char** argv)
{
    try {
        QApplication app(argc, argv);

        Form wnd;
        wnd.show();

        return app.exec();
    } catch (std::exception& e) {
        QMessageBox::critical(nullptr, "Критическая ошибка!", "Необработаное исключение: " + QString(e.what()));
    }
}
