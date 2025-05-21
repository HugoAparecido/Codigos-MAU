#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int casos_testes;
    cin >> casos_testes;
    while (casos_testes--)
    {
        long long int caso;
        cin >> caso;
        int a = caso - 3, b, c, d;
        b = c = d = 1;
        cout << a << " " << b << " " << c << " " << d << endl;
    }

    return 0;
}