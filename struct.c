#include <stdio.h>
#include <stdlib.h>

struct node{ int i; struct node *next; };

void print_recur(struct node *n, int a){
  if (!a) printf("[");
  if (!(n -> next)) printf("%d]\n", n->i);
  else{
    printf("%d, ", n->i);
    print_recur(n->next, 1);
  }
  return;
}

void print_list(struct node *n){
  print_recur(n, 0);
}

struct node* insert_front(int x, struct node *n){
  struct node *q = (struct node*)malloc(sizeof(struct node));
  q->i = x;
  q->next = n;
  return q;
}

struct node* free_list(struct node *p){
  struct node *r = p;
  struct node *n;
  while (p){
    n = p->next;
    free(p);
    p = n;
  }
  return r;
}

int main(){
  struct node *a = (struct node*)malloc(sizeof(struct node));
  a->i = 5;

  print_list(a);

  a = insert_front(37, a);
  a = insert_front(1, a);
  print_list(a);

  print_list(free_list(a));
}
