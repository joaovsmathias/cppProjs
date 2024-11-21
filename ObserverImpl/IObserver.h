#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>


class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onNotify(const std::string&)=0;
};

#endif
