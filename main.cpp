#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Currently set to localhost
    db.setDatabaseName("company"); // Change to desired schema
    db.setUserName("sammy"); // Change to username
    db.setPassword("password"); // Change to password
    db.open();
    QSqlQuery query;
    query.exec("SELECT * FROM employee");
    while (query.next()) {
        QString fname  = query.value(0).toString();
        QString lname = query.value(1).toString();
        int ssn = query.value(2).toInt();
        qDebug() << "Fname:" << fname << "Lname:" << lname << "SSN:" << ssn;
        }
    qDebug() << "Finished";
    return 1;
}


