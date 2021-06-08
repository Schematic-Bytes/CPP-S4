#include <iostream>

void QuickSort(int a[], int l, int u);
int partition(int a[], int l, int u);

using namespace std;

int main()
{
    int a[10], i, n;
    cout << "Enter the limit > ";
    cin >> n;
    cout << "Enter the element > ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    QuickSort(a, 0, n - 1);
    cout << "-- sorted list --\n";
    for (i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}

void QuickSort(int a[], int l, int u)
{
    int j;
    if (l < u)
    {
        j = partition(a, l, u);
        QuickSort(a, l, j - 1);
        QuickSort(a, j + 1, u);
    }
}

int partition(int a[], int l, int u)
{
    int pivot, j, temp, p, i;
    i = l;
    pivot = a[i];
    j = u + 1;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot && i <= u);
        do
        {
            j--;
        } while (pivot < a[j]);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    a[l] = a[j];
    a[j] = pivot;
    return j;
}