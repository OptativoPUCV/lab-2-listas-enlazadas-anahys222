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
    if(list == NULL) return;
    Node* nuevoNodo = createNode(data);

    if(nuevoNodo == NULL) return;
    
    if(list->head == NULL){
        list->tail = nuevoNodo;
    }
    nuevoNodo->next = list->head;
    list->head = nuevoNodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    if (!list || !list->current) return;

    Node* nuevoNodo = createNode(data);
    if (!nuevoNodo) return;

    nuevoNodo->next = list->current->next;
    nuevoNodo->prev = list->current;
    if (list->current->next){
        list->current->next->prev = nuevoNodo;
    }
    list->current->next =nuevoNodo;

    if (list->current == list->tail) list->tail = nuevoNodo;
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
    if(!list || !list->current ) return NULL;
    Node* temp = list->current;

    void* eliminarData= malloc(sizeof(int));
    if(!eliminarData) return NULL;
    
    *(int *)eliminarData = *(int*)temp->data;

    if(list->current == list->head){
        list->head = list->head->next;}
        if(list->head) list->head->prev = NULL;

        if(list->current == list->tail) list->tail=NULL;
    else{
        Node* prev = list->current->prev;
        prev->next= list->current->next;
        if(list->current->next){
            list->current->next->prev = prev;
        }else{
            list->tail = prev;
        }
    }
    list->current = list->current->next;
    free(temp);
    return eliminarData;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}