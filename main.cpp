//
// Created by Maxim Pedchenko on 07.03.16.
//
#include "server/server.h"

int main(int argc, char *argv[]) {
    server_conf *conf = new server_conf(argc, argv);
    server server(conf);

    server.start();

    delete conf;

    return 0;
}
