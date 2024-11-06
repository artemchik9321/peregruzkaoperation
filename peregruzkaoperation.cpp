// peregruzkaoperation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
using namespace std;

class Flat 
{
    int flatzz;
    char* adr;
    double price;
public:
    Flat() 
    {
        price = 0;
        adr = nullptr;
        flatzz = 0;
    }
    Flat(const char* _adr, int _flatzz, double _price)
    {
        flatzz = _flatzz;
        price = _price;
        adr = new char[strlen(_adr) + 1];
        strcpy_s(adr, strlen(_adr) + 1, _adr);
    }

    ~Flat() 
    {
        delete[] adr;
        cout << "Destructor";
    }

    Flat(const Flat& obj) 
    {
        flatzz = obj.flatzz;
        price = obj.price;
        adr = new char[strlen(obj.adr) + 1];
        strcpy_s(adr, strlen(obj.adr) + 1, obj.adr);
    }

    Flat& operator=(const Flat& obj)
    {
        if (this == &obj) 
        {
            return *this;
        }
        if (adr != nullptr) 
        {
            delete[]adr;
        }
        flatzz = obj.flatzz;
        price = obj.price;
        adr = new char[strlen(obj.adr) + 1];
        strcpy_s(adr, strlen(obj.adr) + 1, obj.adr);
        return *this;
    }

    bool operator==(const Flat& obj)
    {
        if (flatzz == obj.flatzz)
        {
            return true;
        }
        return false;
    }

    bool operator>(const Flat& obj)
    {
        if (price > obj.price) 
        {
            return true;
        }
        return false;
    }

    void Print() 
    {
        cout << adr << endl << price << endl << flatzz << endl;
    }
};
int main() 
{
    Flat a("1 flat", 26, 199990);
    Flat b("2 flat", 27, 1777777);
    Flat c = a;
    Flat d("3 flat", 20, 117777);
    d = b;
    if (a == c) cout << "a and c odinakova area" << endl;
    if (b > a) cout << "b dorozhe chem a" << endl;
    a.Print();
}