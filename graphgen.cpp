#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n = 10;
    int m = (10 * 9) / 2;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int w = rand() % 100000 + 1;
            printf("%d %d %d\n", i, j, w);
        }
    }
    return 0;
}
