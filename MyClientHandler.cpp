
#include "MyClientHandler.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <strings.h>
#include <string.h>
#include <iostream>
#define BUFFER_SIZE 4096

void MyClientHandler::handleClient(int socket) {
    //TODO: mutex
    string input;
    char buffer[BUFFER_SIZE];
    bool endEncountered = false;
    while (!endEncountered) {
        bzero((char *) &buffer, sizeof(buffer));
        int n = recv(socket, &buffer, sizeof(buffer), 0);
        string currMessage=buffer;
        if (currMessage.find("end")!=string::npos) {
            endEncountered = true;
        }
        input += currMessage;

    }
    string solution;
    if (cm->doesSolutionExist(input)) {
        solution = cm->getSolution(input);
    } else {
        solution = solver->solve(input);
    }
    cm->saveSolution(input, solution);
    solution+='\n';
    const char *message=solution.c_str();
    int n=write(socket, message, strlen(message));
    close(socket);

}



