#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << "Enter the elements of the second array: ";
    for (int j = 0; j < m; ++j)
    {
        cin >> b[j];
    }

    int *c = new int[n + m];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        c[k++] = (a[i] < b[j]) ? a[i++] : b[j++];
    }
    while (i < n)
    {
        c[k++] = a[i++];
    }
    while (j < m)
    {
        c[k++] = b[j++];
    }
    cout << "Merged array: ";
    for (int t = 0; t < k; ++t)
    {
        cout << c[t] << ' ';
    }
    cout << endl;
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
