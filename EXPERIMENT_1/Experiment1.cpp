#include <bits/stdc++.h>
using namespace std;

long long operations = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {
    if (n <= 2) return;

    maxDepth = max(maxDepth, depth);

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        p >>= 1;
        operations++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }

    reverse(small.begin(), small.end());
    operations += n;

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    vector<int> testSizes = {8, 16, 32, 64, 128};

    for (int n : testSizes) {
        operations = 0;
        maxDepth = 0;

        clock_t start = clock();
        complexRec(n, 1);
        clock_t end = clock();

        double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;

        cout << "n = " << n << "\n";
        cout << "Operations: " << operations << "\n";
        cout << "Max Depth: " << maxDepth << "\n";
        cout << "Time (ms): " << duration << "\n\n";
    }

    return 0;
}
// Recurance relation: T(N) = 3T(N/2)+N*LOG(N)
// master theorem: theta(n^(1.584)) case 1(f(n)< n^k)
