#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    char vet[200];
    int topo;
} TPilha;

void create(TPilha *p) {
    p->topo = -1;
}

void destroy(TPilha *p) {
    p->topo = -1;
}

int isEmpty(TPilha *p) {
    return p->topo == -1;
}

int isFull(TPilha *p) {
    return p->topo == 199;
}

void push(TPilha *p, char x) {
    if (isFull(p)) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

char pop(TPilha *p) {
    if (isEmpty(p)) {
        puts("underflow");
        abort();
    }
    char aux = p->vet[p->topo];
    p->topo--;
    return aux;
}

// Reverses the words separately of a string
char reverse(char *arr) {
    char tam = strlen(arr);
    TPilha p;
    create(&p);
    int c1 = 0, c2 = 0;
    while (c1 <= tam) {
        if (arr[c1] == ' ' || arr[c1] == '\0') {
            while (isEmpty(&p) != 1) {
                arr[c2] = pop(&p);
                c2++;
            }
            if (arr[c1] == ' ') {
                arr[c2] = ' ';
                c2++;
            }
        } else {
            push(&p, arr[c1]);
        }
        c1++;
    }
    arr[c2] = '\0'; 
    printf("%s\n", arr);
}

int main(void) {
    char arr[200];
    printf("Insert a phrase to see it reversed: ");
    fgets(arr, sizeof(arr), stdin);
    arr[strcspn(arr, "\n")] = '\0'; 
    reverse(arr);
    return 0;
}