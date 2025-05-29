#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int tamanho;
        long long int posicao;
        cin >> tamanho;
        cin >> posicao;
        vector<char> caracteres(tamanho, 'a');

        if (posicao <= tamanho - 1)
        {
            caracteres[tamanho - posicao - 1] = 'b';
            caracteres[tamanho - 1] = 'b';
        }

        else
        {
            if (posicao > 2 * tamanho)
            {
                int resto = tamanho - 1;
                long long int posicao_atual = posicao - tamanho;
                while (posicao_atual > resto)
                {
                    posicao_atual -= resto;
                    resto -= 1;
                }
                caracteres[tamanho - resto] = 'b';
                caracteres[tamanho - posicao_atual + 1] = 'b';
            }
            else
            {
                caracteres[0] = 'b';
                int posicao_outro = posicao % (tamanho - 1);
                caracteres[tamanho - posicao_outro - 2] = 'b';
            }
        }
        for (int i = 0; i < tamanho; i++)
            cout << caracteres[i];
        cout << endl;
    }
    return 0;
}