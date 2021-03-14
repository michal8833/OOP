#include "../include/RingBuffer.h"

RingBuffer::RingBuffer(unsigned capacity) {
    this->capacity = capacity;

    buffer = new int*[capacity];

    addIndex = removeIndex = 0;
}

unsigned RingBuffer::getCapacity() const {
    return capacity;
}

void RingBuffer::add(int i) {
    if(buffer[addIndex%capacity] != nullptr) {
        *(buffer[addIndex]) = i;
        addIndex = (addIndex+1)%capacity;
        removeIndex = (removeIndex+1)%capacity;
    }
    else {
        buffer[addIndex] = new int(i);
        addIndex = (addIndex+1)%capacity;
    }
}

int RingBuffer::getValue(unsigned index) {
    if(index >= capacity) return 0;
    return buffer[index] == nullptr ? 0 : *(buffer[index]);
}

int RingBuffer::remove() {
    int retVal = buffer[removeIndex] == nullptr ? 0 : *(buffer[removeIndex]);
    if(buffer[removeIndex] != nullptr)
        delete buffer[removeIndex];
    buffer[removeIndex] = nullptr;
    removeIndex = (removeIndex+1)%capacity;

    return retVal;
}
