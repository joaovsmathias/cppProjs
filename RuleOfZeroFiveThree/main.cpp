#include<iostream>

using namespace std;


class CommonBaseClass
{
public:
    int common_value;
};

class BaseClass1 : virtual public CommonBaseClass{
public:
    int value;
    void function1(){ cout << "Function1 BaseClass1 " << endl;}
};

class BaseClass2 : virtual public CommonBaseClass{
public:
    int value;
    void function1(){ cout << "Function1 BaseClass2 " << endl;}
};



class DerivedClass: public BaseClass1, public BaseClass2
{
public:
    void function1(){ cout << "Function1 DerivedClass " << endl;}
};

int main() {

    DerivedClass derived;
    derived.BaseClass1::function1();
    derived.common_value = 10;


    return 0;   
}