#pragma once

class RingBuffer {
private:
    int **buffer;

    unsigned capacity;

    unsigned addIndex;
    unsigned removeIndex;

public:
    explicit RingBuffer(unsigned capacity = 5);
    unsigned getCapacity() const;
    void add(int i);
    int getValue(unsigned index);
    int remove();
};