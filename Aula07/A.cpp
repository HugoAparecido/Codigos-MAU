#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arrayVermelho1;
        vector<int> arrayVermelho2;
        int contArray1 = 0;
        int contArray2 = 0;
        int maiorEleArr1 = 0;
        int maiorEleArr2 = 0;
        for (int i = 0; i < n; i++)
        {
            int elemento;
            cin >> elemento;
            if (i % 2 == 0)
            {
                contArray1++;
                arrayVermelho1.push_back(elemento);
                if (maiorEleArr1 < elemento)
                    maiorEleArr1 = elemento;
            }
            else
            {
                contArray2++;
                arrayVermelho2.push_back(elemento);
                if (maiorEleArr2 < elemento)
                    maiorEleArr2 = elemento;
            }
        }
        if ((maiorEleArr1 + contArray1) >= (maiorEleArr2 + contArray2))
            cout << maiorEleArr1 + contArray1 << endl;
        else
            cout << maiorEleArr2 + contArray2 << endl;
    }

    return 0;
}