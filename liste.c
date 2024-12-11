#include <stdio.h>
#include <stdlib.h>
#include "liste.h"


List *init(){
    List *liste = malloc(sizeof(*liste));
    Element *e = malloc(sizeof(*e));
    if (e == NULL || liste == NULL) {
        exit(EXIT_FAILURE);
    }
    e->nombre = 0;
    e->precedent = NULL;
    e->suivant = NULL;
    liste->origine = e;
    return liste;
}

void append(List *l, int value){
    Element *i = l->origine;
    if(i->nombre == 0){
        i->nombre = value;
    }
    else{
        Element *e = malloc(sizeof(*e));
        if(e == NULL){
            exit(EXIT_FAILURE);
        }
        e->nombre = value;
        e->suivant = NULL;
        while (i->suivant != NULL)
        {
            i = i->suivant;
        }
        i->suivant = e;
        e->precedent = i;
    }
}

void delete(List *l){
    Element *e = l->origine;
    if(e->suivant == NULL){
        exit(EXIT_FAILURE);
    }
    while (e->suivant!= NULL){
        e = e->suivant;
    }
    Element *dernier = e->precedent;
    dernier->suivant = NULL;
    free(e);
}

int get(List *l, int index){
    Element *e = l->origine;
    if(index < 0){
        exit(EXIT_FAILURE);
    }
    for(int j = 0; j < index; j++){
        if(e->suivant == NULL){
            exit(EXIT_FAILURE);
        }
        e = e->suivant;
    }
    return e->nombre;
}

int len(List *l){
    Element *e = l->origine;
    int count = 0;
    while (e!= NULL)
    {
        count++;
        e = e->suivant;
    }
    return count;
}

void printList(List *l){
    Element *i = l->origine;
    while (i != NULL)
    {
        printf("%d -> ", i->nombre);
        i = i->suivant;
    }
    printf("NULL\n");
}