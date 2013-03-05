#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include<furniture.h>

class Bookshelf : public Furniture
{
public:
    Bookshelf();
    Bookshelf(string name, int price, int stock, string material, int height);

    virtual ~Bookshelf();

    string toString();

    string getMaterial();
    void setMaterial(string material);
    int getHeight();
    void setHeight(int height);

private:
    string material;
    int height;
};

#endif // BOOKSHELF_H
