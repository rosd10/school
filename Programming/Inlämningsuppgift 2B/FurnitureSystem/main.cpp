#include <iostream>
#include <cstdlib>
#include <system.h>

using namespace std;

bool handleChoice(int choice, System *system)
{
    bool running = true;
    string name, type, temp;

    switch(choice)
    {
    case 1:
        cout << endl << endl << "Showing all furniture" << endl;
        system->show();
        break;

    case 2:
        cout << endl << endl << "Show stock for all furniture" << endl;
        cout << "Enter name of furniture to show stock: ";
        getline(cin, name);

        system->showStockForFurniture(name);

        break;

    case 3:
        cout << endl << endl << "Show stock for all furniture of a specific type" << endl;
        cout << "Enter what type you want to show stock (sofa/bookshelf): ";
        getline(cin, type);

        system->showStockForType(type);

        break;

    case 4:
        cout << endl << endl << "Show information for all sofas" << endl;
        system->showAllSofas();

        break;

    case 5:
        cout << endl << endl << "Show information for all bookshelfs" << endl;
        system->showAllBookshelfs();

        break;

    case 6:
        cout << endl << endl << "Add furniture" << endl;
        cout << "Enter type of furniture (sofa/bookshelf): ";
        getline(cin, type);

        if(type == "sofa")
        {
            string colour;
            int price, stock, seats;

            cout << "Enter name: ";
            getline(cin, name);

            cout << "Enter price: ";
            getline(cin, temp);
            price = atoi(temp.c_str());

            cout << "Enter stock: ";
            getline(cin, temp);
            stock = atoi(temp.c_str());

            cout << "Enter seats: ";
            getline(cin, temp);
            seats = atoi(temp.c_str());

            cout << "Enter colour: ";
            getline(cin, colour);

            system->addSofa(name, price, stock, seats, colour);

        }
        else if(type == "bookshelf")
        {
            string material;
            int price, stock, height;

            cout << "Enter name: ";
            getline(cin, name);

            cout << "Enter price: ";
            getline(cin, temp);
            price = atoi(temp.c_str());

            cout << "Enter stock: ";
            getline(cin, temp);
            stock = atoi(temp.c_str());

            cout << "Enter material: ";
            getline(cin, material);

            cout << "Enter height: ";
            getline(cin, temp);
            height = atoi(temp.c_str());

            system->addBookshelf(name, price, stock, material, height);

        }
        else
        {
            cout << endl << "Error: Invalid type" << endl;
        }

        break;

    case 7:
        cout << endl << endl << "Remove furniture" << endl;
        cout << "Enter name of furniture to remove: ";
        getline(cin, name);
        system->removeFurniture(name);

        break;

    case 0:
        running = false;
        break;

    default:
        cout << endl << "Error, invalid choice" << endl;
        break;
    }

    return running;

}

bool showMenu(System *system)
{
    cout << endl << "Menu" << endl;
    cout << "1. Show all furniture" << endl;
    cout << "2. Show stock of specified furniture" << endl;
    cout << "3. Show total stock of type of furniture" << endl;
    cout << "4. Show all sofas" << endl;
    cout << "5. Show all bookshelfs" << endl;
    cout << "6. Add furniture" << endl;
    cout << "7. Remove furniture" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter number of your choice: ";
    string temp;
    getline(cin, temp);

    return handleChoice(atoi(temp.c_str()), system);


}

int main()
{
    System *system = new System();

    while(showMenu(system));

    delete system;

    cout << "Goodbye" << endl;

    return 0;
}

