#include <QCoreApplication>
#include <unistd.h>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QObject>
#include "incomingconnection.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "PID: " << getpid();//debugtool: PID:
    QTcpServer server;
    IncomingConnection conn(&server);
    QObject::connect(&server, &QTcpServer::newConnection, &conn, &IncomingConnection::newConnection);
    server.listen(QHostAddress::LocalHost, 3500);
    for (int i=0; i < 3; i++) { //fork 2^3 times (there is 8 process)
        fork();
    }
    qDebug() << "PID: " << getpid();//debugtool: PID:
    return a.exec();
}
