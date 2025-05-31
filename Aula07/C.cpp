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
    vector<char> sala1;
    vector<char> sala2;
    map<char, int> sala1_quantidade;
    map<char, int> sala2_quantidade;
    int contador = 0;
    while (n--)
    {
        string nome;
        cin >> nome;
        if (sala1.size() < sala2.size() || (sala1.size() == sala2.size() && sala1_quantidade[nome[0]] < sala2_quantidade[nome[0]]))
        {
            if (sala1_quantidade.find(nome[0]) != sala1_quantidade.end())
            {
                sala1_quantidade[nome[0]]++;
            }
            else
            {
                sala1_quantidade[nome[0]] = 1;
            }
            sala1.push_back(nome[0]);
        }
        else
        {
            if (sala2_quantidade.find(nome[0]) != sala2_quantidade.end())
            {
                sala2_quantidade[nome[0]]++;
            }
            else
            {
                sala2_quantidade[nome[0]] = 1;
            }
            sala2.push_back(nome[0]);
        }
    }

    vector<pair<char, int>> sala1_ordenada(sala1_quantidade.begin(), sala1_quantidade.end());
    vector<pair<char, int>> sala2_ordenada(sala2_quantidade.begin(), sala2_quantidade.end());

    auto sort_by_value_decreasing = [](const pair<char, int> &a, const pair<char, int> &b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    };

    sort(sala1_ordenada.begin(), sala1_ordenada.end(), sort_by_value_decreasing);
    sort(sala2_ordenada.begin(), sala2_ordenada.end(), sort_by_value_decreasing);

    if (sala1_ordenada[0].first == sala2_ordenada[0].first)
    {
        if (sala1_ordenada[0].second == 2)
            contador += (sala1_ordenada[0].second - 1);
        if (sala1_ordenada[0].second > 2)
            contador += (sala1_ordenada[0].second);

        if (sala2_ordenada[0].second > 2)
            contador += (sala2_ordenada[0].second);
        if (sala2_ordenada[0].second == 2)
            contador += (sala2_ordenada[0].second - 1);
    }

    cout << contador << endl;

    return 0;
}