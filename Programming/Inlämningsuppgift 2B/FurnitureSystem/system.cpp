#include "system.h"
#include <iostream>
#include <sofa.h>
#include <furniture.h>
#include <bookshelf.h>
#include <typeinfo>

using namespace std;

System::System()
{
    this->numberOfItems = 20;
    this->furniture = new Furniture*[this->numberOfItems];
}

System::System(const System &other)
{
    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        delete this->furniture[i];
    }

    delete [] this->furniture;

    this->currentNumberOfItems = other.currentNumberOfItems;
    this->numberOfItems = other.numberOfItems;

    this->furniture = new Furniture*[this->numberOfItems];

    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        this->furniture[i] = other.furniture[i];
    }

}

System::~System()
{
    for(int i = 0; i <this->currentNumberOfItems; i++)
    {
        delete this->furniture[i];
    }

    delete [] this->furniture;
}

int System::getNumberOfItems()
{
    return this->numberOfItems;
}

void System::setNumberOfItems(int numberOfItems)
{
    this->numberOfItems = numberOfItems;
}

int System::getCurrentNumberOfItems()
{
    return this->currentNumberOfItems;
}

void System::setCurrentNumberOfItems(int currentNumberOfItems)
{
    this->currentNumberOfItems = currentNumberOfItems;
}

void System::show()
{
    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        cout << this->furniture[i]->toString() << endl;
    }
}

void System::showStockForFurniture(string name)
{
    bool found = false;

    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        if(this->furniture[i]->getName() == name)
        {
            found = true;
            cout << "Stock for " << name << ": " << this->furniture[i]->getStock() << endl;
        }
    }

    if(!found)
    {
        cout << "Couldn't find entry for " << name << endl;
    }
}

void System::showStockForType(string type)
{
    int total = 0;

    if(type == "sofa")
    {
        for(int i = 0; i < this->currentNumberOfItems; i++)
        {
            if(dynamic_cast<Sofa*>(this->furniture[i]))
            {
                total += this->furniture[i]->getStock();
            }
        }
        cout << "Total stock for sofas: " << total << endl;
    }
    else if(type == "bookshelf")
    {
        for(int i = 0; i < this->currentNumberOfItems; i++)
        {
            if(dynamic_cast<Bookshelf*>(this->furniture[i]))
            {
                total += this->furniture[i]->getStock();
            }
        }
        cout << "Total stock for bookshelfs: " << total << endl;
    }
    else
    {
        cout << "Error: wrong input" << endl;
    }

}

void System::showAllSofas()
{
    cout << "Info from all sofas" << endl;
    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        if(dynamic_cast<Sofa*>(this->furniture[i]))
        {
            cout << this->furniture[i]->toString() << endl;
        }
    }
}

void System::showAllBookshelfs()
{
    cout << "Info from all bookshelfs" << endl;
    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        if(dynamic_cast<Bookshelf*>(this->furniture[i]))
        {
            cout << this->furniture[i]->toString() << endl;
        }
    }
}

void System::addSofa(string name, int price, int stock, int seats, string colour)
{
    if(this->currentNumberOfItems == this->numberOfItems)
    {
        this->expandArray();
    }

    this->furniture[this->currentNumberOfItems] = new Sofa(name, price, stock, seats, colour);
    this->currentNumberOfItems++;

    cout << "Sofa added" << endl;
}

void System::addBookshelf(string name, int price, int stock, string material, int height)
{
    if(this->currentNumberOfItems == this->numberOfItems)
    {
        this->expandArray();
    }

    this->furniture[this->currentNumberOfItems] = new Bookshelf(name, price, stock, material, height);
    this->currentNumberOfItems++;

    cout << "Bookshelf added" << endl;

}

void System::removeFurniture(string name)
{
    bool found = false;

    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        if(this->furniture[i]->getName() == name)
        {
            delete this->furniture[i];

            for(int n = i; n < this->currentNumberOfItems-1; n++)
            {
                this->furniture[i] = this->furniture[i+1];
            }

            this->currentNumberOfItems--;

            found = true;
        }
    }

    if(!found)
    {
        cout << "No furniture by that name found" << endl;
    }
    else
    {
        cout << "Furniture " << name << " removed." << endl;
    }
}

void System::expandArray()
{
    this->numberOfItems += 10;

    Furniture **tempArray = new Furniture*[this->numberOfItems];

    for(int i = 0; i < this->currentNumberOfItems; i++)
    {
        tempArray[i] = this->furniture[i];
    }

    delete [] this->furniture;

    this->furniture = tempArray;
}
