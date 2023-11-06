#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_DUCK_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_DUCK_H
// предварительное объявление
struct duck_t;
// аллокатор памяти
struct duck_t* duck_new();
// конструктор
void duck_ctor(struct duck_t*);
// деструктор
void duck_dtor(struct duck_t*);
// все поведенческие функции наследуются от класса Animal
#endif
Как	видите,	это	очень	похоже	на	класс	Cat.	Посмотрим	на	приватное	определение	
класса	Duck	(листинг	8.26).
Листинг 8.26. Приватная реализация класса Duck (ExtremeC_examples_chapter8_4_duck.c)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExtremeC_examples_chapter8_4_animal.h"
#include "ExtremeC_examples_chapter8_4_animal_p.h"
typedef struct {
  animal_t animal;
} duck_t;
// определяем новое поведение для операции sound
void __duck_sound(void* ptr) {
 animal_t* animal = (animal_t*)ptr;
  printf("%s: Quacks\n", animal->name);
}
// аллокатор памяти
duck_t* duck_new() {
  return (duck_t*)malloc(sizeof(duck_t));
}
// конструктор
void duck_ctor(duck_t* duck) {
  animal_ctor((struct animal_t*)duck);
  strcpy(duck->animal.name, "Duck");
  // указываем на новую поведенческую функцию
  // переопределение происходит именно здесь
  duck->animal.sound_func = __duck_sound;
}
// деструктор
void duck_dtor(duck_t* duck) {
  animal_dtor((struct animal_t*)duck);
}

