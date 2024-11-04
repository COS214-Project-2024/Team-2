#ifndef Materials_H
#define Materials_H

#include "Resources.h"

/**
 * @class Materials
 * @brief Abstract base class for all materials that can be used as resources.
 * 
 * This class defines the interface for materials, requiring derived classes to
 * implement methods for using and generating resources.
 */
class Materials : public Resources {
    public:
        /**
         * @brief Uses a specified quantity of the material.
         * 
         * Derived classes must implement this method to define how the material is used.
         * 
         * @param quantity The amount of material to use.
         */
        virtual void useResource(int quantity) = 0;

        /**
         * @brief Generates a specified quantity of the material.
         * 
         * Derived classes must implement this method to define how the material is generated.
         * 
         * @param quantity The amount of material to generate.
         */
        virtual void generateResource(int quantity) = 0;
};

#endif
