#ifndef PASEKPOSTEPU_H
#define PASEKPOSTEPU_H

#include <QDialog>

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

private:
    Ui::PasekPostepu *ui;
};

#endif // PASEKPOSTEPU_H
