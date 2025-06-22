#include<iostream>
#define max 6
using namespace std;

int main()
{
    int n, temp, i, data, beg=0, end=5, mid;
    cout << "How many you want to enter?\n";
    cin >> n;
    int arr[n];
    cout << "Enter the element: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

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
    }
    cout<<"Which number you want to search? ";
    cin>> data;
    mid=(beg+end)/2;
    if(data<arr[mid]){
        end = mid-1;
    }
    else if(data>arr[mid]){
        beg = mid+1;
    }
    while(beg<=end && arr[mid]!=data){
        if(data<arr[mid]){
            end = mid-1;
        }
        else if(data>arr[mid]){
            beg = mid+1;  
        }
        mid=(beg+end)/2;
    }
    if(arr[mid]==data){ 
        cout<<"Data is found.";
    }
    else{
        cout<<"Data not found.";
    }
}