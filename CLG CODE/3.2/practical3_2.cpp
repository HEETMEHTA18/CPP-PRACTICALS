/*A software development company was tasked with conducting a performance analysis of recursive
algorithms versus their iterative counterparts. The specific focus was on calculating the sum of
integers in an array, where the array's size and elements were to be provided dynamically by the user.
To facilitate memory management and enable dynamic resizing of the array, the team decided to use
a flexible container for storing the array elements.
The system was designed to first prompt users for the array's size and then request the input of
individual elements. A recursive function was to be implemented to compute the sum by dividing the
problem into smaller sub-problems, recursively summing subsets of the array until reaching the base

case. In addition to the recursive implementation, an iterative version of the function would be
created for comparison.
The main objective of the study was to assess and compare the computational performance and
implementation complexity of both recursive and non-recursive approaches. By evaluating execution
times, memory usage, and code complexity, the team hoped to gain insights into the trade-offs
between recursion and iteration, particularly in terms of efficiency and applicability to real-world
problems.*/
#include <iostream>
using namespace std;

int recursiveSum(int arr[], int n) {
    if(n <= 0) return 0;
    return arr[n-1] + recursiveSum(arr, n-1);
}

int iterativeSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Recursive Sum: " << recursiveSum(arr, n) << endl;
    cout << "Iterative Sum: " << iterativeSum(arr, n) << endl;
    delete[] arr;
    return 0;
}
