#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &grafo, vector<int> precos, vector<bool> &visitados, int atual)
{
    visitados[atual] = true;
    count = precos[atual];
    for (int i = 0; i < grafo[atual].size(); i++)
        if (!visitados[grafo[atual][i]])
            count = min(count, dfs(grafo, precos, visitados, grafo[atual][i]));
    return count;
}
int main()
{
    m = 3;
    vector<bool> visitados(m, false);
    int count = 0;
    for (int i = 0; i < m; ++i)
        if (!visitados[i])
            count += dfs(grafo, precos, visitados, i);

    cout << count << endl;

    return 0;
}