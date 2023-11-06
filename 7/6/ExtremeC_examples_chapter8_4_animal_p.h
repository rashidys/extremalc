#ifndef EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_P_H
#define EXTREME_C_EXAMPLES_CHAPTER_8_4_ANIMAL_P_H
// тип указателя, необходимого для обращения к разным версиям animal_sound
typedef void (*sound_func_t)(void*);
// предварительное объявление
typedef struct {
  char* name;
  // этот член класса является указателем на функцию, 
  // которая отвечает за вывод звуков
  sound_func_t sound_func;
} animal_t;
#endif

