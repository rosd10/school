#ifndef FURNITURE_H
#define FURNITURE_H

#include<string>

using namespace std;

class Furniture
{
public:
    Furniture();
    Furniture(string name, int price, int stock);

    virtual ~Furniture();

    virtual string toString() = 0;

    string getName();
    void setName(string name);
    int getPrice();
    void setPrice(int price);
    int getStock();
    void setStock(int stock);

private:
    // Name of the furniture
    string name;

    // The price of the furniture
    int price;

    //Number of items in stock
    int stock;
};

#endif // FURNITURE_H
