#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int casos_testes;
    cin >> casos_testes;
    while (casos_testes--)
    {
        string caso;
        cin >> caso;
        int tamanho = caso.size();
        vector<int> numeros(tamanho);
        vector<int> arrayElevado(tamanho);
        for (int i = 0; i < tamanho; i++)
        {
            numeros[i] = caso[i] - '0'; // Convert char to int
            arrayElevado[i] = numeros[i] * numeros[i] < 10 ? numeros[i] * numeros[i] : numeros[i];
        }

        bool divisivel = false;
        for (int i = 0; i < tamanho; i++)
        {
            if (arrayElevado[i] != numeros[i])
            {
                int guardar = numeros[i];
                numeros[i] = arrayElevado[i];
                int soma = accumulate(numeros.begin(), numeros.end(), 0);
                if (soma % 9 == 0)
                {
                    divisivel = true;
                    break;
                }
                numeros[i] = guardar;
            }
        }
        if (!divisivel)
            divisivel = accumulate(arrayElevado.begin(), arrayElevado.end(), 0) % 9 == 0;

        if (divisivel)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}