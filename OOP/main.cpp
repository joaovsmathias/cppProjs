#include<iostream>
#include <algorithm>  // Para std::copy
#include <vector>



using namespace std;

//regra de Três
/*
class MyResource {
public:
    // Constructor and destructor
    MyResource() : data(new int[100]) {} 
    ~MyResource() { delete[] data; } 

    // Copy constructor
    MyResource(const MyResource& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Copy assignment operator
    MyResource& operator=(const MyResource& other) {
        if (&other == this) { return *this; }
        std::copy(other.data, other.data + 100, data);
        return *this;
    }

private:
    int* data;
}; */

//Rule of Five

class MyResource {
public:
    // Constructors and destructor
    MyResource() : data(new int[100]) {}
    ~MyResource() { delete[] data; }

    // Copy constructor
    MyResource(const MyResource& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Copy assignment operator
    MyResource& operator=(const MyResource& other) {
        if (&other == this) { return *this; }
        std::copy(other.data, other.data + 100, data);
        return *this;
    }

    // Move constructor
    MyResource(MyResource&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    MyResource& operator=(MyResource&& other) noexcept {
        if (&other == this) { return *this; }
        delete[] data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }

private:
    int* data;
};

int main() {
    
    // Testando o comportamento do construtor e destruidor
    std::cout << "Creating a resource (r1)\n";
    MyResource r1;  // Construtor padrão

    std::cout << "\nCreating a copy of r1 (r2) using copy constructor\n";
    MyResource r2 = r1;  // Construtor de cópia

    std::cout << "\nAssigning r1 to r3 (copy assignment operator)\n";
    MyResource r3;
    r3 = r1;  // Operador de atribuição por cópia

    std::cout << "\nCreating a new resource (r4) and moving it to r5 (move constructor)\n";
    MyResource r4;  // Construtor padrão
    MyResource r5 = std::move(r4);  // Construtor de movimento

    std::cout << "\nAssigning r5 to r6 using move assignment operator\n";
    MyResource r6;
    r6 = std::move(r5);  // Operador de atribuição por movimento

    return 0;   
    

}