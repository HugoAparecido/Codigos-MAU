#include <iostream>
#include <vector>

// pesquisar unordered set

using namespace std;

vector<int> fatoracao(int n)
{
    vector<int> result;
    if (n == 1)
        return result;
    while (n % 2 == 0)
    {
        n /= 2;
        result.push_back(2);
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            result.push_back(i);
        }
    }

    if (n > 1)
        result.push_back(n);
    return result;
}

int main()
{

    return 0;
}