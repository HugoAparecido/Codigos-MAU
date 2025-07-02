#include <iostream>
#include <vector>

using namespace std;

// versão normal
void dfs(vector<vector<int>> &grafo, vector<bool> &visitados, int atual)
{
    visitados[atual] = true;
    for (int i = 0; i < grafo[atual].size(); i++)
        if (!visitados[grafo[atual][i]])
            dfs(grafo, visitados, grafo[atual][i]);
}

int dfs(vector<vector<int>> &grafo, vector<bool> &visitados, int atual)
{
    int x = 1;
    visitados[atual] = true;
    for (int i = 0; i < grafo[atual].size(); i++)
        if (!visitados[grafo[atual][i]])
            x += dfs(grafo, visitados, grafo[atual][i]);
}

int main()
{

    return 0;
}