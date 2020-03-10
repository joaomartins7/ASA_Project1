#include <stdio.h>
#include <stdlib.h> 
#include "gr.h"

/* --------------------------------------
GLOBAL VARIABLES
---------------------------------------*/
#define NR_ARGS 0
vertex* gr;

static void displayUsage (const char* appName){
    printf("Usage: %s\n", appName);
    exit(EXIT_FAILURE);
}
static void parseArgs (long argc, char* const argv[]){
    if (argc != NR_ARGS+1) {
        fprintf(stderr, "Invalid number of arguments: ");
        displayUsage(argv[0]);
    }
}

int main(int argc, char* argv[]){
  parseArgs(argc, argv);

  printf("Esta tudo bem e ... ");
  gr = new_vertex();
  printf("nao morreu\n");

//////////////////////////////
  char nome[100];
  printf("Escreve o nome: ");
  scanf("%s", nome);

  printf("Adeus %s.\n", nome);
/////////////////////////////

  free_vertex(gr);
  return 0;
}
