#ifndef H_LISTE

#define H_LISTE

typedef struct Element Element;

struct Element {
    int nombre;
    Element *suivant;
    Element *precedent;
};

typedef struct List List;

struct List {
    Element *origine;
};

List *init();
void append(List *l, int nvNombre);
void delete(List *l);
void printList(List *l);
void main();
#endif