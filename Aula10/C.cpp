#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int a, b, c, d;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    double resposta = 1 / (1 - ((1 - (double)a / b) * (1 - (double)c / a)));

    cout << setprecision(6) << resposta << endl;

    return 0;
}