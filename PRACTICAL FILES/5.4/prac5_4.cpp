#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius {
private:
    double temp;
public:
    Celsius(double t = 0) : temp(t) {}

    double getTemp() const { return temp; }

    // Convert Celsius to Fahrenheit
    operator Fahrenheit();

    // Overload == to compare with Fahrenheit
    bool operator==(const Fahrenheit& f);
};

class Fahrenheit {
private:
    double temp;
public:
    Fahrenheit(double t = 32) : temp(t) {}

    double getTemp() const { return temp; }

    // Convert Fahrenheit to Celsius
    operator Celsius() {
        return Celsius((temp - 32) * 5.0 / 9.0);
    }

    // Overload == to compare with Celsius
    bool operator==(const Celsius& c) {
        return temp == (c.getTemp() * 9.0 / 5.0 + 32);
    }
};

// Define Celsius to Fahrenheit conversion
Celsius::operator Fahrenheit() {
    return Fahrenheit(temp * 9.0 / 5.0 + 32);
}

// Define Celsius == Fahrenheit
bool Celsius::operator==(const Fahrenheit& f) {
    return temp == ((f.getTemp() - 32) * 5.0 / 9.0);
}

// FIFO approach using queue
queue<Fahrenheit> tempQueue;

void processQueueConversion(Celsius cTemp) {
    Fahrenheit fTemp = cTemp; // Implicit conversion
    tempQueue.push(fTemp);
}

// Static approach using array
Fahrenheit tempArray[100];
int index = 0;

void processArrayConversion(Celsius cTemp) {
    if (index < 100) {
        tempArray[index++] = cTemp; // Implicit conversion
    }
}

// Main driver code
int main() {
    // Conversion Test
    Celsius c1(25);
    Fahrenheit f1 = c1;
    cout << "25*C = " << f1.getTemp() << "*F\n";

    Fahrenheit f2(77);
    Celsius c2 = f2;
    cout << "77*F = " << c2.getTemp() << "*C\n";

    // Comparison
    if (c1 == f2) {
        cout << "c1 and f2 represent the same temperature.\n";
    } else {
        cout << "c1 and f2 are different.\n";
    }

    // Queue-based temperature conversion
    cout << " Queue-Based Conversion ";
    processQueueConversion(Celsius(30));
    processQueueConversion(Celsius(40));
    processQueueConversion(Celsius(0));

    while (!tempQueue.empty()) {
        cout << "Queue Temp in Fahrenheit: " << tempQueue.front().getTemp() << " *F\n";
        tempQueue.pop();
    }

    // Array-based temperature conversion
    cout << " Array-Based Conversion ";
    processArrayConversion(Celsius(10));
    processArrayConversion(Celsius(20));
    processArrayConversion(Celsius(15));

    for (int i = 0; i < index; i++) {
        cout << "Array Temp in Fahrenheit: " << tempArray[i].getTemp() << "*F\n";
    }

    return 0;
}
