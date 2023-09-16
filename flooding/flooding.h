#ifndef flooding_h
#define flooding_h
#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int maping(vertex *v, Graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        if (v == &g->root[i])
        {
            return i;
        }
    }
}

void flooding(Graph *g, int *visited, int start)
{
    tp_fila queue;
    visited[start] = 1;
    insere_fila(&queue, start);

    while (!fila_vazia(&queue))
    {
        int current;
        remove_fila(&queue, &current);
        Node *neighbor = g->root[current].adjList;
        for (int i = 0; i < g->root[current].edgeN; i++)
        {
            neighbor = neighbor->next;
            int v = maping(neighbor->w, g);
            if (!visited[v])
            {
                visited[v] = 1;
                insere_fila(&queue, v);
            }
            neighbor = neighbor->next;
        }
    }
}

int countingConections(Graph *g)
{
    int i, count = 0;
    int visited[g->V];
    memset(visited, 0, sizeof(visited));
    for (i = 0; i < g->V; i++)
    {
        if (!visited[i])
            flooding(g, visited, i);
        count++;
    }
    return count;
}

#endif