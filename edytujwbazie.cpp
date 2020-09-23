#include "edytujwbazie.h"
#include "ui_edytujwbazie.h"

int EdytujWBazie::toEditRow = 0;

EdytujWBazie::EdytujWBazie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EdytujWBazie)
{
    ui->setupUi(this);

    setLabels();
}

void EdytujWBazie::on_pbEdytuj_clicked()
{
    TableManager tm;

    QString marka = ui->teMarka->toPlainText();
    QString model = ui->teModel->toPlainText();
    QString nrRej = ui->teNrRej->toPlainText();
    QString vin = ui->teVin->toPlainText();

    tm.UpdateEntry(toEditRow,marka, model, nrRej, vin);

    emit comingBackToMainWindow();

    EdytujWBazie::close();
}

void EdytujWBazie::on_pbAnuluj_clicked()
{
    EdytujWBazie::close();
}

void EdytujWBazie::setLabels(){
    TableManager tm;

    ui->teMarka->setText(tm.FindEntry(toEditRow, "marka"));
    ui->teModel->setText(tm.FindEntry(toEditRow, "model"));
    ui->teNrRej->setText(tm.FindEntry(toEditRow, "nrRej"));
    ui->teVin->setText(tm.FindEntry(toEditRow, "vin"));

    qDebug() << toEditRow;
    qDebug() << tm.FindEntry(toEditRow, "marka");
    qDebug() << tm.FindEntry(toEditRow, "model");
    qDebug() << tm.FindEntry(toEditRow, "nrRej");
    qDebug() << tm.FindEntry(toEditRow, "vin");
}

EdytujWBazie::~EdytujWBazie()
{
    delete ui;
}
