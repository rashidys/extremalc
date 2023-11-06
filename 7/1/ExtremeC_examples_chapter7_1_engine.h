#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_1_ENGINE_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_1_ENGINE_H

struct engine_t;

//алокатор памяти
struct engine_t* engine_new();

//конструктор
void engine_ctor(struct engine_t*);

//деструктор
void engine_dtor(struct engine_t*);

//поведенческие функции
void engine_turn_on(struct engine_t*);
void engine_turn_off(struct engine_t*);
double engine_get_temperature(struct engine_t*);

#endif
