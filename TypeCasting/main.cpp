#include <iostream>
#include <cstring>
using namespace std;

struct Data {
    int id;
    double value;
};

int main() {
    char buffer[sizeof(Data)];

    // Criando dados brutos
    Data originalData = {123, 456.78};
    memcpy(buffer, &originalData, sizeof(Data));

    // Interpretando os dados do buffer como um objeto do tipo `Data`
    Data* dataPtr = reinterpret_cast<Data*>(buffer);

    cout << "ID: " << dataPtr->id << ", Value: " << dataPtr->value << endl;

    return 0;
}
