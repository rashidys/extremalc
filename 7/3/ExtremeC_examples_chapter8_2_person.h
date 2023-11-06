#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_2_PERSON_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_2_PERSON_H
// предварительное объявление
struct person_t;
// аллокатор памяти
struct person_t* person_new();
// конструктор
void person_ctor(struct person_t*,
                 const char*  /* имя */,
                 const char*  /* фамилия */,
                 unsigned int /* год рождения */);
// деструктор
void person_dtor(struct person_t*);
// поведенческие функции
void person_get_first_name(struct person_t*, char*);
#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_2_PERSON_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_2_PERSON_H
// предварительное объявление
struct person_t;
// аллокатор памяти
struct person_t* person_new();
// конструктор
void person_ctor(struct person_t*,
                 const char*  /* имя */,
                 const char*  /* фамилия */,
                 unsigned int /* год рождения */);
// деструктор
void person_dtor(struct person_t*);
// поведенческие функции
void person_get_first_name(struct person_t*, char*);
ExtremeC_examples_chapter8_2_person.h
ExtremeC_examples_chapter8_2_person_p.h
