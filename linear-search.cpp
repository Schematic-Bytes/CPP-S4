#include <iostream>

using namespace std;

int main()
{
    int n, a[10], s, found = 0;
    cout << "Enter the no. of elements: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the element to be searched: ";
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s == a[i])
        {
            found = 1;
            cout << "The element is found at position: " << i;
            break;
        }
    }
    if (found == 0)
        cout << "Element is not found";
    return 0;
}