#include "flooding.h"
#include "graph.h"

// Grupo:
// Enzo Bacelar Conte Gebauer
// Maria Eduarda Lopes de Morais Brito
// Luiz Guilherme Guerreiro Carvalho

int main()
{
  FILE *file1 = fopen("input.txt", "r");
  Graph G1;
  createGraph(&file1, &G1);
  printf("Number of connections: %d\n", countingConections(&G1));
  return 0;
}
