#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TableManager tm;

    tm.DatabaseConnect();
    tm.DatabaseInit();

    DisplayDatabase();
}

void MainWindow::DisplayDatabase()
{
    QScopedPointer<QSqlQueryModel> model(new QSqlQueryModel());
    QSqlQuery query;

    query.exec("SELECT * FROM auta");

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));

    ui->tableView->setModel(model.take());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->show();
}

void MainWindow::on_pbDodaj_clicked()
{
    dodajdobazy ddb;
    ddb.setModal(true);

    connect(&ddb, SIGNAL(comingBackToMainWindow()),this,SLOT(refreshAfterChange()));

    ddb.exec();
}

void MainWindow::on_pbEdytuj_clicked(){
    QModelIndexList selIndex = ui->tableView->selectionModel()->selectedIndexes();
    QMessageBox msgBox;
    TableManager tm;

    if (selIndex.isEmpty()) {
        msgBox.setText("Wybierz wiersz do edycji");
        msgBox.exec();
    } else {
        int toUpdate = ui->tableView->model()->data(ui->tableView->model()->index(selIndex.begin()->row(),0)).toInt();
        EdytujWBazie::toEditRow = toUpdate;
        EdytujWBazie ewb;
        ewb.setModal(true);

        connect(&ewb, SIGNAL(comingBackToMainWindow()), this, SLOT(refreshAfterChange()));

        ewb.exec();
    }
}

void MainWindow::on_pbUsun_clicked(){
    QModelIndexList selIndex = ui->tableView->selectionModel()->selectedIndexes();
    TableManager tm;
    QMessageBox msgBox;

    if (selIndex.isEmpty()) {
        msgBox.setText("Wybierz wiersz do usuniecia");
        msgBox.exec();
    } else {
        int toDelete = ui->tableView->model()->data(ui->tableView->model()->index(selIndex.begin()->row(),0)).toInt();
        tm.DeleteEntry(toDelete);
        DisplayDatabase();
    }
}

void MainWindow::on_pbProgressBar_clicked(){
    PasekPostepu pp;

    pp.setModal(true);
    pp.exec();
}

void MainWindow::refreshAfterChange()
{
    DisplayDatabase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

