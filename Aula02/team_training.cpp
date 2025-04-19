#include <iostream>
using namespace std;
int main()
{
    int text_cases = 0, num_students = 0, force_time = 0, current_force = 0;
    cin >> text_cases;
    for (int i = 0; i < text_cases; i++)
    {
        cin >> num_students;
        cin >> force_time;
        int students[num_students];
        for (int j = 0; j < num_students; j++)
        {
            cin >> students[j];
            if (current_force == 0)
            {
                current_force = students[j];
            }
            if (students[j] > force_time && students[j] <= current_force)
            {
                current_force = students[j];
            }
        }
        cout << current_force << endl;
        current_force = 0;
    }
}