//
// Created by Jonathan on 13/01/2019.
//

#include "MyClientHandler.h"

string MyClientHandler::handleClient(int socket) {
    //TODO: mutex

    if (cm->doesSolutionExist(input)){
        return cm->getSolution(input);
    }

    close(socket);
}



