#ifndef GRAPHDEFINITION_H
#define GRAPHDEFINITION_H

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
  int weight;
};
#endif