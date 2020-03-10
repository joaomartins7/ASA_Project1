#ifndef GR_H
#define GR_H
#include <stdio.h>
#include <stdbool.h>

typedef struct vertex {
  bool state;
  int value;

} vertex;

vertex* new_vertex();
void free_vertex(vertex* gr);
void create(vertex* gr, bool state, int value);
void delete(vertex* gr);
void dfs_visit();
void dfs(vertex* gr);


#endif
