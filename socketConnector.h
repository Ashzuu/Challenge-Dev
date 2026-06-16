#ifndef PROG_SOCKETCONNECTOR_H
#define PROG_SOCKETCONNECTOR_H
#include <string>

class SocketConnector {
public:
    static int customConnect(std::string host, int port);
};


#endif //PROG_SOCKETCONNECTOR_H
