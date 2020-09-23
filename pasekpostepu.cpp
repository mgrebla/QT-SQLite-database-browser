#include "pasekpostepu.h"
#include "ui_pasekpostepu.h"
#include "mythread.h"

PasekPostepu::PasekPostepu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasekPostepu)
{
    ui->setupUi(this); 

    MyThread* thr = new MyThread(this);

    connect(thr, SIGNAL(progress(int)), this, SLOT(updateProgress(int)), Qt::QueuedConnection);
    connect(thr, SIGNAL(finished()), thr, SLOT(deleteLater()));
    connect(ui->pbPrzerwij, SIGNAL(clicked()), thr, SLOT(quit()));

    thr->start();
}

PasekPostepu::~PasekPostepu()
{
    delete ui;
}

void PasekPostepu::updateProgress(int prog)
{
    ui->progBar->setValue(prog);
}
void PasekPostepu::on_pbPrzerwij_clicked()
{

}
