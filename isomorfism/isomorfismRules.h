#ifndef ISOMORFISMRULES_H
#define ISOMORFISMRULES_H
#include "graph.h"
#include <iostream>
#include "graphDefinition.h"
#include <stdbool.h>
#include "queue.h"

using namespace std;

// Verifica se os grafos fornecidos possuem o mesmo numero de vertices.
int sameVertexN(Graph *g1, Graph *g2);

// Verifica se os grafos fornecidos possuem o mesmo numero de arestas.
int sameEdgesN(Graph *g1, Graph *g2);

// Mapea o grafo retornando index referente a poisição d amatriz
int mappingVertex(vertex *v, Graph *g);

int inOrder(Graph *g, vertex *w, int start);

// Verifica se os Grafos tem vertices iguais entre si
int equalVertex(Graph *g1, Graph *g2);

// Verifica se um determiando vertice do GR1 possui os mesmos vizinhos que um determinado vertice no GR2.
// Verifica tambem se existe os mesmos caminhos em ambos.
bool isIsomorfic(Graph *g1, Graph *g2);

// *** Desenvolvendo as funções ***

int sameVertexN(Graph *g1, Graph *g2)
{
    if (g1->V == g2->V)
        return 1;
    return 0;
}

int sameEdgesN(Graph *g1, Graph *g2)
{
    if (g1->A == g2->A)
        return 1;
    return 0;
}

bool isIsomorfic(Graph *g1, Graph *g2)
{
    int neighborArr[g1->V];
    int neighborArr2[g1->V];
    memset(neighborArr, 0, sizeof(neighborArr)); // Insere em todas as posições do vetor o valor zero
    memset(neighborArr2, 0, sizeof(neighborArr2));
    int i, j, flag = 1;
    tp_fila queue1, queue2;
    inicializa_fila(&queue1);
    inicializa_fila(&queue2);
    int higherDgg = g1->root[0].degrN;
    int higherDgg_index = 0;

    for (j = 1; j < g1->V; j++)
    {
        if (g1->root[j].degrN > higherDgg)
        {
            higherDgg = g1->root[j].degrN;
            higherDgg_index = j;
        }
    }

    neighborArr[higherDgg_index] = 1;

    int value1[higherDgg_index];
    int value2[higherDgg_index];
    memset(value1, 0, sizeof(value1)); // Insere em todas as posições do vetor o valor zero
    memset(value2, 0, sizeof(value2)); // Insere em todas as posições do vetor o valor zero

    struct Node *aux = g1->root[higherDgg_index].adjList;

    j = 0;
    while (aux->next != NULL)
    {
        printf("Rotulo do vertice você deseja saber: %s\n", aux->w->label);
        value1[j++] = inOrder(g1, &g1->root[higherDgg_index], mappingVertex(aux->next->w, g1));
        aux = aux->next;
    }

    for (j = 0; j < higherDgg; j++)
    {
        printf("%i - ", value1[j]);
    }
    printf("start: %d | rotulo: %s\n", higherDgg_index, g1->root[higherDgg_index].label);

    sort(value1, value1 + higherDgg);

    int higherDgg2 = g2->root[0].degrN;
    higherDgg_index = 0;

    for (j = 1; j < g2->V; j++)
    {
        if (g2->root[j].degrN > higherDgg2)
        {
            higherDgg2 = g2->root[j].degrN;
            higherDgg_index = j;
        }
    }

    neighborArr2[higherDgg_index] = 1;

    aux = g2->root[higherDgg_index].adjList;

    j = 0;
    while (aux->next != NULL)
    {
        printf("Rotulo do vertice: %s\n", aux->w->label);
        value2[j++] = inOrder(g2, &g2->root[higherDgg_index], mappingVertex(aux->next->w, g2));
        aux = aux->next;
    }

    if (higherDgg != higherDgg2)
        return false;

    for (j = 0; j < higherDgg; j++)
    {
        printf("%i - ", value2[j]);
    }
    printf("start2: %d | rotulo: %s\n", higherDgg_index, g2->root[higherDgg_index].label);

    sort(value2, value2 + higherDgg);

    for (j = 0; j < higherDgg; j++)
    {
        if (value1[j] != value2[j])
            return false;
    }

    return true;
}

int mappingVertex(vertex *v, Graph *g)
{
    int i;
    for (i = 0; i < g->V; i++)
    {
        if (v == &g->root[i])
        {
            return i;
        }
    }
    return -1;
}

int inOrder(Graph *g, vertex *w, int start)
{
    tp_fila queue;
    inicializa_fila(&queue);
    insere_fila(&queue, start);

    int neighborArr[g->V];
    memset(neighborArr, 0, sizeof(neighborArr));

    int distance[g->V];
    memset(distance, 0, sizeof(distance));

    int count = 0;

    neighborArr[start] = 1;

    neighborArr[mappingVertex(w, g)] = 1;

    while (!fila_vazia(&queue))
    {
        int start1;
        remove_fila(&queue, &start1);
        struct Node *no_aux1;
        no_aux1 = g->root[start1].adjList;

        printf("--> s1: %d\n", start1);

        int p;
        for (p = 0; p < g->root[start1].edgeN; p++)
        {
            no_aux1 = no_aux1->next;
            int v = mappingVertex(no_aux1->w, g);
            printf("cont: %i | start: %d | P: %d\n", v, start1, p);

            if ((neighborArr[v]) && (count != 0) && (no_aux1->w == w))
            {
                return distance[start1];
            }
            if ((!neighborArr[v]))
            {
                distance[v] = 1 + distance[start1];
                insere_fila(&queue, v);
                neighborArr[v] = 1;
            }
        }

        count++;
    }
    return 0;
}

int equalVertex(Graph *g1, Graph *g2)
{
    int visitedArr[g2->V];
    memset(visitedArr, 0, sizeof(visitedArr));
    int i, j, flag = 0;
    for (i = 0; i < g1->V; i++)
    {
        flag = 1;
        for (j = 0; j < g2->V; j++)
        {
            if ((g1->root[i].degrN == g2->root[j].degrN) && (g1->root[i].edgeN == g2->root[j].edgeN) && (!visitedArr[j]))
            {
                visitedArr[j] = 1;
                flag = 0;
                break;
            }
        }
        if (flag)
            return 0;
    }
    return 1;
}
#endif