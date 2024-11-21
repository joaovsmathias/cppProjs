#include "Observable.h"


void Observable::addObserver(std::shared_ptr<IObserver> observer) {
    observers.push_back(observer);
}

// Notificar todos os observadores
void Observable::notify(const std::string& message) {
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