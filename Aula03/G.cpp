#include <iostream>
using namespace std;
int main(void)
{
    int num_paradas, num_desembarque, num_embarque, num_passageiros = 0, maior_numero = 0;
    cin >> num_paradas;
    for (int i = 0; i < num_paradas; i++)
    {
        cin >> num_desembarque >> num_embarque;
        num_passageiros -= num_desembarque;
        num_passageiros += num_embarque;
        if (num_passageiros > maior_numero)
        {
            maior_numero = num_passageiros;
        }
    }
    cout << maior_numero << endl;
    return 0;
}