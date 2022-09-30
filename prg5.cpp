#include <bits/stdc++.h>
using namespace std;
int c;
void heapify(int a[10], int i, int n)
{
    c++;
    int l, r, max;
    l = 2 * i;
    r = 2 * i + 1;
    if (l <= n && a[l] > a[i])
        max = l;
    else
        max = i;
    if (r <= n && a[r] > a[max])
        max = r;

    if (max != i)
    {
        swap(a[max], a[i]);
        heapify(a, max, n);
    }
}
void heap(int a[10], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(a, i, n);
    }
}

void heapsort(int a[], int n)
{
    heap(a, n);
    for (int i = n; i >= 2; i--)
    {
        swap(a[i], a[1]);
        heapify(a, 1, i - 1);
    }
}
void analysis()
{
    int size = 32, i, j, asc, des, ran, gn;
    cout << "\n\nAnalysis of Heap Sort\n";
    cout << "g(n) is c*nlogn for all the cases where c=2\n";
    cout << "Size\tAsc\tg(n)\tDes\tg(n)\tRan\tg(n)\n";
    for (i = 0; i < 6; i++)
    {
        int a[size + 1];
        c = 0;
        for (j = 1; j <= size; j++)
            a[j] = j;
        heapsort(a, size);
        asc = c;
        c = 0;
        for (j = 1; j <= size; j++)
            a[j] = size - j;
        heapsort(a, size);
        des = c;
        c = 0;
        for (j = 1; j <= size; j++)
            a[j] = rand() % size;
        heapsort(a, size);
        ran = c;
        gn = 2 * size * log2(size);
        cout << size << "\t" << asc << "\t" << gn << "\t" << des << "\t" << gn << "\t" << ran << "\t" << gn << "\n";
        size *= 2;
    }
    cout << "\n";
}
int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n + 1];
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    heapsort(a, n);
    cout << "\nArray after Heap sort: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    analysis();
    return 0;
}