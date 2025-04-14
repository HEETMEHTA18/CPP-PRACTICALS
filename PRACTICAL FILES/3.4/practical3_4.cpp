/*A technology firm aimed to develop a flexible and reusable solution for managing collections of various
data types, including integers, floating-point numbers, and characters. The system was intended to
perform fundamental operations on these collections, such as finding the maximum value, reversing
the collection, and displaying all elements. To achieve versatility and avoid redundancy in code, the
solution was designed to use function templates, allowing the same logic to be applied seamlessly to
different data types.
The team recognized the importance of using dynamic arrays to store the collections, enabling
efficient management of varying collection sizes. The design emphasized scalability and flexibility,
ensuring that the system could handle different data types and their associated operations with
minimal changes to the core logic.
In practice, the system allowed for the creation of collections for various data types, such as integers,
floating-point numbers, and characters. The operations on these collections included determining the
maximum value, reversing the order of elements, and printing the collection contents.*/
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

template <typename T>
void reverseArray(T arr[], int n) {
    for(int i = 0; i < n / 2; i++){
        swap(arr[i], arr[n - i - 1]);
    }
}

template <typename T>
void displayArray(T arr[], int n) {
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 3, 5, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    displayArray(arr, n);
    
    cout << "Max element: " << findMax(arr, n) << endl;
    
    reverseArray(arr, n);
    cout << "Reversed array: ";
    displayArray(arr, n);
    
    return 0;
}
