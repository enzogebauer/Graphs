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
  if (file1 == NULL)
  {
    printf("Erro ao ler o arquivo.\n");
    return 1;
  }

  for (int i = 0; i < lin; i++)
  {
    for (int j = 0; j < col; j++)
    {
      fscanf(file1, " %c", &graphInput1[i][j]); // percorremos o arquivo 1 e salvamos em uma matriz
    }
  }
  fclose(file1);
  FILE *file2 = fopen("input2.txt", "r");
  if (file2 == NULL)
  {
    printf("Erro ao ler o arquivo.\n");
    return 1;
  }
  for (int i = 0; i < lin; i++)
  {
    for (int j = 0; j < col; j++)
    {
      fscanf(file2, " %c", &graphInput2[i][j]); // percorremos o arquivo 2 e salvamos em uma matriz
    }
  }
  fclose(file2);

  Graph G1 = createGraph(col);
  Graph G2 = createGraph(col);

  for (int j = 0; j < col; j++)
  {
    for (int i = 1; i < lin; i++)
    {
      if (graphInput1[i][j] == '1') // perceorremos a matriz do grafo e inserimos um novo nó no grafico onde encontrarmos um 1 na matriz de adjacencias
      {
        insertGraph(G1, j, i - 1);
      }
    }
  }

  for (int j = 0; j < col; j++)
  {
    for (int i = 1; i < lin; i++)
    {
      if (graphInput2[i][j] == '1') // perceorremos a matriz do grafo e inserimos um novo nó no grafico onde encontrarmos um 1 na matriz de adjacencias
      {
        insertGraph(G2, j, i - 1);
      }
    }
  }
  printG(G1);
  printG(G2);

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
