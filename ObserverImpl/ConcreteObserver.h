#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H

#include "IObserver.h"
#include <memory>
#include <string>
#include <iostream>


class ConcreteObserver : public IObserver, public std::enable_shared_from_this<ConcreteObserver> {
private:
    std::string name;

public:
    explicit ConcreteObserver(const std::string&);
    void onNotify(const std::string&)override;
};

#endif
