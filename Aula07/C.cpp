#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<char, int> sala_quantidade;
    int contador = 0;
    while (n--)
    {
        string nome;
        cin >> nome;
        if (sala_quantidade.find(nome[0]) != sala_quantidade.end())
        {
            sala_quantidade[nome[0]]++;
        }
        else
        {
            sala_quantidade[nome[0]] = 1;
        }
    }

    vector<pair<char, int>> sala_ordenada(sala_quantidade.begin(), sala_quantidade.end());

    auto sort_by_value_decreasing = [](const pair<char, int> &a, const pair<char, int> &b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    };

    sort(sala_ordenada.begin(), sala_ordenada.end(), sort_by_value_decreasing);

    int resto = sala_ordenada[0].second % 2;
    int grupo1, grupo2;
    grupo1 = grupo2 = sala_ordenada[0].second / 2;
    grupo2 += resto;

    if (grupo1 == 2)
        contador += 1;
    if (grupo2 == 2)
        contador += 1;
    if (grupo1 > 2)
        contador += grupo1;
    if (grupo2 > 2)
        contador += grupo2;

    cout << contador << endl;

    return 0;
}