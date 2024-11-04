#ifndef TRANSPORTATIONSYSTEM_H
#define TRANSPORTATIONSYSTEM_H

class Bank;

/**
 * @brief Abstract base class for transportation systems.
 * 
 * This class defines the interface for all transportation systems. 
 * Any class that derives from TransportationSystem must implement 
 * the move method, which facilitates the movement of a citizen 
 * using a specific transportation mode.
 */
class TransportationSystem {
    public:
        /**
         * @brief Moves a citizen using the transportation system.
         * 
         * This pure virtual function must be overridden in derived classes. 
         * It takes a pointer to a Bank object, which is used to check the 
         * financial status of the citizen before allowing them to use the 
         * transportation service.
         * 
         * @param bank A pointer to the Bank object representing the citizen's 
         *             financial state.
         */
        virtual void move(Bank* bank) = 0;
};

#endif
