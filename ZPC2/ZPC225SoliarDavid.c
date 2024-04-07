#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include "U25.inc"

struct node {double data; struct node *next;};
typedef struct node stack;

void add_start(stack **seznam, double data){
    stack *new = malloc(sizeof(stack));
    new->data = data;
    new->next = *seznam;
    *seznam = new;
    return;
}

void remove_start(stack *seznam){
    if (seznam==NULL){
        return;
    }
    *seznam = *(seznam->next);
    return;
}

double kalkulator(const char *v,...){
  va_list args;
  va_start(args, v);
  va_end(args);

  stack *st = NULL;
  
  int n = 0;
  double new;
  char k;
  while (v[n]!='\0'){
    k = v[n];
    n++;
    switch (k){
      case 'd':
        add_start(&st, (double) va_arg(args, double));
        break;
      case 'i':
        add_start(&st, (double) va_arg(args, int));
        break;
      case 's':
        new = st->data;
        st->data = pow(new, 2);
        break;
      case 'r':
        new = st->data;
        st->data = sqrt(new);
        break;  
      case '*':
        new = (st->next->data) * (st->data);
        remove_start(st);
        st->data = new; 
        break; 
      case '/':
        new = (st->next->data) / (st->data);
        remove_start(st);
        st->data = new;
        break;
      case '+':
        new = (st->next->data) + (st->data);
        remove_start(st);
        st->data = new;
        break; 
      case '-':
        new = (st->next->data) - (st->data);
        remove_start(st);
        st->data = new;
        break;
      default:
        break;
    }
  }
  return st->data;
}

void main (){
  double d = kalkulator(E,7,2,2.5,4,5);
  printf("%g", d);
}
