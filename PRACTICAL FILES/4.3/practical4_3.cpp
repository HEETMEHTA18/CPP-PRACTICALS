/*A vehicle manufacturing company sought to create a robust system to organize and manage the
details of various cars produced under its brand. To accomplish this, a hierarchical structure was
conceptualized, reflecting the essential components of a vehicle. At the foundation, a class was
designed to represent the type of fuel a vehicle uses. Another class was created to capture the brand
name of the vehicle. These two foundational elements were then combined into a derived class
specifically representing cars, integrating both fuel type and brand information.
Constructors were used at each level to ensure proper initialization of attributes, allowing seamless
integration of all details. Additionally, the ability to display complete information about a car, including
its fuel type and brand, was incorporated into the system. To simulate a real-world scenario such as a
service queue, multiple cars were organized and processed sequentially using a structured approach.
This not only streamlined the handling of cars but also provided an opportunity to compare different
methods of managing the collection and processing of vehicle data.*/
#include <iostream>
#include <vector>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(string f): fuelType(f) {}
};

class Brand {
protected:
    string brandName;
public:
    Brand(string b): brandName(b) {}
};

class Car : public Fuel, public Brand {
    int carID;
public:
    Car(int id, string f, string b): Fuel(f), Brand(b), carID(id) {}
    void display() {
        cout << "Car ID: " << carID << ", Fuel: " << fuelType << ", Brand: " << brandName << endl;
    }
};

int main(){
    vector<Car> cars;
    cars.push_back(Car(1, "Petrol", "Defender"));
    cars.push_back(Car(2, "Diesel", "Ford"));
    cars.push_back(Car(3, "Electric", "Tesla"));
    for(auto &car : cars)
        car.display();
    return 0;
}
