#include <iostream>
using namespace std;

int main()
{
    int n, temp, i, data;
    cout << "How many you want to enter?\n";
    cin >> n;
    int arr[n];
    cout << "Enter the element: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the number you want to search: ";
    cin >> data;
    for (i = 0; i < n ; i++)
    {
        if (data == arr[i])
        {
            cout << "Data is found.";
            break;
        }
    }
    if(arr[i]!=data){
        cout<<"data not found.";
    }
}