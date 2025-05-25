#include <iostream>
#include <vector>

using namespace std;

void primos(vector<bool> &nums)
{
    int n = nums.size();

    // Inicializa todas as posições como true (potencialmente primas)
    // Exceto 0 e 1, que não são primos.
    if (n > 0)
        nums[0] = false;
    if (n > 1)
        nums[1] = false;

    // Começa do 2
    for (int i = 2; i * i < n; i++)
    {
        // Se nums[i] é true, então i é um número primo
        if (nums[i])
        {
            // Marca todos os múltiplos de i (a partir de i*i) como não primos
            for (int j = i * i; j < n; j += i) // CORREÇÃO: j += i
            {
                nums[j] = false; // CORREÇÃO: Marca nums[j] como false
            }
        }
    }
}

int quaseprimo(int numero, vector<bool> primos)
{
    int cont = 0;
    for (int i = 2; i <= numero; i++)
    {
        if (primos[i])
        {
            if (cont > 2)
                return false;
            if (numero % i == 0)
            {
                cont++;
                while (numero % i == 0)
                {
                    numero = numero / i;
                }
            }
        }
    }
    if (cont == 2)
        return true;
    else
        return false;
}

int main()
{
    int numero;
    cin >> numero;
    vector<bool> primosarray(numero, true);

    primos(primosarray);
    int qtd_quase_primo = 0;
    for (int i = 2; i <= numero; i++)

    {
        bool quase_primo = quaseprimo(i, primosarray);
        if (quase_primo)
        {
            qtd_quase_primo++;
        }
    }

    cout << qtd_quase_primo << endl;

    return 0;
}