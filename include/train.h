#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Wagon {
    bool lamp;        // состояние лампочки
    Wagon* nxt;
    Wagon* prv;
  };
  
  int stepsCount;     // число переходов между вагонами
  Wagon* head;        // указатель на первый вагон
  Wagon* ptr;         // текущий вагон для алгоритма
  
 public:
  Train();
  ~Train();
  void addCar(bool light);   // добавить вагон с начальным состоянием лампочки
  int getLength();           // вычислить длину поезда
  int getOpCount();          // вернуть количество переходов
  void resetOps();           // обнулить счетчик переходов
};

#endif
