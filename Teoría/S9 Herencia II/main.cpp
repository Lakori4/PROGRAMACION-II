 // Santiago Valderrama


#include <iostream>


using namespace std;

class clase1
{
private:
    int n;
public:
    clase1();
    int getn() {return n;}
    ~clase1();
};

class clase2: public clase1
{
private:
    char c;
public:
    clase2();
    int getc() {return c;}
    ~clase2();
};

clase2::clase2(/* args */)
{
}

clase2::~clase2()
{
}


clase1::clase1(/* args */)
{
}

clase1::~clase1()
{
}


int main () {

    clase1 c1;

    clase2 c2;

    cout << c2.getn();
    return 0;
}
