#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int buscaBinaria(const std::vector<int> &arr, int alvo, int qtd_consultas)
{
    int esquerda = 0;
    int direita = arr.size() - 1;

    while (esquerda <= direita)
    {
        qtd_consultas++;
        int meio = esquerda + (direita - esquerda) / 2; // Evita overflow para vetores grandes

        if (arr[meio] == alvo)
        {
            return meio; // Elemento encontrado na posição 'meio'
        }
        else if (arr[meio] < alvo)
        {
            esquerda = meio + 1; // Alvo está na metade direita
        }
        else
        {
            direita = meio - 1; // Alvo está na metade esquerda
        }
    }

    return -1; // Elemento não encontrado
}
int main()
{
    int elementos_array = 0, consulta = 0, qtd_consultas_1 = 0, qtd_consultas_2 = 1;
    cin >> elementos_array;
    vector<int> numeros(elementos_array);
    for (int i = 0; i < elementos_array; i++)
    {
        cin >> numeros[i];
    }
    sort(numeros.begin(), numeros.end());
    cin >> consulta;
    vector<int> consultas(consulta);
    for (int i = 0; i < consulta; i++)
    {
        cin >> consultas[i];
        for (int j = 0; j < consultas[i]; j++)
        {
            qtd_consultas_1++;
        }
        int indice = buscaBinaria(numeros, consultas[i], qtd_consultas_2);
    }
    cout << qtd_consultas_1 << " " << qtd_consultas_2 << endl;
    return 0;
}