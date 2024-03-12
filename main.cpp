#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("company"); // Ret til det schema navn du har valgt
    db.setUserName("sammy");
    // Ret brugernavn
    db.setPassword("password");
    // Ret password
    db.open();
    QSqlQuery query;
    query.exec("SELECT * FROM employee"); // employee er her navnet på en tabel, ikke et schema
    while (query.next()) {
        QString fname  = query.value(0).toString();
        QString lname = query.value(1).toString();
        int ssn = query.value(2).toInt();
        qDebug() << "Fname:" << fname << "Lname:" << lname << "SSN:" << ssn;
        }
    qDebug() << "Finished";
    return 1;
}


