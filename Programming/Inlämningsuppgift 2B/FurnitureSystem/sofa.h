#ifndef SOFA_H
#define SOFA_H

#include<furniture.h>

class Sofa : public Furniture
{
public:
    Sofa();
    Sofa(string name, int price, int stock, int seats, string colour);

    virtual ~Sofa();

    string toString();

    int getSeats();
    void setSeats(int seats);
    string getColour();
    void setColour(string colour);


private:
    int seats;
    string colour;
};

#endif // SOFA_H
