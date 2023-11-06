#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_!_CAR_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_1_CAR_H

struct car_t;
// конструктор
struct car_t* car_new();

//деструктор
void car_dtor(struct car_t*);

// поведенческие функции

void car_start(struct car_t*);
void car_stop(struct car_t*);
double car_get_engine_temperature(struct car_t*);

#endif



