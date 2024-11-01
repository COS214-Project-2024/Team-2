#ifndef CITYGROWTH_H
#define CITYGROWTH_H


class CityGrowth
{
    private:
        int size = 0;
    
    public:
        virtual bool grow() = 0;
        virtual bool shrink() = 0;
        virtual int get() const = 0 ;
};

#endif