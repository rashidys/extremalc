#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_CAT_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_CAT_H
// предварительное объявление
struct cat_t;
// аллокатор памяти
struct cat_t* cat_new();
// конструктор
void cat_ctor(struct cat_t*);
// деструктор
void cat_dtor(struct cat_t*);
// все поведенческие функции наследуются от класса Animal
#endif

