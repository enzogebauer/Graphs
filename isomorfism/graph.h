#include "graphDefinition.h"
using namespace std;
int CountingVertex(FILE **file, Graph *g);
Node *alocateNewNode();
void insertGraphNode(FILE **file, Graph *g);
void adjacencyList(FILE *file, Graph *g, vertex *v);
void insertVertex(Graph *g, char *row, vertex *v);

void createGraph(FILE **file, Graph *g)
{
  if (!file)
  {
    printf("Erro ao ler o fileuivo.\n");
    exit(0);
  }

  g->A = 0;
  g->root = 0;
  g->V = 0;
  CountingVertex(file, g);
  insertGraphNode(file, g);
}

int CountingVertex(FILE **file, Graph *g)
{
  rewind(*file);
  int i, num = 0;

  char row[100];
  char *result;
  result = fgets(row, 100, *file);

  if (!result)
  {
    printf("Erro na leitura do cabeçalho.\n");
    return 0;
  }

  int rowSize = strlen(row);

  for (i = 0; i < (rowSize); i++)
  {
    if (isspace(row[i]))
    {
      num++;
    }
  }
  g->V = num;
  printf("Número de vértices: %d\n", g->V);

  return (g->V);
}

void insertGraphNode(FILE **file, Graph *g)
{
  g->root = (vertex *)malloc(g->V * sizeof(vertex));
  g->root = &g->root[0];
  rewind(*file);
  char row[100];
  char *result;
  result = fgets(row, 100, *file);
  int i;
  int flag = 0;
  char *t;

  for (i = 0; i < (g->V - 1); i++)
  {
    g->root[i].degrN = 0; /*zerando o número de graus e de arestas*/
    g->root[i].edgeN = 0;
    if (flag == 0)
    {
      t = strtok(row, " ");
      strcpy(g->root[i].label, t); // Inserindo em cada vertice o seu nome
      flag++;
    }
    else
    {
      t = strtok(NULL, " ");
      strcpy(g->root[i].label, t);
    }
  }
  t = strtok(NULL, "\n");
  strcpy(g->root[i].label, t);

  g->root[i].degrN = 0; // Todos os vertices iniciam com grau zero
  g->root[i].edgeN = 0;
  // Inserindo a lista de adjacencias
  adjacencyList(*file, g, g->root);
}

void adjacencyList(FILE *file, Graph *g, vertex *v)
{
  char row[100];
  char *result;
  int i = 0;
  while (!feof(file))
  {                                 // Lê uma linha (inclusive com o '\n')
    result = fgets(row, 100, file); // o 'fgets' lê até 99 caracteres ou até o '\n'
    if (result)
    { // Se foi possível ler
      // printf("Linha %d : %s", i, linha);
      insertVertex(g, row, &v[i++]); // Insere no vertice a sua adjc
    }
  }
  // printf("\n");
  g->A /= 2;
}
void insertVertex(Graph *g, char *row, vertex *v)
{
  char *t;
  int flag = 0, i;
  v->adjList = alocateNewNode();
  struct Node *node = (*v).adjList;

  node->w = v;

  for (i = 0; i < (g->V) - 1; i++)
  {
    if (flag == 0)
    {
      t = strtok(row, " ");
      if (strcmp(t, "1") == 0)
      {
        struct Node *newNode = alocateNewNode();
        newNode->w = &g->root[i];
        node->next = newNode;
        node = newNode;
        v->edgeN++;

        if (v != &g->root[i])
        {
          g->root[i].degrN++;
          g->A++;
        }
        else
        {
          g->root[i].degrN += 2;
          g->A += 2;
        }
      }
      flag++;
    }
    else
    {
      t = strtok(NULL, " ");
      if (strcmp(t, "1") == 0)
      {
        struct Node *newNode = alocateNewNode();
        newNode->w = &g->root[i];
        node->next = newNode;
        node = newNode;

        v->edgeN++;

        if (v != &g->root[i])
        {
          g->root[i].degrN++;
          g->A++;
        }
        else
        {
          g->root[i].degrN += 2;
          g->A += 2;
        }
      }
    }
  }

  t = strtok(NULL, "\n");
  if (strcmp(t, "1") == 0)
  {
    struct Node *newNode = alocateNewNode();
    newNode->w = &g->root[i];
    node->next = newNode;
    node = newNode;
    v->edgeN++;

    if (v != &g->root[i])
    {
      g->root[i].degrN++;
      g->A++;
    }
    else
    {
      g->root[i].degrN += 2;
      g->A += 2;
    }
  }
}
Node *alocateNewNode()
{
  struct Node *newNode;
  newNode = (Node *)malloc(sizeof(Node));
  return newNode;
}
void printGraph(Graph *g)
{
  int i = 0;
  printf("Numero total de arestas: %d\n", g->A);
  for (i = 0; i < g->V; i++)
  {
    vertex *aux = &g->root[i];
    struct Node *node = aux->adjList;
    printf("Vertice: %s\n", aux->label);
    while (node->next != NULL)
    {
      printf("%s -> %s | Num Grau: %d | Num Arestas: %d\n", g->root[i].label, node->next->w->label, g->root[i].degrN, g->root[i].edgeN);
      node = node->next;
    }
    printf("\n");
  }
}
