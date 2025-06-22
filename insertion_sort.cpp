#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many numbers do you want to enter?\n";
    cin >> n;

    int arr[n]; 
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Insertion Sort Algorithm
    for (int i = 1; i < n; i++) { 
        int temp = arr[i]; 

        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;

        // Display the array after each pass
        cout << "Pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }

    // Print the sorted array
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
