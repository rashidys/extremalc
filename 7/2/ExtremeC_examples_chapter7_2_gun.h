#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_2_GUN_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_2_GUN_H
typedef int bool_t;
// предварительное объявление типа
struct gun_t;
// аллокатор памяти
struct gun_t* gun_new();
// конструктор
void gun_ctor(struct gun_t*, int);
// деструктор
void gun_dtor(struct gun_t*);
// поведенческие функции
bool_t gun_has_bullets(struct gun_t*);
void gun_trigger(struct gun_t*);
void gun_refill(struct gun_t*);
#endif

