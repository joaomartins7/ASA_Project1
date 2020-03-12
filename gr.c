#include "gr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


vertex* new_vertex(int n){
	vertex* vr = malloc(sizeof(vertex));

	if (!vr) {
		perror("failed to allocate mem for new vertex");
		exit(EXIT_FAILURE);
	}

	vr->state = 0;
	vr->value = n;
	vr->next = NULL;

  return vr;
}

void free_vertex(vertex* vr){
  free (vr);
}

graph* new_graph(int vertices){
	graph* gr = malloc(sizeof(graph));

	if (!gr) {
		perror("failed to allocate mem for new graph");
		exit(EXIT_FAILURE);
	}

	gr->num_vertices = vertices;
	gr->adj_lists = malloc(vertices * sizeof(vertex));
	for (int i = 0; i < vertices; i++) {gr->adj_lists[i] = NULL;}

  return gr;
}

void add_edge(graph* gr, int src, int dest) {
	vertex* vr = new_vertex(dest);
	vr->next = gr->adj_lists[src];
	gr->adj_lists[src] = vr;

	vr = new_vertex(src);
	vr->next = gr->adj_lists[dest];
	gr->adj_lists[dest] = vr;

}

void printGraph(graph* gr)
{
    int v;
    for (v = 0; v < gr->num_vertices; v++)
    {
        vertex* temp = gr->adj_lists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}
