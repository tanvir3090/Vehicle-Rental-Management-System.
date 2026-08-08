#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
protected:

    int vehicleId;
    string vehicleName;
    string vehicleType;
    double rentPerDay;
    bool isAvailable;

public:
    Vehicle() {
        vehicleId = 0;
        vehicleName = " ";
        vehicleType = " ";
        rentPerDay = 0.0;
        isAvailable = true;
    }
       Vehicle(int id, string name, string type, double rent) {
         vehicleId = id;
         vehicleName = name;
         vehicleType = type;
         rentPerDay = rent;
         isAvailable = true;
    }

    virtual ~Vehicle() {}

    int getVehicleId() {

      return vehicleId;
         }

    string getVehicleName() {

        return vehicleName;
    }

    string getVehicleType() {

        return vehicleType;
    }

    double getRentPerDay() {

        return rentPerDay;
    }

    bool getAvailability() {

        return isAvailable;
    }

    void setAvailability(bool status)
    {
        isAvailable = status;
    }

    virtual void showDetails() = 0;

    virtual double calculateRent(int numberOfDays)  {
        return rentPerDay * numberOfDays;
    }
      };

class Car : public Vehicle
{
public:
    Car() {
      vehicleId = 0;
        vehicleName = " ";
        vehicleType = " ";
        rentPerDay = 0.0;
        isAvailable = true;
    }

    Car(int id, string name, double rent)
    {
        vehicleId = id;
        vehicleName = name;
        vehicleType = "Car";
        rentPerDay = rent;
        isAvailable = true;
    }

    ~Car() {}

    void showDetails() {
        cout << "Vehicle ID    : " <<vehicleId <<endl;
        cout << "Vehicle Name  : " <<vehicleName <<endl;
        cout << "Vehicle Type  : " <<vehicleType <<endl;
        cout << "Rent Per Day  : " <<rentPerDay << "Taka" <<endl;

        if(isAvailable == true)

            cout << "Status : Available" <<endl;
         else
            cout << "Status : Rented" <<endl;
            }

       double calculateRent(int numberOfDays) {
        double serviceCharge = 100;
        double totalRent =(rentPerDay * numberOfDays) + serviceCharge;
        return totalRent;
    }
};

class Bike : public Vehicle {
public:
    Bike() {}

    Bike(int id, string name, double rent) {
        vehicleId = id;
        vehicleName = name;
        vehicleType = "Bike";
        rentPerDay = rent;
        isAvailable = true;
       }

    ~Bike() {}

    void showDetails() {
        cout << "Vehicle ID    : "<< vehicleId <<endl;
        cout << "Vehicle Name  : "<< vehicleName <<endl;
        cout << "Vehicle Type  : "<< vehicleType <<endl;
        cout << "Rent Per Day  : "<< rentPerDay << "Taka" <<endl;

        if(isAvailable == true)

             cout << "Status : Available" <<endl;
         else
            cout << "Status : Rented" <<endl;
            }

    double calculateRent(int numberOfDays)
    {
        double totalRent = rentPerDay * numberOfDays;
        return totalRent;
    }
};

class Customer {
private:
    int customerId;
    string customerName;
    string customerPhone;
public:

    Customer() {

        customerId = 0;
        customerName = "";
        customerPhone = "";
    }

      Customer(int id, string name, string phone) {
        customerId = id;
        customerName = name;
        customerPhone = phone;
            }

    ~Customer() {}

    int getCustomerId()
    {
        return customerId;
    }

    string getCustomerName()
    {
        return customerName;
    }

    string getCustomerPhone()
    {
        return customerPhone;
    }

    void showDetails() {
        cout << "Customer ID    : " <<customerId << endl;
        cout << "Customer Name  : " <<customerName << endl;
        cout << "Phone Number   : " <<customerPhone << endl;
    }
};

class Rental
{
private:
    int rentalId;
    int customerId;
    int vehicleId;
    string customerName;
    string vehicleName;
    int numberOfDays;
    double totalCost;
    bool isReturned;

public:
    Rental(){
        rentalId = 0;
        customerId = 0;
        vehicleId = 0;
        customerName = " ";
        vehicleName = " ";
        numberOfDays = 0;
        totalCost = 0.0;
        isReturned = false;
    }

    Rental(int rId, int cId, int vId, string cName, string vName, int days, double cost)
    {
        rentalId = rId;
        customerId = cId;
        vehicleId = vId;
        customerName = cName;
        vehicleName = vName;
        numberOfDays = days;
        totalCost = cost;
        isReturned = false;
    }

    ~Rental() {}

    int getRentalId(){

        return rentalId;
    }

    int getCustomerId() {

        return customerId;
    }

    int getVehicleId() {

        return vehicleId;
    }

    string getCustomerName() {

        return customerName;
    }

    string getVehicleName() {

        return vehicleName;
    }

    int getNumberOfDays() {

        return numberOfDays;
    }

    double getTotalCost() {

        return totalCost;
    }

    bool getReturnStatus() {

        return isReturned;
    }

    void setReturnStatus(bool status)
    {
        isReturned = status;
    }

    void showDetails() {
        cout << "Rental ID      : " <<rentalId << endl;
        cout << "Customer ID    : " <<customerId << endl;
        cout << "Customer Name  : " <<customerName << endl;
        cout << "Vehicle ID     : " <<vehicleId << endl;
        cout << "Vehicle Name   : " <<vehicleName << endl;
        cout << "Number of Days : " <<numberOfDays << endl;
        cout << "Total Cost     : " <<totalCost << " Taka" <<endl;

        if(isReturned == true)

            cout << "Return Status  : Returned" << endl;

        else
             cout << "Return Status  : Not Returned Yet" << endl;
        }
};

template <class T>
void displayAllRecords(vector<T>&recordList) {

    if(recordList.size() == 0) {
        cout << "No records found." <<endl;
        return;
    }

    for(int i = 0; i<recordList.size(); i++)
    {
        cout << "-----------------------------------" <<endl;
        recordList[i].showDetails();
    }
      cout << "-----------------------------------" <<endl;
}

void displayAllVehicles(vector<Vehicle*> &vehicleList) {

    if(vehicleList.size() == 0){
        cout << "No vehicles found." << endl;
        return;
    }

    for(int i = 0; i < vehicleList.size(); i++) {
        cout << "-----------------------------------" <<endl;
        vehicleList[i]->showDetails();
    }
    cout <<"-----------------------------------" <<endl;
}

void saveVehicles(vector<Vehicle*> &vehicleList, string fileName) {
       ofstream outFile(fileName);

    for(int i = 0; i < vehicleList.size(); i++) {
        outFile << vehicleList[i]->getVehicleId() <<endl;
        outFile << vehicleList[i]->getVehicleName() <<endl;
        outFile << vehicleList[i]->getVehicleType() <<endl;
        outFile << vehicleList[i]->getRentPerDay() <<endl;
        outFile << vehicleList[i]->getAvailability() <<endl;
    }
       outFile.close();
    cout << "Vehicle data saved successfully in " << fileName << endl;
}

void loadVehicles(vector<Vehicle*> &vehicleList, string fileName) {
    ifstream inFile(fileName);

    if(inFile.is_open() == false) {
        cout << "No previous vehicle data found." << endl;
        return;
    }

    for(int i = 0; i < vehicleList.size(); i++) {
        delete vehicleList[i];
      }
    vehicleList.clear();

    int id;
    while(inFile >> id)
    {
        inFile.ignore();

        string name;
        getline(inFile, name);

        string type;
        getline(inFile, type);

        double rent;
       bool avail;
        inFile >> rent >> avail;

       if(type == "Car") {
            Car *newCar = new Car(id, name, rent);
            newCar->setAvailability(avail);
            vehicleList.push_back(newCar);
        }
        else if(type == "Bike") {
            Bike *newBike = new Bike(id, name, rent);
            newBike->setAvailability(avail);
            vehicleList.push_back(newBike);
        }
    }
        inFile.close();
    cout << "Vehicle data loaded successfully from " << fileName << endl;
}

void saveCustomers(vector<Customer> &customerList, string fileName)
{
    ofstream outFile(fileName);

    for(int i = 0; i < customerList.size(); i++) {

        outFile << customerList[i].getCustomerId() <<endl;
        outFile << customerList[i].getCustomerName() <<endl;
        outFile << customerList[i].getCustomerPhone() <<endl;
    }
        outFile.close();
    cout << "Customer data saved successfully in " << fileName << endl;
}

void loadCustomers(vector<Customer> &customerList, string fileName)
{
    ifstream inFile(fileName);

    if(inFile.is_open() == false)  {
        cout << "No previous customer data found." << endl;
        return;
    }
       customerList.clear();

      int id;
    while(inFile >> id)
    {
        inFile.ignore();

        string name;
        getline(inFile, name);

        string phone;
        getline(inFile, phone);

        Customer newCustomer(id, name, phone);
        customerList.push_back(newCustomer);
    }
           inFile.close();
    cout << "Customer data loaded successfully from " << fileName << endl;
}

void saveRentals(vector<Rental> &rentalList, string fileName)
{
    ofstream outFile(fileName);

    for(int i = 0; i < rentalList.size(); i++) {

        outFile << rentalList[i].getRentalId() << endl;
        outFile << rentalList[i].getCustomerId() << endl;
        outFile << rentalList[i].getVehicleId() << endl;
        outFile << rentalList[i].getCustomerName() << endl;
        outFile << rentalList[i].getVehicleName() << endl;
        outFile << rentalList[i].getNumberOfDays() << endl;
        outFile << rentalList[i].getTotalCost() << endl;
        outFile << rentalList[i].getReturnStatus() << endl;
    }
           outFile.close();
    cout << "Rental data saved successfully in " << fileName << endl;
}

void loadRentals(vector<Rental> &rentalList, string fileName)
{
    ifstream inFile(fileName.c_str());

    if(inFile.is_open() == false)
    {
        cout << "No previous rental data found." << endl;
        return;
    }
      rentalList.clear();

      int rId;
    while(inFile >> rId)
    {
        int cId;
        int vId;
        inFile >> cId >> vId;
        inFile.ignore();

        string cName;
        getline(inFile, cName);

        string vName;
        getline(inFile, vName);

        int days;
        double cost;
        int returned;
        inFile >> days >> cost >> returned;

      Rental newRental(rId, cId, vId, cName, vName, days, cost);
        newRental.setReturnStatus(returned);
        rentalList.push_back(newRental);
    }
       inFile.close();
    cout << "Rental data loaded successfully from " << fileName << endl;
}


void addVehicle(vector<Vehicle*> &vehicleList, int &nextVehicleId) {
    string name;
    double rent;
    int choice;

    cout << "Enter Vehicle Name : ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Rent Per Day : ";
    cin >> rent;

    cout << "Select Vehicle Type:" <<endl;
    cout << "1. Car" << endl;
    cout << "2. Bike" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

  if(choice == 1) {
        Car *newCar = new Car(nextVehicleId, name, rent);
        vehicleList.push_back(newCar);
        cout << "Car added successfully with ID " << nextVehicleId << endl;
        nextVehicleId = nextVehicleId + 1;
    }
    else if(choice == 2)  {
        Bike *newBike = new Bike(nextVehicleId, name, rent);
        vehicleList.push_back(newBike);
        cout << "Bike added successfully with ID " << nextVehicleId << endl;
        nextVehicleId = nextVehicleId + 1;
    }
    else {
        cout << "Invalid vehicle type. Vehicle not added." << endl;
    }
}

void customerRegistration(vector<Customer> &customerList, int &nextCustomerId) {
    string name;
    string phone;

    cout << "Enter Customer Name : ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Phone Number  : ";
    getline(cin, phone);

    Customer newCustomer(nextCustomerId, name, phone);
    customerList.push_back(newCustomer);

    cout << "Customer added successfully with ID " << nextCustomerId << endl;
    nextCustomerId = nextCustomerId + 1;
}

void rentVehicle(vector<Vehicle*> &vehicleList, vector<Customer> &customerList, vector<Rental> &rentalList, int &nextRentalId) {
    if(customerList.size() == 0)  {
        cout << "Please add a customer first." <<endl;
        return;
    }
     if(vehicleList.size() == 0) {
        cout << "Please add a vehicle first." <<endl;
        return;
    }
      int customerId;
      cout << "Enter Customer ID : ";
        cin >> customerId;

    int customerIndex = -1;
    for(int i = 0; i < customerList.size(); i++)
    {
        if(customerList[i].getCustomerId() == customerId)
        {
            customerIndex = i;
            break;
        }
    }

    if(customerIndex == -1)  {
        cout << "Customer not found." << endl;
        return;
    }

    int vehicleId;
    cout << "Enter Vehicle ID : ";
    cin >> vehicleId;

    int vehicleIndex = -1;
    for(int i = 0; i < vehicleList.size(); i++)
    {
        if(vehicleList[i]->getVehicleId() == vehicleId)
        {
            vehicleIndex = i;
            break;
        }
  }

    if(vehicleIndex == -1) {
        cout << "Vehicle not found." << endl;
        return;
    }

    if(vehicleList[vehicleIndex]->getAvailability() == false)  {
        cout << "This vehicle is already rented." << endl;
        return;
    }

    int days;
    cout << "Enter number of days : ";
    cin >> days;

    double cost = vehicleList[vehicleIndex]->calculateRent(days);

    Rental newRental(nextRentalId, customerId, vehicleId, customerList[customerIndex].getCustomerName(), vehicleList[vehicleIndex]->getVehicleName(), days, cost);
    rentalList.push_back(newRental);
    vehicleList[vehicleIndex]->setAvailability(false);
    cout << endl;

    cout << "========== Rental Summary ==========" <<endl;
    newRental.showDetails();
    cout << "=====================================" <<endl;

    nextRentalId = nextRentalId + 1;
}

void returnVehicle(vector<Vehicle*> &vehicleList, vector<Rental> &rentalList) {
    if(rentalList.size() == 0) {
        cout << "No rental records found." << endl;
        return;
    }

    int rentalId;
    cout << "Enter Rental ID to return : ";
    cin >> rentalId;

    int rentalIndex = -1;
    for(int i = 0; i < rentalList.size(); i++) {
        if(rentalList[i].getRentalId() == rentalId) {
            rentalIndex = i;
            break;
        }
    }

    if(rentalIndex == -1) {
        cout << "Rental record not found." << endl;
        return;
    }

    if(rentalList[rentalIndex].getReturnStatus() == true) {
        cout << "This vehicle is already returned." << endl;
        return;
    }

    int vehicleId = rentalList[rentalIndex].getVehicleId();

    for(int i = 0; i < vehicleList.size(); i++) {
        if(vehicleList[i]->getVehicleId() == vehicleId)
        {
            vehicleList[i]->setAvailability(true);
            break;
        }
    }

    rentalList[rentalIndex].setReturnStatus(true);

    cout << "Vehicle returned successfully." << endl;
}

     int main(){
    vector<Vehicle*> vehicleList;
    vector<Customer> customerList;
    vector<Rental> rentalList;

    int nextVehicleId = 1;
    int nextCustomerId = 1;
    int nextRentalId = 1;

    Car *sampleCar1 = new Car(nextVehicleId, "Toyota Axio", 2500);
    vehicleList.push_back(sampleCar1);
    nextVehicleId = nextVehicleId + 1;

    Car *sampleCar2 = new Car(nextVehicleId, "Honda Civic", 3000);
    vehicleList.push_back(sampleCar2);
    nextVehicleId = nextVehicleId + 1;

    Bike *sampleBike1 = new Bike(nextVehicleId, "SUZUKI GIXXER", 700);
    vehicleList.push_back(sampleBike1);
    nextVehicleId = nextVehicleId + 1;

    Bike *sampleBike2 = new Bike(nextVehicleId, "Honda CBR", 900);
    vehicleList.push_back(sampleBike2);
    nextVehicleId = nextVehicleId + 1;

    int choice;
    bool isFirstTime = true;

    cout << "===========================================" <<endl;
    cout << "     VEHICLE RENTAL MANAGEMENT SYSTEM       " <<endl;
    cout << "===========================================" <<endl;

    do {
        if(isFirstTime == true) {
            cout << endl;
            cout << "------------------ MAIN MENU -------------------" <<endl;
            cout << "1.  View Vehicles" <<endl;
            cout << "2.  Add Vehicle" <<endl;
            cout << "3.  Customer Registration" <<endl;
            cout << "4.  View Customers" <<endl;
            cout << "5.  Rent a Vehicle" <<endl;
            cout << "6.  Return a Vehicle" <<endl;
            cout << "7.  View Rental Details" <<endl;
            cout << "8.  Save All Data to File" <<endl;
            cout << "9.  Load All Data from File" <<endl;
            cout << "10. EXIT " <<endl;
            cout << "-------------------------------------------------" <<endl;
            isFirstTime = false;
        }

        cout << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        if(choice == 1)
        {
            cout << endl << "----- Vehicle List -----" << endl;
            displayAllVehicles(vehicleList);
        }
        else if(choice == 2)
        {
            addVehicle(vehicleList, nextVehicleId);
        }
        else if(choice == 3)
        {
            customerRegistration(customerList, nextCustomerId);
        }
        else if(choice == 4)
        {
            cout << endl << "----- Customer List -----" << endl;
            displayAllRecords(customerList);
        }
        else if(choice == 5)
        {
            rentVehicle(vehicleList, customerList, rentalList, nextRentalId);
        }
        else if(choice == 6)
        {
            returnVehicle(vehicleList, rentalList);
        }
        else if(choice == 7)
        {
            cout << endl << "----- Rental Details -----" << endl;
            displayAllRecords(rentalList);
        }
        else if(choice == 8)
        {
            saveVehicles(vehicleList, "vehicles.txt");
            saveCustomers(customerList, "customers.txt");
            saveRentals(rentalList, "rentals.txt");
        }
        else if(choice == 9)
        {
            loadVehicles(vehicleList, "vehicles.txt");
            loadCustomers(customerList, "customers.txt");
            loadRentals(rentalList, "rentals.txt");

            if(vehicleList.size() > 0)
            {
                nextVehicleId = vehicleList[vehicleList.size() - 1]->getVehicleId() + 1;
            }

            if(customerList.size() > 0)
            {
                nextCustomerId = customerList[customerList.size() - 1].getCustomerId() + 1;
            }

            if(rentalList.size() > 0)
            {
                nextRentalId = rentalList[rentalList.size() - 1].getRentalId() + 1;
            }
        }
        else if(choice == 10)
        {
            cout << endl << " Exiting The Program. " << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while(choice != 10);

    for(int i = 0; i < vehicleList.size(); i++)
    {
        delete vehicleList[i];
    }

    return 0;
}
