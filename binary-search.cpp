#include <iostream>

using namespace std;

int main()
{
    int n, a[10], s, beg, mid, end, i, found = 0;
    cout << "Enter the limit: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the element to be searched: ";
    cin >> s;
    beg = 0;
    end = n - 1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == s)
        {
            cout << "Element is found at position: " << mid;
            found = 1;
            break;
        }
        else if (a[mid] > s)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if (beg > end && found == 0)
        cout << "Not found";
    return 0;
}