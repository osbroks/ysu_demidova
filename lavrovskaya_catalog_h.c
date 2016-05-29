#pragma once
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define LENGTH_FILE_NAME 255

typedef struct sCatalog {
    struct tm *Date;
    char *Name;
    unsigned int Size;
    struct sCatalog *Next_File;
} Catalog;

void addFile(Catalog **catalog);
void printList(Catalog **catalog);
void delFiles(Catalog **catalog);
void nameEntering(char *name);
