#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
  char nome[20];
  int num_camp;
  int **matriz;
} TAtleta;

void preencherAtleta(TAtleta *vetor, int pos);
void exibirVetor(TAtleta *vetor, int tam);
void filtrarAtletas(TAtleta* vetor, TAtleta** vetorFiltr, int tam, char letra, int *qt);

int main() {
  int qntd, i, qtFiltro;
  char letra;
  TAtleta* vAtlFiltro = NULL;

  printf("\nInsira o numero de atletas de um clube: ");
  scanf("%d", &qntd);

  TAtleta vAtleta[qntd];

  for(i = 0; i < qntd; i++){
    preencherAtleta(vAtleta, i);
  }

  exibirVetor(vAtleta, qntd);

  printf("\n\nInsira uma letra para filtrar os atletas: ");
  scanf(" %c", &letra);

  filtrarAtletas(vAtleta, &vAtlFiltro, qntd, toupper(letra), &qtFiltro);

  exibirVetor(vAtlFiltro, qtFiltro);

  return 0;
}

void preencherAtleta(TAtleta *vetor, int pos){
  TAtleta item;
  int j, k;

  printf("\t\t\nAtleta %d\nInsira o nome: ", pos+1);
  scanf("%s", item.nome);

  printf("Insira o numero de campeonatos: ");
  scanf("%d", &item.num_camp);

  //alocação de memória para 2 linhas
  item.matriz = malloc(2 * sizeof(int *));

  //alocação de memória para colunas = num_camp
  for(j = 0; j < 2; j++) {
      item.matriz[j] = malloc(item.num_camp * sizeof(int));
  }

  for(k = 0; k < item.num_camp; k++){
    printf("Campeonato %d - Insira a pontuação: ", k+1);
    scanf("%d", &item.matriz[1][k]);
  }

  vetor[pos] = item;
}

void exibirVetor(TAtleta *vetor, int tam){
  int i, j, k;

  for(i = 0; i < tam; i++){
    printf("\n\n\t\tAtleta %d\nNome: %s\nNumero de campeonatos: %d\nPontuação: ", i+1, vetor[i].nome, vetor[i].num_camp);
    for(j = 0, k = vetor[i].num_camp - (vetor[i].num_camp - 1); j < vetor[i].num_camp; j++, k++){
      printf("\n\tCampeonato %d -> %d", k, vetor[i].matriz[1][j]);
    }
  }
}

void filtrarAtletas(TAtleta* vetor, TAtleta** vetorFiltr, int tam, char letra, int *qt){
  TAtleta item;
  int i, count = 0;

  *vetorFiltr = (TAtleta*) malloc(sizeof(TAtleta));

  for(i = 0; i < tam; i++){
    if(toupper(vetor[i].nome[0]) == letra){
      if (count > 0) {
        *vetorFiltr = (TAtleta*) realloc(*vetorFiltr, (count + 1) * sizeof(TAtleta));
      }

      strcpy(item.nome, vetor[i].nome);
      item.num_camp = vetor[i].num_camp;
      item.matriz = vetor[i].matriz;
      (*vetorFiltr)[count] = item;
      count++;
    }
  }
  *qt = count;
}
