#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int j = 0; j < m; ++j) std::cin >> b[j];
    int *c = new int[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
        c[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
    for (int t = 0; t < k; ++t) std::cout << c[t] << ' ';
    std::cout << std::endl;
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
