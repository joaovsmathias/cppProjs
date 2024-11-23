#include<iostream>
#include <algorithm>  // Para std::copy
#include <vector>



using namespace std;

int& GetValue()
{
    static int value = 10;
    return value;
}

void PrintName(const string& name){
    cout << "[lvalue] " << name << endl;
}

void PrintName(string&& name){
    cout <<  "[rvalue] " << name << endl;
}

int main() {
    
    //int i = GetValue();
    //GetValue() = 5;
    //cout << GetValue() <<endl;
     
    string name{"Joao"};
    PrintName("Joao");
    PrintName(name);

    return 0;  

}