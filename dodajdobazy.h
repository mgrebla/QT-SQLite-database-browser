#pragma once

#include "mainwindow.h"
#include "tablemanager.h"

#include <QDialog>

#include <QDebug>

namespace Ui {
class dodajdobazy;
}

class dodajdobazy : public QDialog
{
    Q_OBJECT

public:
    explicit dodajdobazy(QWidget *parent = nullptr);
    ~dodajdobazy();

private slots:

    void on_pbSecDodaj_clicked();
    void on_pbAnuluj_clicked();

signals:
    void comingBackToMainWindow();

private:
    Ui::dodajdobazy *ui;

};
