#ifndef SYSTEM_H
#define SYSTEM_H

#include <furniture.h>

class System
{
public:
    System();
    System(const System &other);

    virtual ~System();

    int getNumberOfItems();
    void setNumberOfItems(int numberOfItems);
    int getCurrentNumberOfItems();
    void setCurrentNumberOfItems(int currentNumberOfItems);

    void show();
    void showStockForFurniture(string name);
    void showStockForType(string type);
    void showAllSofas();
    void showAllBookshelfs();
    void addSofa(string name, int price, int stock, int seats, string colour);
    void addBookshelf(string name, int price, int stock, string material, int height);
    void removeFurniture(string name);


private:
    int numberOfItems;
    int currentNumberOfItems;

    Furniture** furniture;

    void expandArray();
};

#endif // SYSTEM_H
