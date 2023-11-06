#ifndef EXTREME_C_EXAMPLES_CHAPTER_7_2_PLAYER_H
#define EXTREME_C_EXAMPLES_CHAPTER_7_2_PLAYER_H
// предварительное объявление типа
struct player_t;
struct gun_t;
// аллокатор памяти
struct player_t* player_new();
// конструктор
void player_ctor(struct player_t*, const char*);
// деструктор
void player_dtor(struct player_t*);
// поведенческие функции
void player_pickup_gun(struct player_t*, struct gun_t*);
void player_shoot(struct player_t*);
void player_drop_gun(struct player_t*);
#endif

