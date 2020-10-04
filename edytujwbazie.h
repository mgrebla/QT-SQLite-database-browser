#pragma once

#include "mainwindow.h"
#include "tablemanager.h"

#include <QDialog>

namespace Ui {
class EdytujWBazie;
}

class EdytujWBazie : public QDialog
{
    Q_OBJECT

public:
    explicit EdytujWBazie(QWidget *parent = nullptr);
    ~EdytujWBazie();

    static int toEditRow;

private slots:

    void on_pbEdytuj_clicked();
    void on_pbAnuluj_clicked();

signals:
    void comingBackToMainWindow();

private:
    Ui::EdytujWBazie *ui;

    void setLabels();
};
