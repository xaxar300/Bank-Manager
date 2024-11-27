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
        // ������������� ��������� ������������
        QVBoxLayout* layout = new QVBoxLayout(this);
        QPushButton* button = new QPushButton("Change Color", this);

        // ���������� ������ ������� ������ � ����� ��� ��������� �����
        connect(button, &QPushButton::clicked, this, &ColorChangingApp::changeBackgroundColor);

        layout->addWidget(button);
        setLayout(layout);

        // ��������� ��������� �����
        srand(static_cast<unsigned>(time(nullptr)));
    }

private slots:
    void changeBackgroundColor() {
        // ��������� ���������� �����
        QColor color(rand() % 256, rand() % 256, rand() % 256);

        // ���������� ����� � ����
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

#include "main.moc"
