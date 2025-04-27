#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_non_decreasing(const vector<int>& a) {
    for (size_t i = 0; i < a.size() - 1; ++i) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        bool possible = false;
        if (m == 1) {
            int x = b[0];
            vector<int> original_a = a;
            sort(original_a.begin(), original_a.end());
            if (is_non_decreasing(original_a)) {
                possible = true;
            } else {
                vector<int> modified_a = a;
                for (int i = 0; i < n; ++i) {
                    modified_a[i] = x - a[i];
                }
                sort(modified_a.begin(), modified_a.end());
                if (is_non_decreasing(modified_a)) {
                    possible = true;
                } else {
                    vector<int> mixed_a = a;
                    sort(mixed_a.begin(), mixed_a.end());
                    if (is_non_decreasing(mixed_a)) {
                        possible = true;
                    } else {
                        vector<int> all_modified_a = a;
                        for (int i = 0; i < n; ++i) {
                            all_modified_a[i] = x - a[i];
                        }
                        sort(all_modified_a.begin(), all_modified_a.end());
                        if (is_non_decreasing(all_modified_a)) {
                            possible = true;
                        } else {
                            for (int i = 0; i < (1 << n); ++i) {
                                vector<int> current_a = a;
                                for (int j = 0; j < n; ++j) {
                                    if ((i >> j) & 1) {
                                        current_a[j] = x - a[j];
                                    }
                                }
                                vector<int> sorted_current_a = current_a;
                                sort(sorted_current_a.begin(), sorted_current_a.end());
                                if (is_non_decreasing(sorted_current_a)) {
                                    possible = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}