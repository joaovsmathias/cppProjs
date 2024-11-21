#include<memory>
#include"Observable.h"
#include"ConcreteObserver.h"


using namespace std;



int main() {
    
    auto observable = std::make_shared<Observable>();
    auto observer1 = std::make_shared<ConcreteObserver>("Observer1");
    auto observer2 = std::make_shared<ConcreteObserver>("Observer2");

    // Registrando os observadores
    observable->addObserver(observer1);
    observable->addObserver(observer2);

    // Enviando uma notificação
    observable->notify("Primeira mensagem");

    // Simulando a destruição de um observador
    observer1.reset(); // Libera a memória do Observer1

    // Enviando outra notificação
    observable->notify("Segunda mensagem");

    return 0;
}