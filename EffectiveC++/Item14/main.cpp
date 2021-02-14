#include <iostream>

class Vehicle
{
    public:
        Vehicle() {}
        Vehicle(std::string model): m_model(model)
        {
            ++m_totalVehicles;
            std::cout << "Vehicles: " << m_totalVehicles << std::endl;
        }
        virtual ~Vehicle()
        {
            --m_totalVehicles;
            std::cout << "Vehicle Destructor: " << m_totalVehicles << std::endl;
        }

    private:
        std::string m_model;
        static size_t m_totalVehicles;
};
size_t Vehicle::m_totalVehicles; // Defining static variable outisde of the class, 0 by default

class Car : public Vehicle
{
    public:
        Car(std::string model): m_model(model)
        { 
            ++m_totalCars; 
            std::cout << "Cars:" << m_totalCars << std::endl;
        }
        ~Car()
        {
             --m_totalCars;
             std::cout << "Car Destructor: " << m_totalCars << std::endl;
        }

    private:
        std::string m_model;
        static size_t m_totalCars;
};
size_t Car::m_totalCars; // Defining static variable outside of the class, 0 by default


/**
 * Make sure base classes have virtual destructors!
 * When we try to destroy a derived class through a BASE CLASS POINTER, and the base class
 * has a non virtual destructor, the resuls are undefined.
 * 
 * If I didn't declare the destructor of vehicle to be virtual, the car destructor would've never been called.
 * And it only calls the vehicle destructor. Which would make the behavior of counting cars, wrong.
 * 
 * Then if I add the "virtual" keyword to the destructor of Vahicle, the destructor for Car is correctly called.
 */ 

int main()
{
    Vehicle* v1 = new Car("Ford Focus");
    delete v1;
}