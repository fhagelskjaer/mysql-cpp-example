#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("company"); // Ret til det schema navn du har valgt
    db.setUserName("sammy");  // Ret brugernavn
    db.setPassword("password");  // Ret password
    db.open();
       
    QSqlQuery query;
    query.prepare("INSERT INTO employee "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
        
    query.addBindValue(argv[1]);
    query.addBindValue(argv[2]);
    query.addBindValue(std::stoi(argv[3]));
    query.addBindValue(argv[4]);
    query.addBindValue(argv[5]);
    query.addBindValue(argv[6]);
    query.addBindValue(std::stoi(argv[7]));
    query.addBindValue(std::stoi(argv[8]));
    query.addBindValue(std::stoi(argv[9]));
    
    qDebug() << query.exec();
    
}
