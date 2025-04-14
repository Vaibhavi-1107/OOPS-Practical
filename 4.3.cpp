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
#include <string>
#include <vector>
#include <queue>
using namespace std;

// Base class: Fuel type
class FuelType {
protected:
    string fuel;
public:
    FuelType(const string& fuel) : fuel(fuel) {}
    virtual void displayFuel() const {
        cout << "Fuel Type: " << fuel << endl;
    }
};

// Base class: Brand
class Brand {
protected:
    string brandName;
public:
    Brand(const string& brandName) : brandName(brandName) {}
    virtual void displayBrand() const {
        cout << "Brand: " << brandName << endl;
    }
};

// Derived class: Car (inherits from both FuelType and Brand)
class Car : public FuelType, public Brand {
private:
    string model;
public:
    Car(const string& fuel, const string& brandName, const string& model)
        : FuelType(fuel), Brand(brandName), model(model) {}

    void displayCarInfo() const {
        cout << "Model: " << model << endl;
        displayBrand();
        displayFuel();
        cout << "--------------------------" << endl;
    }

    string getModel() const {
        return model;
    }
};

// --- Approach 1: Service queue using std::queue (FIFO) ---
class CarServiceQueue {
private:
    queue<Car> serviceQueue;
public:
    void addCarToQueue(const Car& car) {
        serviceQueue.push(car);
    }

    void processQueue() {
        cout << "\nProcessing cars in service queue (FIFO):" << endl;
        while (!serviceQueue.empty()) {
            serviceQueue.front().displayCarInfo();
            serviceQueue.pop();
        }
    }
};

// --- Approach 2: Using std::vector for collection processing ---
class CarVectorManager {
private:
    vector<Car> cars;
public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void displayAllCars() const {
        cout << "\nDisplaying all cars from vector:" << endl;
        for (const auto& car : cars) {
            car.displayCarInfo();
        }
    }
};

// --- Demo ---
int main() {
    Car car1("Petrol", "Toyota", "Corolla");
    Car car2("Diesel", "Ford", "F-150");
    Car car3("Electric", "Tesla", "Model S");

    // Using queue for service simulation
    CarServiceQueue serviceQueue;
    serviceQueue.addCarToQueue(car1);
    serviceQueue.addCarToQueue(car2);
    serviceQueue.addCarToQueue(car3);
    serviceQueue.processQueue();

    // Using vector for general car collection
    CarVectorManager vectorManager;
    vectorManager.addCar(car1);
    vectorManager.addCar(car2);
    vectorManager.addCar(car3);
    vectorManager.displayAllCars();
    cout<<"Vaibhavi 24CE053";
    return 0;
}
