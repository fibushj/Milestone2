//
// Created by Jonathan on 13/01/2019.
//

#include "MyTestClientHandler.h"

string MyTestClientHandler::handleClient(string input) {
    //TODO: mutex
    if (cm->doesSolutionExist(input)){
        return cm->getSolution(input);
    }

}



