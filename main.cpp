#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <type_traits>
#include <thread>
#include <tuple>
#include <cstdlib>
#include <map>
#include <array>
#include <variant>
#include <typeinfo> 
#include <any>
#include <memory>

using namespace std;



// c++ 17 changes lambda
//[]               ()              specifiers exeception attr                -> ret            {/*code; */}
//capture list    parameter list      mutable,constexpr,noexcept,attributes    return type        body


class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onNotify(const std::string& message) = 0;
};

// Classe Observável
class Observable {
private:
    // Lista de observadores usando weak_ptr para evitar ciclos
    std::vector<std::weak_ptr<IObserver>> observers;

public:
    // Registrar um observador
    void addObserver(std::shared_ptr<IObserver> observer) {
        observers.push_back(observer);
    }

    // Notificar todos os observadores
    void notify(const std::string& message) {
        for (auto it = observers.begin(); it != observers.end(); ) {
            if (auto observer = it->lock()) { // Converte weak_ptr em shared_ptr se ainda válido
                observer->onNotify(message);
                ++it;
            } else {
                // Remove observadores que já não existem
                it = observers.erase(it);
            }
        }
    }
};


class ConcreteObserver : public IObserver, public std::enable_shared_from_this<ConcreteObserver> {
private:
    std::string name;

public:
    explicit ConcreteObserver(const std::string& observerName) : name(observerName) {}

    // Método chamado quando notificado
    void onNotify(const std::string& message) override {
        std::cout << "Observer [" << name << "] recebeu mensagem: " << message << '\n';
    }
};


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