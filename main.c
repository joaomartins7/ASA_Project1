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
  int notas[args[0]];                         //lista simples
  int relacoes[args[0]][args[0]];             //matriz de adjacencias
  int aluno, amigo;

  //TESTE DE CONCEITO
  for (int i = 0; i < args[0]; i++){
    scanf("%d", &notas[i]);
  }
  for (int i = 0; i < args[0]; i++){
    for (int j = 0; j < args[0]; j++){ relacoes[i][j] = 0; }
  }
  for (int i = 0; i < args[1]; i++) {
    scanf("%d %d", &aluno, &amigo);
    relacoes[aluno-1][amigo-1] = 1;
  }

  graph* graph = new_graph(6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 6);
    add_edge(graph, 5, 1);
    add_edge(graph, 5, 6);

    printGraph(graph);

/*  gr = new_vertex();
  teste = DFS(argv[1]);
  free_vertex(gr); */
  return 0;
}
