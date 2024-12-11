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
void append(List *l, int value);
void delete(List *l);
void printList(List *l);
void main();
int get(List *l, int index);
int len(List *l);
#endif