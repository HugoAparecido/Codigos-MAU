#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int numerador_inicial = 1;
    int denominador_inicial = 1;
    for (int i = 0; i < n; i++)
    {
        int numerador_atual = denominador_inicial;
        denominador_inicial += numerador_inicial;
        numerador_inicial = numerador_atual;
    }

    cout << numerador_inicial << endl;

    return 0;
}