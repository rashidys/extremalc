#include <stdlib.h>
#include <string.h>
// определение person_t находится в следующем заголовке
#include "ExtremeC_examples_chapter8_2_person_p.h"
// аллокатор памяти
person_t* person_new() {
  return (person_t*)malloc(sizeof(person_t));
}
// конструктор
void person_ctor(person_t* person,
                 const char* first_name,
                 const char* last_name,
                 unsigned int birth_year) {
  strcpy(person->first_name, first_name);
  strcpy(person->last_name, last_name);
  person->birth_year = birth_year;
}
// деструктор
void person_dtor(person_t* person) {
  // здесь ничего не происходит
}
// поведенческие функции
void person_get_first_name(person_t* person, char* buffer) {
  strcpy(buffer, person->first_name);
}
void person_get_last_name(person_t* person, char* buffer) {
  strcpy(buffer, person->last_name);
}

