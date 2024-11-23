#include <iostream>
#include <vector>
#include <unordered_map>
#include "ArrayContainer.h"

using namespace std;




int main() {

   

    // Criando um container para 5 inteiros
    ArrayContainer<int, 5> container(0);

    // Preenchendo o container
    container.fill(42);

    // Modificando um elemento
    container[0] = 199;
    container[2] = 99;
    container[4] = 399;

    /*
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
    
    */
    for (ArrayContainer<int, 5>::Iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    
    //ArrayContainer<int, 5>::Iterator it = container.begin();
    //ArrayContainer<int, 5>::Iterator it2 = container.end();
    //cout << it << endl;
    //cout << *it << endl;
    


    return 0;
}
