#include "KABAN.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPalette>
#include <QColor>
#include <ctime>

class ColorChangingApp : public QWidget {
    Q_OBJECT

public:
    ColorChangingApp(QWidget* parent = nullptr) : QWidget(parent) {
        // Óñòàíàâëèâàåì íà÷àëüíóþ êîíôèãóðàöèþ
        QVBoxLayout* layout = new QVBoxLayout(this);
        QPushButton* button = new QPushButton("Change Color", this);

        // Ïîäêëþ÷àåì ñèãíàë íàæàòèÿ êíîïêè ê ñëîòó äëÿ èçìåíåíèÿ öâåòà
        connect(button, &QPushButton::clicked, this, &ColorChangingApp::changeBackgroundColor);

        layout->addWidget(button);
        setLayout(layout);

        // Ãåíåðàòîð ñëó÷àéíûõ ÷èñåë
        srand(static_cast<unsigned>(time(nullptr)));
    }

private slots:
    void changeBackgroundColor() {
        // Ãåíåðàöèÿ ñëó÷àéíîãî öâåòà
        QColor color(rand() % 256, rand() % 256, rand() % 256);

        // Ïðèìåíåíèå öâåòà ê ôîíó
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, color);
        this->setPalette(palette);
        this->update();
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ColorChangingApp window;
    window.setWindowTitle("Color Changing App");
    window.resize(400, 300);
    window.show();

    return app.exec();
}

return (0); //маму не ебал



#include "main.moc"
