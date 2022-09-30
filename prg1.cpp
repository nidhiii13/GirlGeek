#include <bits/stdc++.h>
using namespace std;

int merge(int a[], int l, int mid, int r)
{
    int count = 0;
    int temp[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            count++;
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            count++;
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        count++;
        i++;
        k++;
    }
    while (j <= r)
    {

        temp[k] = a[j];
        count++;
        k++;
        j++;
    }
    k = 0;
    i = l;
    while (k <= r - l)
    {
        a[i] = temp[k];
        count++;
        k++;
        i++;
    }
    return count;
}

int mergeSort(int a[], int l, int h)
{
    if (l >= h)
        return 0;
    int mid = (l + h) / 2;
    int x = mergeSort(a, l, mid);
    int y = mergeSort(a, mid + 1, h);
    int z = merge(a, l, mid, h);
    return x + y + z;
}

int main()
{
    // int n;
    int size = 32;
    int a[30000];
    int m;
    cout << "Size    "
         << "Asc   C*log(n)   "
         << "dsc    C*log(n) "
         << "random     C*nlog(n)" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << size << "\t";
        for (int j = 0; j < size; j++)
        {
            a[j] = j;
        }
        m = mergeSort(a, 0, size - 1);
        cout << m << "\t" << 3 * size * log2(size) << "\t";
        for (int j = 0; j < size; j++)
        {
            a[j] = size - j;
        }
        m = mergeSort(a, 0, size - 1);
        cout << m << "\t" << 3 * size * log2(size) << "\t  ";
        for (int j = 0; j < size; j++)
        {
            a[j] = rand() % 10000;
        }
        m = mergeSort(a, 0, size - 1);
        cout << m << "\t\t" << 3 * size * log2(size) << "\t";
        size = size * 2;
        cout << endl;
    }
}