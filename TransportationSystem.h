#ifndef TRANSPORTATIONSYSTEM_H
#define TRANSPORTATIONSYSTEM_H

class Bank;

class TransportationSystem{
    public:
        virtual void move(Bank bank) = 0;
}

#endif