#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ExtremeC_example s_chapter7_2_gun.h"
// структура атрибутов
typedef struct {
  char* name;
  struct gun_t* gun;
} player_t;
// аллокатор памяти
player_t* player_new() {
  return (player_t*)malloc(sizeof(player_t));
}
// конструктор
void player_ctor(player_t* player, const char* name) {
  player->name =
      (char*)malloc((strlen(name) + 1) * sizeof(char));
  strcpy(player->name, name);
  // Это важно. Указатели агрегации, которые не должны быть заданы 
  // в конструкторе, необходимо обнулить
  player->gun = NULL;
}
// деструктор
void player_dtor(player_t* player) {
  free(player->name);
}
// поведенческие функции
void player_pickup_gun(player_t* player, struct gun_t* gun) {
  // после следующей строчки начинается отношение типа «агрегация»
  player->gun = gun;
}
void player_shoot(player_t* player) {
  // нам нужно проверить, подобрал ли игрок ружье, 
  // иначе стрельба не имеет смысла
  if (player->gun) {
    gun_trigger(player->gun);
  } else {
    printf("Player wants to shoot but he doesn't have a gun!");
    exit(1);
  }
}
void player_drop_gun(player_t* player) {
  // После следующей строчки завершается агрегация двух объектов. 
  // Заметьте, что объект gun не нужно освобождать, поскольку 
  // данный объект не является его владельцем (как в композиции).
  player->gun = NULL;
}

