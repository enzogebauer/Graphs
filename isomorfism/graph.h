#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <list>

using namespace std;

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

static link createNewNode(vertex w, link next)
{
  link a = (link)malloc(sizeof(struct node));
  a->w = w;
  a->next = next;
  return a;
}

Graph createGraph(int V)
{
  Graph G = (Graph)malloc(sizeof(struct graph));
  G->V = V;
  G->A = 0;
  G->adj = (link *)malloc(V * sizeof(link));
  for (vertex v = 0; v < V; ++v)
  {
    G->adj[v] = NULL;
  }
  return G;
}

void insertGraph(Graph G, vertex v, vertex w)
{
  G->adj[v] = createNewNode(w, G->adj[v]);
  G->A++;
}

void printG(Graph G)
{
  for (vertex v = 0; v < G->V; v++)
  {
    printf("Vertex %c:", 'A' + v); // Print vertex label based on the index
    for (link a = G->adj[v]; a != NULL; a = a->next)
    {
      printf(" %c", 'A' + a->w); // Print connected vertices' labels based on the index
    }
    printf("\n");
  }
}

bool CompareVertex(Graph G1, Graph G2)
{
  int cont1 = 0;
  int cont2 = 0;

  for (vertex v = 0; v < G1->V; v++)
  {
    cont1++;
  }

  for (vertex v = 0; v < G2->V; v++)
  {
    cont2++;
  }

  if (cont1 == cont2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool CompareEdges(Graph G1, Graph G2)
{
  printf("G1->A = %d\n", G1->A);
  printf("G2->A = %d\n", G2->A);
  return G1->A == G2->A;
}

list<int> CompareDegree(Graph G1, Graph G2)
{
  list<int> degList1;
  list<int> degList2;
  int cont1 = 0;
  int cont2 = 0;
  for (vertex v = 0; v < G1->V; v++)
  {
    cont1 = 0;
    cont2 = 0;
    for (link a = G1->adj[v]; a != NULL; a = a->next)
    {
      cont1++;
      printf("cont1 = %d\n", cont1);
    }
    degList1.push_back(cont1);
    printf("Vertex %c do grafo1: cujo grau é %d\n", 'A' + v, cont1);
    for (link a = G2->adj[v]; a != NULL; a = a->next)
    {
      cont2++;
      printf("cont2 = %d\n", cont2);
    }
    degList2.push_back(cont2);
    printf("Vertex %c do grafo2: cujo grau é %d\n", 'A' + v, cont2);
    if (cont1 != cont2)
    {
      degList1.clear();
      return degList1;
    }
  }
  return degList1;
}

// bool CompareBijectivity(Graph G1, Graph G2, list<int> *degreeList)
// {
//   Graph mainArr[G1->A];
//   for (vertex v = 0; v < G1->V; v++)
//   {
//   }
// }
// Um Grafo de input e outro de comparação
// começa no primeiro nó do g1 e percorre pra achar um de mesmo grau no grau 2, achando compara suas adjacências se forem iguais passa pro próximo nó do g1 se não percorre pra achar outro de mesmo grau no g2, se não achar mais nenhum eles não são isomorfos se sim repete o processo

// for(int i=0; i<tam; i++){
//      vetG[v[i][j];
//  compara
// }

// v sendo um vetor int da posição de graus iguais
// i = linhas (graus iguais)
// j = colunas (outros graus iguais)
// matriz[i][j]
// matriz:
// 4 3 6 -> posições de graus iguais
// 5 1 2 -> outra posição de graus iguais