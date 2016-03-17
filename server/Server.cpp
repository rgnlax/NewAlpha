//
// Created by Maxim Pedchenko on 17.03.16.
//

#include "server.h"

server::~server() {

}

server::server(server_conf *conf) {
    this->conf = conf;
}

void server::start() {
    std::cout << conf->getPort();
    std::cout << conf->getRootDir();
    std::cout << conf->getWorkers();
}
