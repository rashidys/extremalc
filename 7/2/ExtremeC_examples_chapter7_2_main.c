#include <stdio.h>
#include <stdlib.h>
#include "ExtremeC_examples_chapter7_2_player.h"
#include "ExtremeC_examples_chapter7_2_gun.h"
int main(int argc, char** argv) {
  // создаем и инициализируем объект gun
  struct gun_t* gun = gun_new();
  gun_ctor(gun, 3);
  // создаем и инициализируем объект player
  struct player_t* player = player_new();
  player_ctor(player, "Billy");
  // начинаем агрегацию
  player_pickup_gun(player, gun);
  // стреляем, пока не закончатся патроны
  while (gun_has_bullets(gun)) {
    player_shoot(player);
  }
  // перезаряжаем ружье
  gun_refill(gun);
  // стреляем, пока не закончатся патроны
  while (gun_has_bullets(gun)) {
          player_shoot(player);
  }
  // завершаем агрегацию
  player_drop_gun(player);
  // уничтожаем и освобождаем объект player
  player_dtor(player);
  free(player);
  // уничтожаем и освобождаем объект gun
  gun_dtor(gun);
  free(gun);
  return 0;
}

