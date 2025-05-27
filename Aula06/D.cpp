#include <iostream>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        if ((n % 2020 == 1 && n >= 2020) || (n % 2020 == 0 && n >= 2020) || (n % 2021 == 0 && n >= 2021))
            cout << "YES" << endl;
        else
        {
            while (n > 2020 && n % 2021 != 0)
                n = n - 2020;
            if (n % 2021 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}