#include <stdlib.h>
// Car может работать только с публичным интерфейсом Engine
#include "ExtremeC_examples_chapter7_1_engine.h"
typedef struct {
  // благодаря этому атрибуту устанавливается отношение композиции
  struct engine_t* engine;
} car_t;
car_t* car_new() {
  return (car_t*)malloc(sizeof(car_t));
}
void car_ctor(car_t* car) {
  // выделяем память для объекта engine
  car->engine = engine_new();
  // создаем объект engine
  engine_ctor(car->engine);
}
void car_dtor(car_t* car) {
  // уничтожаем объект engine
  engine_dtor(car->engine);
  // освобождаем память, выделенную для объекта engine
  free(car->engine);
}
void car_start(car_t* car) {
  engine_turn_on(car->engine);
}
void car_stop(car_t* car) {
  engine_turn_off(car->engine);
}
double car_get_engine_temperature(car_t* car) {
  return engine_get_temperature(car->engine);
}

