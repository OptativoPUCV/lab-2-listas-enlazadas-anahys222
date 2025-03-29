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

List * createList() {
    List* nuevaList = (List*)malloc(sizeof(List));
    if (nuevaList == NULL) return NULL;
    nuevaList ->head = NULL;
    nuevaList ->tail = NULL;
    nuevaList ->current = NULL;
    return nuevaList;
}

void * firstList(List * list) {
    if(list ==  NULL || list->head ==NULL) return NULL;
    list->current = list->head;
    return (void*)(list->current->data);
}

void * nextList(List * list) {
    if(list ==  NULL || list->current ==NULL || list->current->next ==NULL) return NULL;
    list->current = list->current->next;
    return (void *)(list->current->data);
}

void * lastList(List * list) {
    if(list ==  NULL || list->tail ==NULL) return NULL;
    list->current = list->tail;

    return (void*)(list->current->data);
}

void * prevList(List * list) {
    if(list ==  NULL || list->current ==NULL|| list->current == list->head) return NULL;
    Node* temp = list->head;
    while(temp->next != list->current){
        temp = temp->next;
    }
    list->current= temp;
    
    return (void *)(list->current->data);
}

void pushFront(List * list, void * data) {
    if(list == NULL) return NULL;

    Node* nuevoNodo = createNode(data);
    if(nuevoNodo == NULL) return NULL;

    nuevoNodo->next = list->head;
    list->head = nuevoNodo;

    if(list->tail == NULL){
        list->tail = nuevoNodo;
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
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