#include "graph.h"
#include <limits.h>
#include <stdio.h>

void dijkstra(Graph *g, int src)
{
  if (g == NULL || g->V <= 0)
  {
    printf("Invalid graph input.\n");
    return;
  }

  int dist[g->V];    // Array para armazenar as distâncias mais curtas.
  int visited[g->V]; // Array para marcar os vértices visitados.

  // Inicialização das distâncias e dos vértices visitados.
  for (int i = 0; i < g->V; i++)
  {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }

  // A distância do vértice de origem para ele mesmo é sempre 0.
  dist[src] = 0;

  // Encontrando as distâncias mais curtas.
  for (int count = 0; count < g->V - 1; count++)
  {
    int u = -1;

    // Encontra o vértice com a menor distância que ainda não foi visitado.
    for (int v = 0; v < g->V; v++)
    {
      if (!visited[v] && (u == -1 || dist[v] < dist[u]))
      {
        u = v;
      }
    }

    visited[u] = 1;

    // Atualiza as distâncias dos vértices adjacentes ao vértice atual.
    struct Node *node = g->root[u].adjList;
    while (node != NULL)
    {
      int v = node->w - g->root; // Supondo que node->w seja um ponteiro para vertex e g->root seja um ponteiro para o primeiro vértice no grafo.
      int weight = node->weight;

      if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
      }

      node = node->next;
    }
  }

  // Imprime as distâncias mais curtas a partir do vértice de origem.
  printf("Menor caminho encontrado pelo algoritmo de Dijkstra:\n");
  printf("Distâncias mais curtas a partir do vértice %s:\n", g->root[src].label);
  for (int i = 0; i < g->V; i++)
  {
    printf("Para o vértice %s: %d\n", g->root[i].label, dist[i]);
  }
}

int readSourceVertex()
{
  printf("Digite o caractere MINUSCULO que representa o vértice de origem e lhe mostraremos todos os caminhos mais curtos desse vértice escolhido para os demais vértices do grafo.\n");
  char option;
  scanf("%c", &option);
  int return_value = (option - 'a') % 26;

  switch (option)
  {
  case 'a':
    // Código para a opção 'a'
    printf("Opção 'a' escolhida.\n");
    break;
  case 'b':
    // Código para a opção 'b'
    printf("Opção 'b' escolhida.\n");
    break;
  case 'c':
    // Código para a opção 'c'
    printf("Opção 'c' escolhida.\n");
    break;

  // Adicione mais casos para outras letras minúsculas
  case 'd':
    printf("Opção 'd' escolhida.\n");
    break;
  case 'e':
    printf("Opção 'e' escolhida.\n");
    break;
  case 'f':
    printf("Opção 'f' escolhida.\n");
    break;
  case 'g':
    printf("Opção 'g' escolhida.\n");
    break;
  case 'h':
    printf("Opção 'h' escolhida.\n");
    break;
  case 'i':
    printf("Opção 'i' escolhida.\n");
    break;
  case 'j':
    printf("Opção 'j' escolhida.\n");
    break;
  case 'k':
    printf("Opção 'k' escolhida.\n");
    break;
  case 'l':
    printf("Opção 'l' escolhida.\n");
    break;
  case 'm':
    printf("Opção 'm' escolhida.\n");
    break;
  case 'n':
    printf("Opção 'n' escolhida.\n");
    break;
  case 'o':
    printf("Opção 'o' escolhida.\n");
    break;
  case 'p':
    printf("Opção 'p' escolhida.\n");
    break;
  case 'q':
    printf("Opção 'q' escolhida.\n");
    break;
  case 'r':
    printf("Opção 'r' escolhida.\n");
    break;
  case 's':
    printf("Opção 's' escolhida.\n");
    break;
  case 't':
    printf("Opção 't' escolhida.\n");
    break;
  case 'u':
    printf("Opção 'u' escolhida.\n");
    break;
  case 'v':
    printf("Opção 'v' escolhida.\n");
    break;
  case 'w':
    printf("Opção 'w' escolhida.\n");
    break;
  case 'x':
    printf("Opção 'x' escolhida.\n");
    break;
  case 'y':
    printf("Opção 'y' escolhida.\n");
    break;
  case 'z':
    printf("Opção 'z' escolhida.\n");
    break;

  // Código para a opção padrão (outras letras)
  default:
    printf("Opção inválida.\n");
    break;
  }

  return return_value;
}