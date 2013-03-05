#include "bookshelf.h"
#include <sstream>

Bookshelf::Bookshelf()
{
    this->setName("");
    this->setPrice(0);
    this->setStock(0);
    this->material = "";
    this->height = 0;
}

Bookshelf::Bookshelf(string name, int price, int stock, string material, int height)
    :Furniture(name, price, stock)
{
    this->material = material;
    this->height = height;
}

Bookshelf::~Bookshelf()
{
    this->setName("");
    this->setPrice(0);
    this->setStock(0);
    this->material = "";
    this->height = 0;
}

string Bookshelf::toString()
{
    std::ostringstream oss;
    oss << "Name: " << this->getName() << " Price: " << this->getPrice() << " Items in stock: " << this->getStock() << " Material: " << this->getMaterial() << " Height: " << this->getHeight();
    return oss.str();
}

string Bookshelf::getMaterial()
{
    return this->material;
}

void Bookshelf::setMaterial(string material)
{
    this->material = material;
}

int Bookshelf::getHeight()
{
    return this->height;
}

void Bookshelf::setHeight(int height)
{
    this->height = height;
}


