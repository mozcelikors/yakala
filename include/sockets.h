#ifndef SOCKETS_H
#define SOCKETS_H

#include <QStringList>

class Sockets
{
private:
	QStringList protos;
	QStringList recvQs;
	QStringList sendQs;
	QStringList localAddrs;
	QStringList foreignAddrs;
	QStringList states;
public:
	Sockets();
	void readSocketList (void);
	QStringList getProtos (void);
	QStringList getRecvQs (void);
	QStringList getSendQs(void);
	QStringList getLocalAddrs (void);
	QStringList getForeignAddrs (void);
	QStringList getStates (void);
};

#endif // SOCKETS_H
