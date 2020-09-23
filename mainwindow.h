#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dodajdobazy.h"
#include "edytujwbazie.h"
#include "pasekpostepu.h"
#include "tablemanager.h"
#include "mythread.h"

#include <QMainWindow>

#include <QDebug>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void DisplayDatabase();

    ~MainWindow();

public slots:
    void refreshAfterChange();

private slots:

    void on_pbDodaj_clicked();
    void on_pbEdytuj_clicked();
    void on_pbUsun_clicked();
    void on_pbProgressBar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
