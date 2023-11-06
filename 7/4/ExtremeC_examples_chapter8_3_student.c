#include <stdlib.h>
#include <string.h>
#include "ExtremeC_examples_chapter8_2_person.h"
// определение person_t находится в следующем заголовке, и оно нам здесь нужно
#include "ExtremeC_examples_chapter8_2_person_p.h"
// предварительное объявление
typedef struct {
  // благодаря этой вложенности мы наследуем все атрибуты класса Person 
  // и получаем доступ ко всем его поведенческим функциям
  person_t person;
  char* student_number;
  unsigned int passed_credits;
} student_t;
// аллокатор памяти
student_t* student_new() {
  return (student_t*)malloc(sizeof(student_t));
}

// конструктор
void student_ctor(student_t* student,
                  const char* first_name,
                  const char* last_name,
                  unsigned int birth_year,
                  const char* student_number,
                  unsigned int passed_credits) {
  // выделяем память для родительского объекта
  student->person = person_new();
  person_ctor(student->person, first_name,
          last_name, birth_year);
  student->student_number = (char*)malloc(16 * sizeof(char));
  strcpy(student->student_number, student_number);
  student->passed_credits = passed_credits;
}
// деструктор
void student_dtor(student_t* student) {
  // сначала нужно уничтожить дочерний объект
  free(student->student_number);
  // затем следует вызвать деструктор родительского класса
  person_dtor(student->person);
  // необходимо также освободить память, выделенную для родительского объекта
  free(student->person);
}
// поведенческие функции
void student_get_first_name(student_t* student, char* buffer) {
  // мы должны использовать поведенческие функции класса Person
  person_get_first_name(student->person, buffer);
}
void student_get_last_name(student_t* student, char* buffer) {
  // мы должны использовать поведенческие функции класса Person
  person_get_last_name(student->person, buffer);
}
unsigned int student_get_birth_year(student_t* student) {
  // мы должны использовать поведенческие функции класса Person
  return person_get_birth_year(student->person);
}
void student_get_student_number(student_t* student, char* buffer) {
  strcpy(buffer, student->student_number);
}
unsigned int student_get_passed_credits(student_t* student) {
  return student->passed_credits;
}
