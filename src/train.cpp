// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : stepsCount(0), head(nullptr), ptr(nullptr) {}

Train::~Train() {
    if (head == nullptr) return;
    Wagon* current = head->nxt;
    while (current != head) {
        Wagon* toDelete = current;
        current = current->nxt;
        delete toDelete;
    }
    delete head;
}

void Train::addCar(bool light) {
    Wagon* newWagon = new Wagon{light, nullptr, nullptr};
    if (head == nullptr) {
        head = newWagon;
        head->nxt = head;
        head->prv = head;
        ptr = head;
    } else {
        Wagon* last = head->prv;
        last->nxt = newWagon;
        newWagon->prv = last;
        newWagon->nxt = head;
        head->prv = newWagon;
    }
}

int Train::getLength() {
    if (head == nullptr) return 0;
    resetOps();
    ptr = head;
    if (ptr->lamp == false) {
        ptr->lamp = true;
    }
    int length = 0;
    bool finished = false;
    while (!finished) {
        while (true) {
            ptr = ptr->nxt;
            ++stepsCount;
            ++length;
            if (ptr->lamp == true) {
                ptr->lamp = false;
                break;
            }
        }
        for (int step = 0; step < length; ++step) {
            ptr = ptr->prv;
            ++stepsCount;
        }
        if (ptr->lamp == false) {
            finished = true;
        } else {
            length = 0;
        }
    }
    return length;
}

int Train::getOpCount() {
    return stepsCount;
}

void Train::resetOps() {
    stepsCount = 0;
}
