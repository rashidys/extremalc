#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_3_STUDENT_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_3_STUDENT_H
// предварительное объявление
struct student_t;
// аллокатор памяти
struct student_t* student_new();
// конструктор
void student_ctor(struct student_t*,
                  const char*  /* имя */,
                  const char*  /* фамилия */,
                  unsigned int /* год рождения */,
                  const char*  /* номер студенческого билета */,
                  unsigned int /* засчитанные кредиты */);
// деструктор
void student_dtor(struct student_t*);
// поведенческие функции
void student_get_first_name(struct student_t*, char*);
void student_get_last_name(struct student_t*, char*);
unsigned int student_get_birth_year(struct student_t*);
void student_get_student_number(struct student_t*, char*);
unsigned int student_get_passed_credits(struct student_t*);
#endif

