#include <unistd.h> // для функции sleep
#include <stdlib.h> // для функции malloc
#include <stdio.h> // для printf
int main(int argc, char** argv) {
  void* ptr = malloc(1024); // выделяем для кучи 1 Кбайт
  printf("Address: %p\n", ptr);
  fflush(stdout); // для принудительного вывода
  // бесконечный цикл
  while (1) {
    sleep(1); // засыпаем на 1 секунду
  };
  return 0;
}

