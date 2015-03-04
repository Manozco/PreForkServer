#ifndef INCOMINGCONNECTION_H
#define INCOMINGCONNECTION_H

#include <QObject>
#include <QTcpServer>

class IncomingConnection : public QObject
{
    Q_OBJECT
public:
    explicit IncomingConnection(QTcpServer *server, QObject *parent = 0);
    ~IncomingConnection();

    QTcpServer *_server;

public slots:
    void newConnection();
};

#endif // INCOMINGCONNECTION_H
