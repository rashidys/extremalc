#include <stdlib.h>
typedef enum {
  ON,
  OFF
} state_t;
typedef struct {
  state_t state;
  double temperature;
} engine_t;
// аллокатор памяти
engine_t* engine_new() {
  return (engine_t*)malloc(sizeof(engine_t));
}
// конструктор
void engine_ctor(engine_t* engine) {
  engine->state = OFF;
  engine->temperature = 15;
}
// деструктор
void engine_dtor(engine_t* engine) {
  // Здесь ничего не происходит
}
// поведенческие функции
void engine_turn_on(engine_t* engine) {
  if (engine->state == ON) {
    return;
  }
  engine->state = ON;
  engine->temperature = 75;
}
void engine_turn_off(engine_t* engine) {
  if (engine->state == OFF) {
    return;
  }
  engine->state = OFF;
  engine->temperature = 15;
}
double engine_get_temperature(engine_t* engine) {
  return engine->temperature;
}

