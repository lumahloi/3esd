#include "PONTO.h"
#include "QUADRADO.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct quadrado {
  double lado;
  Ponto* vie;
};

Quadrado* quad_cria(double lado, double x, double y){
  Quadrado* q = (Quadrado*)malloc(sizeof(Quadrado));
  q->lado = lado;
  q->vie = pto_cria(x, y);
}

void quad_libera(Quadrado* q){
  pto_libera(q->vie); 
  free(q);
}

char* quad_getQuadrado(Quadrado* q){
  char* pt = (char*)malloc(sizeof(*q)+8);
  sprintf(pt, "Lado: %.2f, vértice inferior esquerdo: %s", q->lado, pto_getPonto(q->vie));
  return pt;
}

void quad_exibe(Quadrado* q){
  printf("Lado: %.2f, vértice inferior esquerdo: %s", q->lado, pto_getPonto(q->vie));
}

Quadrado* quad_clona(Quadrado* q){
  Quadrado* qNovo = (Quadrado*)malloc(sizeof(Quadrado));
  qNovo->lado = q->lado;
  qNovo->vie = pto_clona(q->vie);
}

void quad_acessa(Quadrado* q, float* x, float* y){
  float a, b;
  pto_acessa(q->vie, &a, &b);
  Ponto* ponto = pto_cria(a, b);
  ponto = pto_clona(q->vie);
  *x = ponto->x;
  *y = ponto->y;
}

void quad_atribui(Quadrado* q, float x, float y){
  Ponto* p = pto_cria(x, y);
  q->vie = p;
}

int quadCompara(Quadrado* q1, Quadrado* q2){
  float q1_area = q1->lado * q1->lado;
  float q2_area = q2->lado * q2->lado;

  if(q1_area == q2_area){
    return 0;
  } else {
    if(q1_area > q2_area){
      return 1;
    } else {
      return -1;
    }
  }
}

char* getVSE(Quadrado* q){
  double x, y;
  float qx, qy;

  pto_acessa(q->vie, &qx, &qy);

  x = qx;
  y = qy + q->lado;
  
  return pto_getPonto(pto_cria(x, y));
}

char* getVSD(Quadrado* q){
  double x, y;
  float qx, qy;

  pto_acessa(q->vie, &qx, &qy);

  x = qx + q->lado;
  y = qy + q->lado;

  return pto_getPonto(pto_cria(x, y));
}

char* getVID(Quadrado* q){
  double x, y;
  float qx, qy;

  pto_acessa(q->vie, &qx, &qy);

  x = qx + q->lado;
  y = qy;

  return pto_getPonto(pto_cria(x, y));
}

char* getVIE(Quadrado* q){
  return pto_getPonto(q->vie);
}