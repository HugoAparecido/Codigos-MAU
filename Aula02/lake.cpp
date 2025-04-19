#include <iostream>
using namespace std;
int main()
{
    int num_cases = 0;
    cin >> num_cases;
    for (int i = 0; i < num_cases; i++)
    {
        int n = 0;
        cin >> n;
        int lake[n];
        for (int j = 0; j < n; j++)
        {
            cin >> lake[j];
        }
        int max = 0;
        for (int j = 0; j < n; j++)
        {
            if (lake[j] > max)
            {
                max = lake[j];
            }
        }
        cout << max << endl;
    }
}