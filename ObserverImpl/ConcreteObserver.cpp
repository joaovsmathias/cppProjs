#include "ConcreteObserver.h"
#include<string>

ConcreteObserver::ConcreteObserver(const std::string& observerName) : name(observerName) {}

void ConcreteObserver::onNotify(const std::string& message){
    std::cout << "Observer [" << name << "] recebeu mensagem: " << message << '\n';
}