#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_H
// предварительное объявление
struct animal_t;
// аллокатор памяти
struct animal_t* animal_new();
// конструктор
void animal_ctor(struct animal_t*);
// деструктор
void animal_dtor(struct animal_t*);
// поведенческие функции
void animal_get_name(struct animal_t*, char*);
void animal_sound(struct animal_t*);
#endif

