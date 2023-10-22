#include "graph.h"
#include <limits.h>
#include <stdio.h>

// Function to find the Minimum Spanning Tree (MST) using the Prim's algorithm.
void primMST(Graph *g)
{
  if (g == NULL || g->V <= 0)
  {
    printf("Invalid graph input.\n");
    return;
  }

  int parent[g->V]; // Parent vertex in the MST.
  int key[g->V];    // Key of each vertex.
  int inMST[g->V];  // Indicates if the vertex is in the MST.

  // Initialization of keys, parents, and inMST.
  for (int i = 0; i < g->V; i++)
  {
    key[i] = INT_MAX;
    parent[i] = -1;
    inMST[i] = 0;
  }

  // The root of the MST will be the first vertex.
  key[0] = 0;

  for (int count = 0; count < g->V - 1; count++)
  {
    int u = -1;

    // Find the vertex with the minimum key that is not in the MST.
    for (int v = 0; v < g->V; v++)
    {
      if (!inMST[v] && (u == -1 || key[v] < key[u]))
      {
        u = v;
      }
    }

    inMST[u] = 1;

    // Update the keys of vertices adjacent to u.
    struct Node *node = g->root[u].adjList;
    while (node != NULL)
    {
      int v = node->w - g->root; // Get the index of the adjacent vertex.

      if (!inMST[v] && node->weight < key[v]) // Compare using node->weight
      {
        parent[v] = u;
        key[v] = node->weight; // Use node->weight as the edge weight.
      }

      node = node->next;
    }
  }

  printf("Minimum Spanning Tree (MST):\n");
  for (int i = 1; i < g->V; i++)
  {
    printf("Edge: %s - %s (Weight: %d)\n", g->root[i].label, g->root[parent[i]].label, key[i]);
  }
}
