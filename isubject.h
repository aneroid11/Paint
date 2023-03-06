#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "iobserser.h"

class ISubject
{
public:
    virtual ~ISubject() {}

    virtual void attachObserver(IObserver *observer) = 0;
    virtual void detachObserver(IObserver *observer) = 0;

    virtual void notify(std::string msgForObservers) = 0;
};

#endif // ISUBJECT_H
