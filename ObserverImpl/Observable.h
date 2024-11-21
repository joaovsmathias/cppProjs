#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include<vector>
#include<memory>
#include"IObserver.h"

class Observable {
private:
    
    std::vector<std::weak_ptr<IObserver>> observers;

public:
    // Registrar um observador
    void addObserver(std::shared_ptr<IObserver>);

    // Notificar todos os observadores
    void notify(const std::string&);
};

#endif
