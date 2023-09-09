#include "graph.h"

using namespace std;
// Grupo:
// Enzo Bacelar Conte Gebauer
// Maria Eduarda Lopes de Morais Brito
// Luiz Guilherme Guerreiro Carvalho

/*
comparar vertices e arestas
coletar o grau do grafo e retornar o vetor de graus
ordena o vetor e depois comparar o outro vetor de graus
se isso tiver ok continue se nao aborte o programa
depois disso vai testar o isomorfismo a partir de umna forca bruta por bijecoes
*/

int main()
{
  char graphInput1[col][lin];
  char graphInput2[col][lin];
  FILE *file1 = fopen("input.txt", "r");
  FILE *file2 = fopen("input2.txt", "r");
  Graph G1, G2;
  createGraph(&file1, G1);
  createGraph(&file2, G2);
  fclose(file1);
  fclose(file2);

  bool SameVertexN = CompareVertex(G1, G2);
  if (SameVertexN == false)
  {
    printf("Os grafos nāo sāo isomórficos, pois tem números de vértices distintos\n");
    return 0;
  }
  else
  {
    printf("Os grafos podem ser isomórficos, pois tem números de vértices iguais\n");
  }
  bool SameEdgesN = CompareEdges(G1, G2);
  if (SameEdgesN == false)
  {
    printf("Os grafos nāo sāo isomórficos, pois tem números de arestas distintos\n");
    return 0;
  }
  else
  {
    printf("Os grafos podem ser isomórficos, pois tem números de arestas iguais\n");
  }
  list<int> degreeList = CompareDegree(G1, G2);
  if (degreeList.empty())
  {
    printf("Os grafos nāo sāo isomórficos, pois tem graus distintos\n");
  }
  else
  {
    printf("Os grafos podem ser isomórficos, pois tem graus iguais\n");
  }
  degreeList.sort();
  // CompareBijectivity(G1, G2, &degreeList);
  return 0;
}
