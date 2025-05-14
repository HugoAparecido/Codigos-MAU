#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    string casos_testes;
    cin >> casos_testes;
    int tamanho = casos_testes.size();
    vector<int> numeros(tamanho);
    int arrayElevado[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        numeros[i] = casos_testes[i] - '0'; // Convert char to int
        arrayElevado[i] = (int)casos_testes[i] * (int)casos_testes[i];
    }

    bool divisivel = false;
    for (int i = 0; i < tamanho; i++)
    {
        if (arrayElevado[i] < 10)
        {
            int guardar = numeros[i];
            numeros[i] = arrayElevado[i];
            int soma = accumulate(numeros.begin(), numeros.end(), 0);
            if (soma % 3 == 0)
            {
                divisivel = true;
                break;
            }
            numeros[i] = guardar;
        }
    }

    if (divisivel)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}