/*In a rapidly growing software development firm, a team of engineers is tasked with building a
lightweight, custom memory management system for handling dynamic datasets. The existing
framework lacks flexibility in managing arrays, often leading to inefficient memory usage and
performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at
the end of the dataset and removing specific elements based on their position. Since the system
operates in a resource-constrained environment, using standard template libraries is not an option,
and direct dynamic memory management must be implemented using pointers. The solution should
ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary
overhead.
The development team must carefully decide on the structure of their implementation, defining how
data will be stored, accessed, and modified efficiently. They need to outline the appropriate class
design, determine essential data members, and define necessary member functions to handle the
operations effectively.*/

#include <iostream>
#include <cstdlib> // for std::malloc and std::free
#include <stdexcept> // for std::out_of_range
#include <cstring> // for std::memcpy

using namespace std;


// Custom dynamic array class
class DynamicArray{
private:
    int* data; // Pointer to the array data
    size_t capacity; // Total capacity of the array
    size_t size; // Current number of elements in the array

public:
    // Constructor to initialize the dynamic array with a given capacity
    DynamicArray(size_t initial_capacity = 10) : capacity(initial_capacity), size(0) {
        data = static_cast<int*>(std::malloc(capacity * sizeof(int))); // Allocate memory for the array
        if (!data) {
            throw std::runtime_error("Memory allocation failed"); // Handle memory allocation failure
        }
    }

    // Destructor to free the allocated memory
    ~DynamicArray() {
        std::free(data); // Free the allocated memory
    }

    // Function to add an element at the end of the array
    void push_back(int value) {
        if (size == capacity) { // Check if we need to resize the array
            resize(); // Resize the array if needed
        }
        data[size++] = value; // Add the new element and increment size
    }

    // Function to remove an element at a specific index
    void remove(size_t index) {
        if (index >= size) { // Check for valid index
            throw std::out_of_range("Index out of range"); // Handle invalid index access
        }
        std::memmove(data + index, data + index + 1, (size - index - 1) * sizeof(int)); // Shift elements left
        --size; // Decrement size after removal
    }

    // Function to get the current size of the array
    size_t getSize() const {
        return size; // Return current number of elements in the array
    }

    // Function to get an element at a specific index
    int get(size_t index) const {
        if (index >= size) { // Check for valid index
            throw std::out_of_range("Index out of range"); // Handle invalid index access
        }
        return data[index]; // Return the element at the specified index
    }

    // Function to resize the array when needed
    void resize() {
        capacity *= 2; // Double the capacity
        int* new_data = static_cast<int*>(std::realloc(data, capacity * sizeof(int))); // Reallocate memory
        if (!new_data) {
            throw std::runtime_error("Memory reallocation failed"); // Handle memory reallocation failure
        }
        data = new_data; // Update the data pointer to the new memory location
    }



};
// Main function to demonstrate the usage of the DynamicArray class
int main()
{
    try {
        DynamicArray arr; // Create a dynamic array with default capacity

        // Add elements to the array
        for (int i = 0; i < 20; ++i) {
            arr.push_back(i); // Add elements from 0 to 19
        }

        // Print the elements in the array
        cout << "Elements in the array: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            cout << arr.get(i) << " "; // Access and print each element
        }
        cout << endl;

        // Remove an element at index 5
        arr.remove(7);
        cout << "After removing element at index 5: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            cout << arr.get(i) << " "; // Access and print each element after removal
        }
        cout << endl;

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl; // Handle any exceptions that occur
    }

    return 0; // Return success
}
// The code implements a custom dynamic array class in C++ that
