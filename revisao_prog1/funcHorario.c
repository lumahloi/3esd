#include "funcHorario.h"
#include "funcMat.h"

void horario(int tempoMin, int *hora, int *minuto){
  divisaoInteira(tempoMin, 60, hora, minuto);
}