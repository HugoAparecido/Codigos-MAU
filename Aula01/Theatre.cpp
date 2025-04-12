#include <iostream>
using namespace std;
int main()
{
    int n = 0, m = 0, a = 0, qtd_lajes = 0;
    cin >> n;
    cin >> m;
    cin >> a;
    qtd_lajes = int(n / a);
    if (n % a != 0)
    {
        qtd_lajes++;
    }
    if (m % a != 0)
    {
        qtd_lajes += int(n / a) + 1;
    }
    cout << qtd_lajes << endl;
    return 0;
}