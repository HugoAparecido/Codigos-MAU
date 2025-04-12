#include <iostream>
using namespace std;

int main()
{
    int num1;
    cin >> num1;
    while (num1 != 42)
    {
        cout << num1 << endl;
        cin >> num1;
    }
    return 0;
}