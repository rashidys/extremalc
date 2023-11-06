#include <stdio.h> // для функции printf
#include <stdlib.h> // для функций по работе с кучей
#define QUEUE_MAX_SIZE 100
typedef struct {
  int front;
  int rear;
  double* arr;
} queue_t;
void init(queue_t* q) {
  q->front = q->rear = 0;
  // выделенными здесь блоками кучи владеет объект очереди
  q->arr = (double*)malloc(QUEUE_MAX_SIZE * sizeof(double));
}
void destroy(queue_t* q) {
  free(q->arr);
}
int size(queue_t* q) {
  return q->rear - q->front;
}
void enqueue(queue_t* q, double item) {
  q->arr[q->rear] = item;
  q->rear++;
}
double dequeue(queue_t* q) {
  double item = q->arr[q->front];
  q->front++;
  return item;
}
int main(int argc, char** argv) {
  // выделенными здесь блоками кучи владеет функция main
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  // выделяем необходимую память для объекта очереди
  init(q);
  enqueue(q, 6.5);
  enqueue(q, 1.3);
  enqueue(q, 2.4);
  printf("%f\n", dequeue(q));
  printf("%f\n", dequeue(q));
  printf("%f\n", dequeue(q));
  // освобождаем ресурсы, полученные объектом очереди
  destroy(q);
  // освобождаем память, выделенную для объекта кучи, принадлежащего функции main
  free(q);
  return 0;
}
