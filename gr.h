#ifndef GR_H
#define GR_H
#include <stdio.h>
#include <stdbool.h>

typedef struct vertex {
  bool state;
  int value;
  struct vertex* next;

} vertex;

typedef struct graph {
  int num_vertices;
  struct vertex** adj_lists;
} graph;


vertex* new_vertex(int n);
void free_vertex(vertex* gr);

graph* new_graph(int vertices);
void printGraph(graph* graph);
void add_edge(graph* gr, int src, int dest);


#endif
