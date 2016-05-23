#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int Data;
    struct list *Next;
    struct list *Prev;
}List;

void addElem(List **, int *);
void printList(List **);
List *endOfList(List **);
void doIt(List **, List **);
