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
        sort(doces.begin(), doces.end());
        for (int j = 0; j < num_consultas; j++)
        {
            int consulta = 0;
            cin >> consulta;
            auto it = lower_bound(doces.begin(), doces.end(), consulta);
             // 3. Verificar os elementos vizinhos
    if (it == doces.begin()) {
        // A consulta é menor que o primeiro elemento
        std::cout << "O valor mais próximo é: " << *it << std::endl;
    } else if (it == doces.end()) {
        // A consulta é maior que o último elemento
        std::cout << "O valor mais próximo é: " << *(it - 1) << std::endl;
    } else {
        // A consulta está no meio do vetor
        int anterior = *(it - 1);
        int atual = *it;

        if (std::abs(consulta - anterior) <= std::abs(consulta - atual)) {
            std::cout << "O valor mais próximo é: " << anterior << std::endl;
        } else {
            std::cout << "O valor mais próximo é: " << atual << std::endl;
        }
    }
        }
    }
}