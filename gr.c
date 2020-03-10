#include "gr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

vertex* new_vertex(){
	vertex* gr = malloc(sizeof(vertex));
	if (!gr) {
		perror("failed to allocate mem for new vertex");
		exit(EXIT_FAILURE);
	}
  return gr;
}

void free_vertex(vertex* gr){
  free (gr);
}
