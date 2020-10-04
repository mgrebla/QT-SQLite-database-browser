#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include "mythread.h"

namespace Ui {
class PasekPostepu;
}

class PasekPostepu : public QDialog
{
    Q_OBJECT

public:
    explicit PasekPostepu(QWidget *parent = nullptr);
    ~PasekPostepu();

public slots:
    void updateProgress(int prog);
    void on_pbPrzerwij_clicked();

protected:
    void closeEvent(QCloseEvent *e) override;

private:
    Ui::PasekPostepu *ui;

};
