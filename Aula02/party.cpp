#include <iostream>
#include <vector>

using namespace std;

void dfs(int profundidade, int &maxProf, vector<vector<int>> &hierarquias, int funcionario)
{
    maxProf = max(maxProf, profundidade);

    for (int hierarquia : hierarquias[funcionario])
    {
        dfs(profundidade + 1, maxProf, hierarquias, hierarquia);
    }
}

void maiorProfundidade(int empregados, vector<int> &chefes)
{
    vector<int> raizes;

    vector<vector<int>> hierarquias(empregados + 1);

    for (int i = 0; i < empregados; ++i)
    {
        if (chefes[i] == -1)
        {
            raizes.push_back(i + 1);
        }
        else
        {
            hierarquias[chefes[i]].push_back(i + 1);
        }
    }

    int maxProf = 0;

    for (int raiz : raizes)
    {
        dfs(1, maxProf, hierarquias, raiz);
    }

    cout << maxProf;
}

int main()
{

    int empregados;

    cin >> empregados;

    vector<int> chefes(empregados);

    for (int i = 0; i < empregados; ++i)
    {

        cin >> chefes[i];
    }

    maiorProfundidade(empregados, chefes);

    return 0;
}