//
// Created by Maxim Pedchenko on 17.03.16.
//

#ifndef NEW_ALPHA_SERVER_H
#define NEW_ALPHA_SERVER_H

#include "server_conf.h"

class server {
public:
    server(server_conf *conf);

    ~server();

    void start();

private:
    server_conf *conf;
};


#endif //NEW_ALPHA_SERVER_H
