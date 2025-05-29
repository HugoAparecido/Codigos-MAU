#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int comprimento;
        cin >> comprimento;
        string numero_binario;
        cin >> numero_binario;
        int numeros_1 = 0;
        vector<char> VetorString(numero_binario.begin(), numero_binario.end());
        for (int i = 0; i < comprimento; i++)
        {
            if (VetorString[i] == '0')
                numeros_1++;
            else
                numeros_1 += comprimento - 1;
        }

        cout << numeros_1 << endl;
    }

    return 0;
}