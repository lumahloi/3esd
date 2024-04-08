#include "PONTO.h"
#include <stdio.h>
#include <string.h>

int main (){
  int x = -2;
  int y = -6;
  Ponto* p1 = pto_cria(x, y);

  int z = 8;
  int a = 3;
  Ponto* p2 = pto_cria(z, a);

  //quadrantes:
  printf("%d", pto_quadrante(p1));

  //soma entre pontos:
  Ponto* soma = pto_somarPts(p1, p2);
  pto_exibe(soma);

  //deslocar X:
  deslocaX(p1, 2);
  pto_exibe(p1);

  //deslocar Y:
  deslocaY(p1, 8);
  pto_exibe(p1);
  
  
  return 0;
}