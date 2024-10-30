#include "Utilities.h"
#include "Government.h"
#include "Wood.h"
#include "Steel.h"
#include "Concrete.h"


class MaterialFactory : public Utilities {
    public:
        void handleRequest(Government* govern) override {
            StateOfResources* FullState = new FullState();
            Wood* wood = new Wood(FullState, 100);
            Steel* steel = new Steel(FullState, 100);
            Concrete* concrete = new Concrete(FullState, 100);

            std::cout << "MaterialFactory: Created a Wood object with quantity: " << wood->getQuantity() << std::endl;
            std::cout << "MaterialFactory: Created a Steel object with quantity: " << steel->getQuantity() << std::endl;
            std::cout << "MaterialFactory: Created a Concrete object with quantity: " << concrete->getQuantity() << std::endl;

            delete wood;
            delete steel;
            delete concrete;
            delete normalState;

            Utilities::handleRequest(govern);
        }
};