#ifndef UTILITIES_H
#define UTILITIES_H
#include "../Government.h"

class Utilities {
protected:
    Utilities* nextHandler;

public:
    Utilities() : nextHandler(nullptr) {}
    virtual ~Utilities() {}

    void setNext(Utilities* next) {
        nextHandler = next;
    }

    virtual void handleRequest(Government* govern) {
        if (nextHandler) {
            nextHandler->handleRequest(govern);
        }
    }
};

#endif