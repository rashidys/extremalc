#include <stdio.h>
#include <stdlib.h>
#include "ExtremeC_examples_chapter8_3_student.h"
int main(int argc, char** argv) {
  // создаем объект student
  struct student_t* student = student_new();
  student_ctor(student, "John", "Doe", 1987, "TA5667", 134);
  // Мы должны использовать поведенческие функции объекта student, 
  // так как его указатель нельзя привести к типу person и мы
  // не имеем доступа к приватному родительскому указателю
  // в объекте student.
  char buffer[32];
  student_get_first_name(student, buffer);
  printf("First name: %s\n", buffer);
  student_get_last_name(student, buffer);
  printf("Last name: %s\n", buffer);
 
  printf("Birth year: %d\n", student_get_birth_year(student));
  student_get_student_number(student, buffer);
  printf("Student number: %s\n", buffer);
  printf("Passed credits: %d\n", student_get_passed_credits(student));
  // уничтожаем и освобождаем объект student
  student_dtor(student);
  free(student);
  return 0;
}
