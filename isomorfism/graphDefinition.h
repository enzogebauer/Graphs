#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <list>

#define col 4
#define lin 5

typedef struct node *link;
typedef struct graph *Graph;

struct vertex
{
  char label[20];
  int degrN;
  int edgeN;
  node *adjList;
};

struct graph
{
  int V;
  int A;
  link *adj;
};

struct node
{
  vertex w;
  link next;
};
