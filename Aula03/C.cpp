#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num_elementos, qtd_percorrido_1 = 0, qtd_percorrido_2 = 0;
    cin >> num_elementos;
    vector<pair<int, int>> elementos(num_elementos);
    int indice = 0;
    for (auto& par : elementos) {
        std::cin >> par.first;
        par.second = indice + 1;
        indice++;
    }
    reverse(elementos.begin(), elementos.end()); // Inverte a ordem dos elementos
    int num_consultas;
    cin >> num_consultas;
    for (int i = 0; i < num_consultas; i++)
    {
        int consulta;
        cin >> consulta;
        qtd_percorrido_2++;
        auto it = find_if(elementos.begin(), elementos.end(), [&](const pair<int, int>& p){
return p.first == consulta;
        });
        if (it != elementos.end())
        {
            qtd_percorrido_1 +=  it->second;
            qtd_percorrido_2 += distance(elementos.begin(), it);
        }
    }
    cout << qtd_percorrido_1 << " "<< qtd_percorrido_2 << endl;
    return 0;
}