class Resources {
    private:
        int maxCapacity;
    public:
        virtual void useResource(int quantity) = 0;
        virtual void generateResource(int quantity) = 0;
        virtual int getQuantity() const = 0;
        virtual int getMaxCapacity() const = 0;
};