#include <iostream>
#include <vector>
#include <map> // Inclui a biblioteca para usar mapas (estruturas de dados chave-valor)

using namespace std;

int main()
{
    int num_elementos;
    cin >> num_elementos;

    vector<int> elementos(num_elementos);
    map<int, int> pos; // Declara um mapa onde a chave é um inteiro (o elemento) e o valor é um inteiro (sua posição)

    for (int i = 0; i < num_elementos; ++i)
    {
        cin >> elementos[i];
        pos[elementos[i]] = i + 1; // Armazena o elemento como chave no mapa 'pos' e sua posição (índice + 1, pois o problema usa indexação baseada em 1) como valor
    }

    int num_consultas;
    cin >> num_consultas;

    long long vasya = 0, petya = 0; // Declara duas variáveis long long para armazenar o número total de passos de Vasya e Petya (usamos long long para evitar overflow com grandes entradas)
    for (int i = 0; i < num_consultas; ++i)
    {
        int consulta;
        cin >> consulta;

        // Verifica se o elemento procurado existe no mapa 'pos' (ou seja, no array original)
        if (pos.count(consulta))
        {
            vasya += pos[consulta];                       // Se encontrado, adiciona a posição (passos de Vasya) ao total de Vasya
            petya += (num_elementos - pos[consulta] + 1); // Calcula e adiciona os passos de Petya (começando do final) ao total de Petya
        }
        else
        {
            // Caso o elemento não seja encontrado (embora a descrição do problema geralmente assuma que os elementos consultados estarão presentes)
            vasya += num_elementos; // No pior caso, Vasya teria que verificar todos os elementos
            petya += num_elementos; // No pior caso, Petya também teria que verificar todos os elementos (do final)
        }
    }

    cout << vasya << " " << petya << endl; // Imprime o número total de passos de Vasya e Petya separados por um espaço
    return 0;                              // Indica que o programa terminou com sucesso
}