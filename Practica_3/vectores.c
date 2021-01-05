/***************************************
Practica numero: 3
Tema: Yacc básico
Opción: Calculadora para Vectores
	con tabla de simbolos.
Fecha: 01/01/2021
Grupo: 3CM7
Materia: Compiladores
****************************************/

#include "vectores.h"
#include "hoc.h"
#include  "y.tab.h"

Vector *creaVector(int n, double dato){
    Vector *vec;
    int i;
    vec=(Vector *)malloc(sizeof(Vector));
    vec->n = n;
    vec->vec = (double *)malloc(sizeof(double)*n);
    vec->vec[0] = dato;
    return vec;
}
void imprimeVector(Vector *v){
    int i;
    for(i=0; i< v->n; i++)
        printf("%.2f ", v->vec[i]);
    printf("\n");
}
Vector *copiaVector(Vector *v){
    int i;
    Vector *copy=creaVector(v->n, 0);
    for(i = 0; i< v->n; i++)
        copy->vec[i]=v->vec[i];
    return copy;
}
Vector *sumaVector(Vector *a, Vector *b){
    Vector *c;
    int i;
    c=creaVector(a->n, 0);
    for(i=0; i< a->n;i++)
        c->vec[i]=a->vec[i]+b->vec[i];
    return c;
}
Vector *restaVector(Vector *a, Vector *b){
    Vector *c;
    int i;
    c=creaVector(a->n, 0);
    for(i=0; i< a->n;i++)
        c->vec[i]=a->vec[i]-b->vec[i];
    return c;
}
Vector *unirVectores(Vector *a, Vector *b){
    Vector *c;
    int i, j;
    int len = a->n + b->n;
    c = creaVector(len, 0);
    for(i = 0; i < a->n; i++){
        c->vec[i] = a->vec[i];
    }
    for(j = i;j < len; j++){
        c->vec[j] = b->vec[j - i];
    }
    return c;
}

double productoPunto(Vector *a, Vector *b){
    int i, len;
    double res = 0;
    len = a->n > b->n ? b->n : a->n;
    for(i = 0; i < len; i++){
        res += a->vec[i] * b->vec[i];
    }
    return res;
}
Vector *productoCruz(Vector *a, Vector *b){
    Vector *c;
    c = creaVector(3, 0);
    c->vec[0] = a->vec[1] * b->vec[2] - b->vec[1] * a->vec[2];
    c->vec[1] = a->vec[2] * b->vec[0] - b->vec[2] * a->vec[0];
    c->vec[2] = a->vec[0] * b->vec[1] - b->vec[0] * a->vec[1];
    return c;
}
Vector *productoEscalar(double a, Vector *b){
    Vector *c;
    int i;
    c = creaVector(b->n, 0);
    for(i = 0; i < b->n; i++){
        c->vec[i] = a*b->vec[i];
    }
    return c;
}
double magnitud(Vector *a){
    double res = 0;
    int i;
    for(i = 0; i < a->n; i++){
        res += a->vec[i] * a->vec[i];
    }
    return sqrt(res);
}
