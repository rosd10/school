#include "sofa.h"
#include<sstream>

Sofa::Sofa() : Furniture()
{
    this->seats = 0;
    this->colour = "";
}

Sofa::Sofa(string name, int price, int stock, int seats, string colour)
    :Furniture(name, price, stock)
{
    this->seats = seats;
    this->colour = colour;
}

Sofa::~Sofa()
{
    this->seats = 0;
    this->colour = "";
}

string Sofa::toString()
{
    std::ostringstream oss;
    oss << "Name: " << this->getName() << " Price: " << this->getPrice() << " Items in stock: " << this->getStock() << " Seats: " << this->seats << " Colour: " << this->colour;
    return oss.str();
}

int Sofa::getSeats()
{
    return this->seats;
}

void Sofa::setSeats(int seats)
{
    this->seats = seats;
}

string Sofa::getColour()
{
    return this->colour;
}

void Sofa::setColour(string colour)
{
    this->colour = colour;
}
