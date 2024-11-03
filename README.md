Project Overview
The Vehicle Rental Management System is a C++ application that simulates the operations of a rental company. It enables user registration, authentication, vehicle listing, renting, and return functionality. This project demonstrates key programming principles, including object-oriented programming (OOP) with a focus on classes, encapsulation, and structured data management.

Features
User Registration and Authentication: Secure user login with username and password.
Vehicle Management: Display available vehicles, rent vehicles for specified days, and return them to the fleet.
Dynamic Vehicle Pricing: Each vehicle type has a different rental rate per day.
Interactive User Menu: Options to view available vehicles, rent, return, or exit the system.
Code Explanation
Main Components:
Vehicle Class:

Represents a vehicle with attributes like id, type, pricePerDay, and isAvailable.
Contains a constructor for initialization and a displayInfo() method to display vehicle details.
User Class:

Represents a user with username and password.
Includes constructors for creating user objects.
RentalCompany Class:

Maintains a fleet of vehicles and a map of registered users.
Provides methods for adding vehicles, registering users, authenticating users, renting vehicles, and returning them.
Detailed Class Descriptions:
Vehicle:
Demonstrates encapsulation by managing vehicle attributes and methods within a single class.
Future improvements could involve making this class the base of a polymorphic hierarchy with derived classes for specific vehicle types.
User:
Stores user credentials and could be extended for further user attributes, like contact details.
RentalCompany:
Utilizes a vector (std::vector<Vehicle>) for managing the fleet and a map (std::map<std::string, User>) for registered users.
Methods like rentVehicle() and returnVehicle() are used to change the isAvailable status of vehicles, showcasing interaction between objects.
Execution Flow:
Initialization: The program initializes with a list of vehicles added to the RentalCompany class.
User Interaction:
The user is prompted to log in using a registered username and password.
Once authenticated, they are presented with a menu offering various options: viewing vehicles, renting, returning, or exiting.
Vehicle Operations:
displayAvailableVehicles() iterates over the fleet to show all vehicles that are available.
rentVehicle() checks for vehicle availability, processes the rental, calculates the total cost, and marks the vehicle as rented.
returnVehicle() changes the isAvailable status of a returned vehicle to true.
Programming Principles Used:
Inheritance and Polymorphism:
While the current code focuses on encapsulation and structured data management, extending the code with inheritance can create specialized vehicle types. For example, a LuxuryVehicle or ElectricVehicle class could inherit from the Vehicle base class and override specific methods such as pricing strategies or additional features.
Polymorphism can be incorporated by defining a virtual displayInfo() method in the Vehicle class. Derived classes could then implement their own displayInfo() to show additional details specific to that type (e.g., battery life for electric vehicles).
Other Principles:
Encapsulation: Each class encapsulates its attributes and related methods, promoting modular design.
Data Abstraction: The implementation hides internal details of how vehicles and users are managed, exposing only the necessary interfaces for interaction.
Composition: The RentalCompany class uses composition by including objects of Vehicle and User.