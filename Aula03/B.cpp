#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int contarValoresMenorOuIgual(const vector<int> &array_ordenado, int valor)
{
    // Encontra o primeiro elemento que é estritamente maior que 'valor'
    auto it = upper_bound(array_ordenado.begin(), array_ordenado.end(), valor);

    // A distância do início do array até esse elemento é a quantidade de elementos
    // que são menores ou iguais a 'valor'
    return distance(array_ordenado.begin(), it);
}

int main()
{
    int num_lojas;
    cin >> num_lojas;
    vector<int> preco_lojas(num_lojas);
    for (int i = 0; i < num_lojas; i++)
    {
        cin >> preco_lojas[i];
    }

    // Importante: Ordene o array de preços para usar a busca binária
    sort(preco_lojas.begin(), preco_lojas.end());

    int num_dias;
    cin >> num_dias;
    for (int i = 0; i < num_dias; i++)
    {
        int dia;
        cin >> dia;
        int contador = contarValoresMenorOuIgual(preco_lojas, dia);
        cout << contador << endl;
    }

    return 0;
}