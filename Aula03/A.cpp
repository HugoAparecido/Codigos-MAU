#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int casos_testes = 0;
    cin >> casos_testes;
    for (int i = 0; i < casos_testes; i++)
    {
        int num_doces = 0, num_consultas = 0;
        cin >> num_doces >> num_consultas;
        vector<int> doces(num_doces);
        for (int j = 0; j < num_doces; j++)
        {
            cin >> doces[j];
        }
        sort(doces.rbegin(), doces.rend());
        vector<long long> prefix_sum(num_doces);
        prefix_sum[0] = doces[0];
        for (int j = 1; j < num_doces; ++j)
        {
            prefix_sum[j] = prefix_sum[j - 1] + doces[j];
        }
        for (int j = 0; j < num_consultas; j++)
        {
            int consulta;
            cin >> consulta;
            auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), consulta);
            if (it == prefix_sum.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << distance(prefix_sum.begin(), it) + 1 << endl;
            }
        }
    }
}