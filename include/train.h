// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Wagon {
    bool lamp;
    Wagon* nxt;
    Wagon* prv;
  };

  int stepsCount;
  Wagon* head;
  Wagon* ptr;

 public:
  Train();
  ~Train();
  void addCar(bool light);
  int getLength();
  int getOpCount();
  void resetOps();
};

#endif  // INCLUDE_TRAIN_H_
