#include "graph.h"
#include "prim.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Grupo:
// Enzo Bacelar Conte Gebauer
// Eduardo Nery Campos Guimarães
// Henrique Barreto Sá

int main()
{
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

  printf("\nMST (Árvore Geradora Mínima) encontrada pelo algoritmo de Prim:\n");
  primMST(&g);

  return 0;
}