#include "dodajdobazy.h"
#include "ui_dodajdobazy.h"

dodajdobazy::dodajdobazy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodajdobazy)
{
    ui->setupUi(this);
}

void dodajdobazy::on_pbSecDodaj_clicked()
{
    TableManager tm;

    QString marka = ui->teMarka->toPlainText();
    QString model = ui->teModel->toPlainText();
    QString nrRej = ui->teNrRej->toPlainText();
    QString vin = ui->teVin->toPlainText();

    tm.AddEntry(marka, model, nrRej, vin);

    emit comingBackToMainWindow();

    dodajdobazy::close();
}

void dodajdobazy::on_pbAnuluj_clicked()
{
    dodajdobazy::close();
}

dodajdobazy::~dodajdobazy()
{
    delete ui;
}
