#include <stdio.h>
#include <stdlib.h>
#include "funcHorario.h"
/*
  Faça um programa que leia o tempo de treino (em minutos) de 10 atletas, mostrando a cada um, o tempo de treino no formato hh:mm. (utilize a função do item a).
  No final deve ser exibido o maior tempo de treino e quantos atletas o fizeram
*/

struct atl {
  int num;
  int tempo, h, m;
};

typedef struct atl tAtleta;

void exibeMaiorTempoMedio(tAtleta vTempoAtl[], int n, float media);
void exibirAtletas(tAtleta v[], int n, int x);
tAtleta* criarVetor(tAtleta v[], int at, int treino, int *qntd);

int main() {
  int i, soma=0, atletas, treino=-1, qntd=0;
  tAtleta *vAtl, *v2;
  float media;

  printf("Quantos atletas? ");
  scanf("%d", &atletas);

  /* alocação de área para guardar os dados dos atletas */
  vAtl = (tAtleta*)malloc(atletas*sizeof(tAtleta));

  if (!vAtl){
    printf("\nErro na alocação de memória");
    exit(1);
  } 
  
  for (i = 0; i < atletas; i++){
    printf("Digite o tempo de treino do atleta %d: ", i+1);
    scanf("%d", &(vAtl+i)->tempo); //ou &vAtl[i].tempo
    vAtl[i].num = i+1;
    horario(vAtl[i].tempo, &vAtl[i].h, &vAtl[i].m);
    
    printf("Atleta: %d - %02d:%02dh\n", vAtl[i].num, vAtl[i].h, vAtl[i].m);
   
    soma += vAtl[i].tempo;

    if(vAtl[i].tempo > treino){
      treino = vAtl[i].tempo;
    }
  }
  
  media = soma/atletas;

  printf("\nExibindo todos os atletas inseridos:");
  exibirAtletas(vAtl, atletas, 0);
  
  v2 = criarVetor(vAtl, atletas, treino, &qntd);
  printf("\n\nExibindo atletas com tempo de treino igual ao maior tempo de treino: ");
  
  exibirAtletas(v2, qntd, 1);
  //exibeMaiorTempoMedio(vAtl, atletas, media);
  
  return 0;
}

tAtleta* criarVetor(tAtleta v[], int at, int treino, int *qntd){
  //construa uma função que receba o vetor de atletas, a qtdade de elementos e o maior tempo. A função deve  retornar um novo vetor, com tamanho exato necessário , para guardar os atletas com mesmo tempo que o maior tempo
  int i, j=0;
  tAtleta *v2;
  
  for(i=0; i<at; i++){
    if(v[i].tempo == treino){
      (*qntd)++;
    }
  }
  
  v2 = (tAtleta*)malloc((*qntd)*sizeof(tAtleta));
  
  if(!v2){
    printf("Erro na alocação de memória");
    exit(1);
  }

  for(i=0; i<at; i++){
    if(v[i].tempo == treino){
      v2[j].num = i+1;
      j++;
    }
  }
  return v2;
}

void exibirAtletas(tAtleta v[], int n, int x){
  //construa uma função que receba um vetor de atletas e a qtdade de elementos e exiba os atletas
  int i;

  for(i=0; i<n; i++){
    if(x==0){
      printf("\nAtleta: %d - %02d:%02dh", v[i].num, v[i].h, v[i].m);
    }
    else{
      printf("\nAtleta %d", v[i].num);
    }
  }
}

void exibeMaiorTempoMedio(tAtleta vTempoAtl[], int n, float media){
  int i;
  printf("\nAtleta com treino maior que a media: \n");
  
  for (i = 0; i < n; i++){
    if (vTempoAtl[i].tempo > media){
      printf("Atleta: %d - %02d:%02dh\n", vTempoAtl[i].num, vTempoAtl[i].h, vTempoAtl[i].m);
    }

    /*
    if((mAtl > mMed)&&(hAtl < hMed)){
      printf("\nAtleta com minuto maior que o minuto médio e hora menor que a hora média: \n");
      printf("Atleta: %d - %02d:%02dh\n", i+1, hAtl, mAtl);
    }
    */
  }
}