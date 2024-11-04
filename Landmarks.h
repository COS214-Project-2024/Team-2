#ifndef Landmarks_h
#define Landmarks_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

/**
 * @brief Class representing landmarks in the city.
 * 
 * This class inherits from Buildings and provides methods to manage
 * different types of landmarks, including their prices and satisfaction
 * rates.
 */
class Landmarks : public Buildings
{
    private:
        string type[3] = {"parks", "monuments", "culturecenters"}; ///< Array of landmark types.
        int price[3] = {300, 500, 350}; ///< Array of prices corresponding to landmark types.
        int position; ///< The position index of the landmark type.
        int satisfactionRate = 2; ///< The satisfaction rate associated with landmarks.
        string myType = "landmarks"; ///< The type identifier for landmarks.
        bool taken = false; ///< Indicates if the landmark is taken.

    public:
        /**
         * @brief Constructor for the Landmarks class.
         * 
         * Initializes a Landmarks object with the specified type.
         * 
         * @param type The type of the landmark (parks, monuments, culturecenters).
         */
        Landmarks(string type);

        /**
         * @brief Retrieves the type of the landmark.
         * 
         * @return The type of the landmark as a string.
         */
        std::string getType();

        /**
         * @brief Retrieves the price of the landmark.
         * 
         * @return The price of the landmark as an integer.
         */
        int getPrice();

        /**
         * @brief Retrieves the position of the landmark in the type array.
         * 
         * @return The position of the landmark as an integer.
         */
        int getPosition();

        /**
         * @brief Retrieves the satisfaction rate of the landmark.
         * 
         * @return The satisfaction rate as an integer.
         */
        int getSatisfaction();

        /**
         * @brief Sets the price of the landmark.
         * 
         * @param p The new price for the landmark.
         */
        void setPrice(int p);

        /**
         * @brief Checks if the landmark is taken.
         * 
         * @return true if the landmark is taken, false otherwise.
         */
        bool getTaken();

        /**
         * @brief Sets the taken status of the landmark.
         * 
         * @param t The new taken status.
         */
        void setTaken(bool t);
};

#endif
