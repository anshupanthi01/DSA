#include <iostream>
using namespace std;
int main()
{
    int n, temp, i;
    cout << "How many you want to enter?\n";
    cin >> n;
    int arr[n];
    cout << "Enter the element: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sorting process:\n";
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    cout << "Sorted array is: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}