#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gr.h"

/* --------------------------------------
GLOBAL VARIABLES
---------------------------------------*/
#define NR_ARGS 2
vertex* gr;

/* --------------------------------------
PARSING
---------------------------------------*/
static void displayUsage (const char* appName){
  printf("Usage: %s\n", appName);
  exit(EXIT_FAILURE);
}
static int *parseArgs (long argc, char* argv[]){
  static int args[2];

  argv[1][strlen(argv[1])-1] ='\0';
  args[0] = atoi(argv[1]);
  args[1] = atoi(argv[2]);

  if (argc != NR_ARGS+1) {
    fprintf(stderr, "Invalid number of arguments: ");
    displayUsage(argv[0]);
  }
  if (args[0] < 2 || args[1] < 1) {
    fprintf(stderr, "NOTE: Arg1 > 2 and Arg2 > 1: ");
    displayUsage(argv[0]);
  }
  return args;
}
/* --------------------------------------
FUNCTIONS
---------------------------------------*/
/*
char DFS(char *f1){
  return f1;
}
*/
int main(int argc, char* argv[]){
  int *args = parseArgs(argc, argv);          //args é um array com os valores N e M (nr de alunos e nr de ralacoes)
  int notas[args[0]];
  int relacoes[args[1]];

  //TESTE DE CONCEITO
  for (int i = 0; i < args[0]; i++){
    scanf("%d", &notas[i]);
  }
  for (int i = 0; i < args[1]; i++){
    scanf("%d", &relacoes[i]);
  }

  for (int i = 0; i < args[0]; i++){
    printf("%d\n", notas[i]);
  }
  for (int i = 0; i < args[1]; i++){
    printf("%d\n", relacoes[i]);
  }

/*  gr = new_vertex();
  teste = DFS(argv[1]);
  free_vertex(gr); */
  return 0;
}
