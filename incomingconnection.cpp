#include "incomingconnection.h"
#include <QTcpSocket>
#include <unistd.h>
#include <QByteArray>
#include <QDebug>
IncomingConnection::IncomingConnection(QTcpServer *server, QObject *parent)
    : QObject(parent)
    , _server(server)
{
    qDebug() << getpid() <<Q_FUNC_INFO << server;//debugtool:
}

IncomingConnection::~IncomingConnection()
{

}

void IncomingConnection::newConnection()
{
    qDebug() << getpid() <<"new_connection";//debugtool: new_connection
    QTcpSocket *socket = _server->nextPendingConnection();
    QByteArray data = socket->readAll();
    qDebug() << "PID: " << getpid() << data;//debugtool: PID:

}

