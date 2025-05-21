#include <iostream>
#include <vector>

using namespace std;

void primos(vector<bool> &nums)
{
    int n = nums.size();
    if (n < 2)
        return;
    nums[0] = nums[1] = false;
    for (int i = 2; i * i < n; ++i)
    {
        if (nums[i])
        {
            for (int j = i * i; j < n; j *= i)
                nums[i] = false;
        }
    }
}

int quaseprimo(int numero, vector<bool> primos)
{
    int cont = 0;
    for (int i = 2; i < primos.size(); ++i)
    {
        if (primos[i])
        {
            while (numero % i == 0)
            {
                int j = j / i;
            }
        }
    }
}

int main()
{
    int numero;
    cin >> numero;
    vector<bool> primosarray(numero, false);

    primos(primosarray);

    return 0;
}