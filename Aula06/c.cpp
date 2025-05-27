#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int num_sequencia = 0;
    int num_sequencia_maior = 0;
    long int num_anterior = 0;
    while (n--)
    {
        long int num_atual;
        cin >> num_atual;
        if (num_atual < num_anterior)
        {
            if (num_sequencia_maior < num_sequencia)
            {
                num_sequencia_maior = num_sequencia;
            }
            num_sequencia = 1;
        }
        else
            num_sequencia++;
        num_anterior = num_atual;
    }
    if (num_sequencia_maior < num_sequencia)
    {
        num_sequencia_maior = num_sequencia;
    }
    cout << num_sequencia_maior << endl;
    return 0;
}