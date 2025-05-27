#include <iostream>
#include <vector>

using namespace std;

int somaElementos(vector<int> &array, int inicio, int fim)
{
    int soma = 0;
    for (int i = inicio; i <= fim; i++)
    {
        soma += array[i];
    }
    return soma;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    int menor_altura;
    int indice_inicial;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        if (i >= k - 1)
        {
            int soma = somaElementos(array, i - k + 1, i);
            if (i == k - 1 || soma < menor_altura)
            {
                menor_altura = soma;
                indice_inicial = i - k + 2; // +1 para ajustar ao índice 1
            }
        }
    }

    cout << indice_inicial << endl;

    return 0;
}