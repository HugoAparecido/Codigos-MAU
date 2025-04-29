#include <iostream>

using namespace std;

int main()
{
    int casos_testes;
    cin >> casos_testes;
    while (casos_testes--)
    {
        int num_elementos, chegada;
        cin >> num_elementos >> chegada;
        int capacidade_tanque;
        int postos[num_elementos];
        for (int i = 0; i < num_elementos; i++)
        {
            cin >> postos[i];
            if (i == 0)
            {
                capacidade_tanque = postos[i] + 2;
            }
            else
            {
                if (postos[i] - postos[i - 1] > capacidade_tanque)
                {
                    capacidade_tanque = postos[i] - postos[i - 1] + 1;
                }
            }
            if (i + 1 == num_elementos)
            {
                if (chegada - postos[i] > capacidade_tanque)
                {
                    capacidade_tanque = chegada - postos[i] + 1;
                }
            }
        }
        cout << capacidade_tanque << endl;
    }

    return 0;
}