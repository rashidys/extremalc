#include <stdio.h>
#include <stdlib.h>
#include "ExtremeC_examples_chapter7_1_car.h"
int main(int argc, char** argv) {
  // выделяем память для объекта car
  struct car_t *car = car_new();
 // создаем объект car
  car_ctor(car);
  printf("Engine temperature before starting the car: %f\n",
          car_get_engine_temperature(car));
  car_start(car);
  printf("Engine temperature after starting the car: %f\n",
          car_get_engine_temperature(car));
  car_stop(car);
  printf("Engine temperature after stopping the car: %f\n",
          car_get_engine_temperature(car));
  // уничтожаем объект car
  car_dtor(car);
  // освобождаем память, выделенную для объекта car
  free(car);
  
  return 0;
}

