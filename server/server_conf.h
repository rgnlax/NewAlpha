//
// Created by Maxim Pedchenko on 17.03.16.
//

#ifndef NEW_ALPHA_SERVER_CONF_H
#define NEW_ALPHA_SERVER_CONF_H

#include <stdlib.h>
#include <libconfig.h++>
#include <iostream>


class server_conf {
public:
    server_conf();

    server_conf(int argc, char *argv[]);

    int getPort() const;

    int getWorkers() const;

    const char *getRootDir() const;

private:
    int mPort;
    int mWorkers;
    const char *mRootDir;

    void parseConf(const char *conf_path);

    void parseArgs(int argc, char *argv[]);
};

#endif //NEW_ALPHA_SERVER_CONF_H
