

class StateOfResources {
    public:
        virtual void useResource(int quantity) = 0;
        virtual void generateResource(int quantity) = 0;
};