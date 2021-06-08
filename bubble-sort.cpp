#include <iostream>

using namespace std;

int main()
{
    int n, a[10], i, j, temp;
    cout << "Enter the limit > ";
    cin >> n;
    cout << "Enter the array elements > ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << "\n SORTING \n";
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        cout << a[i] << "\n";
    return 0;
}