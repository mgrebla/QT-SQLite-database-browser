#pragma once

#include <QMainWindow>

#include <QDir>

#include <QDebug>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

class TableManager
{
public:
    TableManager();

    void DatabaseConnect();
    void DatabaseInit();
    void DisplayDatabase();
    void DeleteEntry(int rowNo);
    void UpdateEntry(int rowNo, QString marka, QString model, QString nrRej, QString vin);
    void AddEntry(QString marka, QString model, QString nrRej, QString vin);
    QString FindEntry(int id, QString var);
};
