#include "tablemanager.h"

TableManager::TableManager()
{

}

void TableManager::DatabaseConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(QDir::currentPath()+"mydb.db");

    if(!db.open()){
        qWarning() << "TableManager::DatabaseConnect - ERROR: " << db.lastError().text();
    } else {
        qDebug() << "Baza danych otwarta";
    }
}
void TableManager::DatabaseInit()
{
    QSqlQuery query("CREATE TABLE auta (id INTEGER PRIMARY KEY, marka TEXT, model TEXT, nrRej TEXT, vin TEXT)");

    if(!query.isActive())
        qWarning() << "TableManager::DatabaseInit - ERROR: " << query.lastError().text();
}

void TableManager::DeleteEntry(int rowNo)
{
    QSqlQuery query;

    if(!query.exec("DELETE FROM auta WHERE id = '" + QString::number(rowNo) + "'"))
        qWarning() << "TableManager::DeleteEntry - ERROR: " << query.lastError().text();

}

void TableManager::UpdateEntry(int rowNo, QString marka, QString model, QString nrRej, QString vin)
{
    QSqlQuery query;

    query.prepare("UPDATE auta set marka=?, model=?, nrRej=?, vin=? WHERE id = '" + QString::number(rowNo) + "'");
    query.addBindValue(marka);
    query.addBindValue(model);
    query.addBindValue(nrRej);
    query.addBindValue(vin);

    if(!query.exec())
        qWarning() << "TableManager::UpdateEntry - ERROR: " << query.lastError().text();

}

void TableManager::AddEntry(QString marka, QString model, QString nrRej, QString vin)
{
    QSqlQuery query;

    query.prepare("INSERT INTO auta(marka, model, nrRej, vin) VALUES(:marka, :model, :nrRej, :vin)");
    query.bindValue(":marka", marka);
    query.bindValue(":model", model);
    query.bindValue(":nrRej", nrRej);
    query.bindValue(":vin", vin);

    if(!query.exec())
        qWarning() << "TableManager::AddEntry - ERROR: " << query.lastError().text();

}

QString TableManager::FindEntry(int id, QString var)
{
    QSqlQuery query;

    if(!query.exec("SELECT " + var + " FROM auta WHERE id = '" + QString::number(id) + "'"))
        qWarning() << "TableManager::FindEntry - ERROR: " << query.lastError().text();

    query.next();

    return query.value(0).toString();
}

