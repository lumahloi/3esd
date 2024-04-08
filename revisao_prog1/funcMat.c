#include "funcMat.h"
int divisaoInteira(int x, int y, int *quoc, int *resto){
  if (y == 0){
    if (x == 0){
      return -1;
    }
    else {
      return 0;
    }
  }
  else {
    *quoc = x/y;
    *resto = x%y;
    return 1;
  }
}