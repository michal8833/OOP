#include "observer/Observable.h"

void observer::Observable::registerObserver(Observer *observer) {
    this->observers.insert(observer);
}

void observer::Observable::unregisterObserver(Observer *observer) {
    this->observers.erase(observer);
}

void observer::Observable::notifyObservers(float value) {
    for(Observer* observer : observers)
        observer->notify(value);
}
