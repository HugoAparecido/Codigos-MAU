#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool subtrairVerificacao(vector<int> &array, int numero)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i] = numero - array[i];
        if (array.size() <= 1)
        {
            return true;
        }
        for (size_t j = 0; j < array.size() - 1; ++j)
        {
            if (array[j] >= array[j + 1])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int num_casos;
    cin >> num_casos;
    while (num_casos--)
    {
        int elementos1, elementos2;
        cin >> elementos1 >> elementos2;
        vector<int> array1(elementos1), array2(elementos2);
        for (int i = 0; i < elementos1; i++)
        {
            cin >> array1[i];
        }
        cin >> array2[0];
        if (elementos1 == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            if(!subtrairVerificacao(array1, array2[0]))
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}