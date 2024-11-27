#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KABAN.h"

class KABAN : public QMainWindow
{
    Q_OBJECT

public:
    KABAN(QWidget *parent = nullptr);
    ~KABAN();

private:
    Ui::KABANClass ui;
};
