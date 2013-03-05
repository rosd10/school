#include "furniture.h"

Furniture::Furniture()
{
    this->setName("");
    this->setPrice(0);
    this->setStock(0);
}

Furniture::Furniture(string name, int price, int stock)
{
    this->setName(name);
    this->setPrice(price);
    this->setStock(stock);
}

Furniture::~Furniture()
{
    this->name = "";
    this->price = 0;
    this->stock = 0;
}

string Furniture::getName()
{
    return this->name;
}

void Furniture::setName(string name)
{
    this->name = name;
}

int Furniture::getPrice()
{
    return this->price;
}

void Furniture::setPrice(int price)
{
    this->price = price;
}

int Furniture::getStock()
{
    return this->stock;
}

void Furniture::setStock(int stock)
{
    this->stock = stock;
}
