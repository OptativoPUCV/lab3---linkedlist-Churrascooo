#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList()
{
  List *nuevo = (List*)malloc(sizeof(List));
  nuevo->head = NULL;
  nuevo->tail = NULL;
  nuevo->current = NULL;
  return nuevo;
}

void * firstList(List * list)
{
  list->current = list->head;
  if (list->head == NULL)
  {
    return NULL;
  }
  return list->current->data;
}

void * nextList(List * list)
{
  if (list->current == NULL)
  {
    return 0;
  }
  if (list->current->next == NULL)
  {
    return 0;
  }
  
  list->current = list->current->next;
  
  return list->current->data;
}

void * lastList(List * list)
{
  list->current = list->tail;
  if (list->tail == NULL)
  {
    return NULL;
  }
  return list->current->data;
}

void * prevList(List * list)
{
  if (list->current == NULL)
  {
    return 0;
  }
  if (list->current->prev == NULL)
  {
    return 0;
  }
  list->current = list->current->prev;
  
  return list->current->data;
}

void pushFront(List * list, void * data)
{
  Node *nuevo = createNode(data);
  if (list->head == NULL)
  {
    list->head = nuevo;
    list->tail = nuevo;
  }
  else
  {
    nuevo->next = list->head;
    list->head->prev = nuevo;
    list->head = nuevo;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data)
{
  Node *nuevo = createNode(data);
  if (list->current == NULL)
  {
    list->head = nuevo;
    list->tail = nuevo;
  }
  else
  {
    nuevo->next = list->current->prev;
    nuevo->prev = list->current;
    list->current->prev = nuevo;
    if (nuevo->next == NULL)
    {
      list->tail = nuevo;
    }
    else
    {
      nuevo->next->prev = nuevo;
    }
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}