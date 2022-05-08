#ifndef IOBSERSER_H
#define IOBSERSER_H

#include <string>

class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void updateObserver(std::string msgFromSubject) = 0;
};

#endif // IOBSERSER_H
