#include "graph.h"
#include "isomorfismRules.h"
#include "isomorfismRules.h"

// Grupo:
// Enzo Bacelar Conte Gebauer
// Maria Eduarda Lopes de Morais Brito
// Luiz Guilherme Guerreiro Carvalho

int main()
{
  FILE *file1 = fopen("input.txt", "r");
  FILE *file2 = fopen("input2.txt", "r");
  Graph G1, G2;
  createGraph(&file1, &G1);
  printGraph(&G1);
  createGraph(&file2, &G2);
  printGraph(&G2);
  fclose(file1);
  fclose(file2);
  int result;

  result = sameVertexN(&G1, &G2);
  if (result == 1)
  {
    printf("Os grafos possuem o mesmo numero de vertices\n");
  }
  else
  {
    printf("Os grafos não possuem o mesmo numero de vertices, portanto não são isomorfos\n");
    return 0;
  }
  result = sameEdgesN(&G1, &G2);
  if (result == 1)
  {
    printf("Os grafos possuem o mesmo numero de arestas\n");
  }
  else
  {
    printf("Os grafos não possuem o mesmo numero de arestas, portanto não são isomorfos\n");
    return 0;
  }
  result = equalVertex(&G1, &G2);
  if (result == 1)
  {
    printf("Os vertices de cada grafo tem um correspondente no outro grafo\n");
  }
  else
  {
    printf("Os vertices de cada grafo não tem os mesmos correspondentes no outro grafo, portanto não são isomorfos\n");
    return 0;
  }
  result = isIsomorfic(&G1, &G2);
  if (result == true)
  {
    printf("Os grafos são isomorfos, pois passaram no teste das bijeçōes\n");
  }
  else
  {
    printf("Os grafos não são isomorfos, pois nāo passaram no teste das bijeçōes\n");
  }

  return 0;
}
