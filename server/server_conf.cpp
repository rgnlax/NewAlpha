//
// Created by Maxim Pedchenko on 17.03.16.
//

#include "server_conf.h"

server_conf::server_conf() {

}

server_conf::server_conf(int argc, char **argv) {
    this->parseConf("conf.txt");
    this->parseArgs(argc, argv);
}

void server_conf::parseConf(const char *conf_path) {
    libconfig::Config cfg;

    try {
        cfg.readFile(conf_path);
    }
    catch (const libconfig::FileIOException &fioex) {
        perror("Unable to find configuration file");
        exit(EXIT_FAILURE);
    }
    catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
        << " - " << pex.getError() << std::endl;
        exit(EXIT_FAILURE);
    }

    try {
        mPort = cfg.lookup("port");
        mWorkers = cfg.lookup("workers");
        mRootDir = cfg.lookup("root_dir");
    } catch (const libconfig::SettingNotFoundException &nfex) {
        perror("Can't find appropriate var in conf file");
        exit(EXIT_FAILURE);
    }
}

void server_conf::parseArgs(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "c:h:p:r:")) != -1) {
        switch (opt) {
            case 'c':
                mWorkers = atoi(optarg);
                break;
            case 'p':
                mPort = atoi(optarg);
                break;
            case 'r':
                if (!chdir(optarg))
                    break;
                perror("Unable to set root directory");
            default:
                fprintf(stderr, "Usage: %s [-c NCPU] [-p PORT] [-r ROOTDIR]\n", argv[0]);
        }
    }
}

int server_conf::getPort() const {
    return this->mPort;
}

int server_conf::getWorkers() const {
    return this->mWorkers;
}

const char *server_conf::getRootDir() const {
    return mRootDir;
}
