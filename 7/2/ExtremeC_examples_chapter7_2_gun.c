#include <stdlib.h>
typedef int bool_t;
// структура атрибутов
typedef struct {
  int bullets;
} gun_t;
// аллокатор памяти
gun_t* gun_new() {
  return (gun_t*)malloc(sizeof(gun_t));
}
// конструктор
void gun_ctor(gun_t* gun, int initial_bullets) {
  gun->bullets = 0;
  if (initial_bullets > 0) {
    gun->bullets = initial_bullets;
  }
}
// деструктор
void gun_dtor(gun_t* gun) {
  // здесь ничего не происходит
}
// поведенческие функции
bool_t gun_has_bullets(gun_t* gun) {
  return (gun->bullets > 0);
}
void gun_trigger(gun_t* gun) {
  gun->bullets--;
}
void gun_refill(gun_t* gun) {
  gun->bullets = 7;
}

