#include "graph.h"
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grupo:
// Enzo Bacelar Conte Gebauer
// Eduardo Nery Campos Guimarães
// Henrique Barreto Sá

int main()
{
  srand(time(NULL)); // Inicializa a semente para gerar números aleatórios.

  FILE *input = fopen("input.txt", "r");

  if (!input)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  Graph g;
  createGraph(&input, &g);
  fclose(input);

  printf("Grafo original:\n");
  printGraph(&g);
  int source = readSourceVertex();
  printf("\nOrigem para Dijkstra: %s\n", g.root[source].label);
  printf("Índice da origem: %d\n", source);
  dijkstra(&g, source);

  return 0;
}
