#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <list>

struct vertex
{
  char label[20];
  int degrN;
  int edgeN;
  struct Node *adjList;
};

struct Graph
{
  int V;
  int A;
  vertex *root;
};

struct Node
{
  vertex *w;
  Node *next;
};
