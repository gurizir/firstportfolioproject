#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Vehicle {
public:
    string id;
    string type;
    double pricePerDay;
    bool isAvailable;

    Vehicle(string id, string type, double price)
        : id(id), type(type), pricePerDay(price), isAvailable(true) {}

    virtual void displayInfo() const { 
        cout << "ID: " << id << ": " << type 
             << ", Price/Day: Rs." << pricePerDay  
             << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
    
    virtual ~Vehicle() {}  
};

class Car : public Vehicle {
public:
    Car(string id, double price) : Vehicle(id, "Car", price) {}

    void displayInfo() const override {  
        cout << "Car Info - ";
        Vehicle::displayInfo();
    }
};

class Truck : public Vehicle {
public:
    Truck(string id, double price) : Vehicle(id, "Truck", price) {}

    void displayInfo() const override {
        cout << "Truck Info - ";
        Vehicle::displayInfo();
    }
};

class User {
public:
    string username;
    string password;

    User() : username(""), password("") {}

    User(string username, string password)
        : username(username), password(password) {}
};

class RentalCompany {
private:
    vector<Vehicle*> vehicles; 
    map<string, User> users;
    map<string, string> rentals; 

public:
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void registerUser(const string& username, const string& password) {
        users[username] = User(username, password);
    }

    bool authenticateUser(const string& username, const string& password) const {
        auto it = users.find(username);
        return (it != users.end() && it->second.password == password);
    }

    void displayAvailableVehicles() const {
        cout << "Available Vehicles:" << endl;
        for (const auto& vehicle : vehicles) {
            if (vehicle->isAvailable) {
                vehicle->displayInfo(); 
            }
        }
    }

    void rentVehicle(const string& vehicleId, const string& username, int days) {
        for (auto& vehicle : vehicles) {
            if (vehicle->id == vehicleId && vehicle->isAvailable) {
                vehicle->isAvailable = false;
                rentals[vehicleId] = username; 
                double totalCost = vehicle->pricePerDay * days;
                cout << "Vehicle rented successfully!" << endl;
                cout << "Total cost for " << days << " days: Rs." << totalCost << endl;
                return;
            }
        }
        cout << "Vehicle not available for rent." << endl;
    }

    void returnVehicle(const string& vehicleId, const string& username) {
        auto it = rentals.find(vehicleId);
        if (it != rentals.end() && it->second == username) {
            for (auto& vehicle : vehicles) {
                if (vehicle->id == vehicleId) {
                    vehicle->isAvailable = true;
                    rentals.erase(it);
                    cout << "Vehicle returned successfully!" << endl;
                    return;
                }
            }
        }
        cout << "This vehicle is not rented by you. Please enter a valid input." << endl;
    }

    ~RentalCompany() {
        for (auto& vehicle : vehicles) {
            delete vehicle; 
        }
    }
};

int main() {
    RentalCompany rentalCompany;

    rentalCompany.addVehicle(new Car("V001", 50.0));
    rentalCompany.addVehicle(new Truck("V002", 70.0));
    rentalCompany.addVehicle(new Car("V003", 90.0));
    rentalCompany.addVehicle(new Car("V004", 45.0));
    rentalCompany.addVehicle(new Car("V005", 65.0));
    rentalCompany.addVehicle(new Truck("V006", 80.0));
    rentalCompany.addVehicle(new Car("V007", 75.0));
    rentalCompany.addVehicle(new Car("V008", 60.0));
    rentalCompany.addVehicle(new Car("V009", 120.0));
    rentalCompany.addVehicle(new Car("V010", 100.0));
    rentalCompany.addVehicle(new Car("V011", 110.0));
    rentalCompany.addVehicle(new Car("V012", 40.0));
    rentalCompany.addVehicle(new Truck("V013", 55.0));
    rentalCompany.addVehicle(new Truck("V014", 85.0));
    rentalCompany.addVehicle(new Car("V015", 95.0));

    rentalCompany.registerUser("USER123", "PASS123");

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (rentalCompany.authenticateUser(username, password)) {
        cout << "Login successful!" << endl;

        int choice;
        while (true) {
            cout << "\n1. View Available Vehicles\n2. Rent Vehicle\n3. Return Vehicle\n4. Exit\n";
            cout << "Enter your choice: \n";
            cin >> choice;

            if (choice == 1) {
                rentalCompany.displayAvailableVehicles();
            } else if (choice == 2) {
                string vehicleId;
                int days;
                cout << "Enter Vehicle ID to rent: ";
                cin >> vehicleId;
                cout << "Enter number of days: ";
                cin >> days;
                rentalCompany.rentVehicle(vehicleId, username, days);
            } else if (choice == 3) {
                string vehicleId;
                cout << "Enter Vehicle ID to return: ";
                cin >> vehicleId;
                rentalCompany.returnVehicle(vehicleId, username);
            } else if (choice == 4) {
                cout << "Exiting system." << endl;
                break;
            } else {
                cout << "Invalid choice, please try again." << endl;
            }
        }
    } else {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}