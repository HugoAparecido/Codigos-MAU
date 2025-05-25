#include <iostream>
#include <vector>

using namespace std;

int mdc(int a, int b)
{
    if (b == 0)
        return 0;
    return mdc(b, a % b);
}

int mmc(int a, int b)
{
    return (a / mdc(a, b) * b);
}

void primos(vector<bool> &nums)
{
    int n = nums.size();

    // Inicializa todas as posições como true (potencialmente primas)
    // Exceto 0 e 1, que não são primos.
    if (n > 0) nums[0] = false;
    if (n > 1) nums[1] = false;

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

int main()
{
    vector<bool> primosArray(10, true);
    primos(primosArray);

    for (int i = 0; i < 10; i++)
        cout << primosArray[i] << endl;
    return 0;
}