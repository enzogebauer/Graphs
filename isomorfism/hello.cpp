#include "graph.h"

using namespace std;
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

  return 0;
}
