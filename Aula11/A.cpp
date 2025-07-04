#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &grafo, vector<bool> &visitados, int atual, int valor_procurado)
{
    int x = 1;
    visitados[atual] = true;
    for (int i = 0; i < grafo[atual].size(); i++)
        if (!visitados[grafo[atual][i]] && grafo[atual][i] != valor_procurado)
            x += dfs(grafo, visitados, grafo[atual][i], valor_procurado);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int q;
        cin >> q;
        vector<vector<int>> grafo(q);
        vector<bool> visitados(q, false);
        for (int i = 0; i < q; i++)
        {
            int entrada;
            cin >> entrada;
            grafo[i] = {entrada};
        }
        int valor_procurado;
        for (int i = 0; i < q; i++)
        {
            valor_procurado = i;
            int resultado = dfs(grafo, visitados, i, valor_procurado);
            cout << "Resultado de " << i << " : " << resultado << endl;
        }
        // for(int i = 0; i < q; i++){
        //     cout << "Tenho: "<< grafo[i][0] << " para passar"<<endl;
        // }
    }

    return 0;
}