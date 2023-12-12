#include <iostream>
#include <list>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    string model;

public:
    Vehicle(string _brand, string _model) : brand(_brand), model(_model) {}

    virtual void display() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }

    virtual void modify() {}

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int doors;

public:
    Car(string _brand, string _model, int _doors) : Vehicle(_brand, _model), doors(_doors) {}

    void display() const override {
        cout << "Car" << endl;
        Vehicle::display();
        cout << "Doors: " << doors << endl;
    }

    void modify() override {
        doors = 5;
    }
};

class Motorcycle : public Vehicle {
protected:
    string type;

public:
    Motorcycle(string _brand, string _model, string _type) : Vehicle(_brand, _model), type(_type) {}

    void display() const override {
        cout << "Motorcycle" << endl;
        Vehicle::display();
        cout << "Type: " << type << endl;
    }

    void modify() override {
        type = "Cruiser";
    }
};

void modifyVehicle(Vehicle* v) {
    v->display();
    v->modify();
    v->display();
}

int main() {
    list<Vehicle*> vehicles;
    vehicles.push_back(new Car("Toyota", "Camry", 4));
    vehicles.push_back(new Motorcycle("Harley-Davidson", "Sportster", "Sport"));
    vehicles.push_back(new Car("Honda", "Accord", 2));

    for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
        (*it)->display();
    }

    for (auto v : vehicles) {
        delete v;
    }

    Vehicle* v1 = new Car("Ford", "Mustang", 2);
    Vehicle* v2 = new Motorcycle("Yamaha", "R1", "Sport");
    modifyVehicle(v1);
    modifyVehicle(v2);
    delete v1;
    delete v2;

    return 0;
}
