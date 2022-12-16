#include "Customer.h"
#include "purchases.h"
#include <iostream>
#include <vector>
#include <fstream>
#include<iomanip>
#include <cctype>

using namespace std;

void showMenu();
void greeting();
void printCustomers(vector<Customer> &customers);
void loadCustomer(vector<Customer> &customers);
void loadPurchases(vector<purchases> &customerPurchases);
void addPurchases(vector<purchases> &customerPurchases,vector<Customer> &customers);
void writeCustomers(vector<Customer> &customers);
void writePurchases(vector<purchases> &customerPurchases);
void writeCustomersNew(vector<Customer> &customers);
void writePurchasesNew(vector<purchases> &customerPurchases);
void printSpecificCustomer(vector<Customer> &customers);
void printHeaders();
void addNewCustomer(vector<Customer> &customers);
void deleteCustomers(vector<Customer> &customers);
void updateCustomer(vector<Customer> &customers);

int main() {
    char choice; //variable to store the users choice
    greeting(); //Greeting the user
    vector<Customer> customers; //Vector to store customers
    vector<purchases> customerPurchases; //Vector to store purchases
    loadCustomer(customers); //Loading the Customers
    loadPurchases(customerPurchases); //Loading the purchases
    do {
        showMenu();//Function to Show the main menu
        OPT:
        cin >> choice; //Taking input from user
        if (cin.fail() || cin.bad()) { //error handling
            cout << "Invalid Input! Please try again. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto OPT;
        }
        switch (choice) {
            case '1': //Print all customers
                cout << "\n";
                cout << setw(20) << left << "Name" << setw(10) << left << "Account#" << setw(25) << left << "Address"
                     << setw(15) << left << "City" << setw(10) << left << "State" << setw(15) << left << "Zip"
                     << setw(15) << left << "Phone" << endl;//Formatting
                printCustomers(customers); //Function to print all customers
                break;  //break statement
            case '2': {  //case statement
                cout << "How do you want to sort the customers? " << endl;
                cout << "1. Descending by account number" << endl;   //case statement
                cout << "2. Ascending by account number" << endl;   //case statement
                cout << "3. Ascending by name" << endl; //case statement
                cout << "4. Descending by name" << endl; //case statement
                cout << "5. Back to Main Menu" << endl;   //case statement
                cout << "Enter your choice: ";   //case statement
                char choice2;   //case statement
                CHOICE2:
                cin >> choice2;   //case statement
                if (cin.fail() || cin.bad()) {   //case statement
                    cout << "Invalid Input! Please try again. " << endl;   //case statement
                    cin.clear();   //case statement
                    cin.ignore(10000, '\n');   //case statement
                    goto CHOICE2;   //case statement
                }   //case statement
                switch (choice2) {  //case statement
                    case '1':
                        //sort vector in ascending order by account number
                        sort(customers.begin(), customers.end(),
                             [](Customer &a, Customer &b) { return a.getAccount() > b.getAccount(); });
                        cout << "\n";
                        for (int i = 0; i < customers.size(); i++) { //For loop to print the customers
                            customers[i].print(); //Function to print the customers
                        }
                        break;  //case statement
                    case '2':
                        //sort vector in descending order by account number
                        sort(customers.begin(), customers.end(),
                             [](Customer &a, Customer &b) { return a.getAccount() < b.getAccount(); });
                        cout << "\n";
                        for (int i = 0; i < customers.size(); i++) { //For loop to print the customers
                            customers[i].print(); //Function to print the customers
                        }
                        break;  //case statement
                    case '3':
                        //sort vector in ascending order by name
                        sort(customers.begin(), customers.end(),
                             [](Customer &a, Customer &b) { return a.getName() > b.getName(); });
                        cout << "\n";
                        for (int i = 0; i < customers.size(); i++) { //For loop to print the customers
                            customers[i].print(); //Function to print the customers
                        }
                        break;  //case statement
                    case '4':
                        //sort vector in descending order by name
                        sort(customers.begin(), customers.end(),
                             [](Customer &a, Customer &b) { return a.getName() < b.getName(); });
                        cout << "\n";
                        for (int i = 0; i < customers.size(); i++) { //For loop to print the customers
                            customers[i].print(); //Function to print the customers
                        }
                        break;  //case statement
                    case '5':
                        break;
                    default:
                        cout << "Invalid Input! Please try again. " << endl;
                        goto CHOICE2;
                }
            }
                break;
            case '3':   //case statement
                printSpecificCustomer(customers); //Function to print specific customer
                break;  //break statement
            case '4': {
                //case statement
                int purchaseTotal = 0;  //case statement
                for (int i = 0; i < customerPurchases.size(); i++) {
                    customerPurchases[i].print(); //Function to print the purchases
                    purchaseTotal += stoi(customerPurchases[i].getPrice()); //Function to get the total
                }//Function to print the purchases
                cout << "Total spending of all customers: $" << purchaseTotal << endl; //Printing the total
                break;  //break statement
            }
            case '5':   //case statement
                printSpecificCustomer(customers); //Function to print specific customer
                break;  //break statement
            case '6':   //case statement
                addNewCustomer(customers); //Function to add new customer
                break;  //break statement
            case '7':   //case statement
                deleteCustomers(customers); //Function to write to file
                break;  //break statement
            case '8':   //case statement
                updateCustomer(customers); //Function to write to file
                break;  //break statement
            case '9':   //case statement
                addPurchases(customerPurchases,customers); //Function to write to file
                break;  //break statement
            case'w':   //case statement
               //ask if user want to overwrite or create a new file
                cout << "Do you want to overwrite the file or create a new file? " << endl; //Printing the message
                cout << "1. Overwrite" << endl; //Printing the message
                cout << "2. Create a new file" << endl; //Printing the message
                cout << "Enter your choice: "; //Printing the message
                char choice3; //Variable to store the choice
                CHOICE3:
                cin >> choice3; //Taking input from user
                if (cin.fail() || cin.bad()) { //error handling
                    cout << "Invalid Input! Please try again. " << endl; //Printing the message
                    cin.clear(); //error handling
                    cin.ignore(10000, '\n'); //error handling
                    goto CHOICE3; //error handling
                }
                switch (choice3) { //switch statement
                    case '1':
                        writeCustomers(customers); //Function to write to file
                        writePurchases(customerPurchases); //Function to write to file
                        cout<<"File saved successfully"<<endl; //Printing the message //Function to write to file
                        break; //break statement
                    case '2':
                        writeCustomersNew(customers); //Function to write to file
                        writePurchasesNew(customerPurchases); //Function to write to file
                        cout<<"File saved successfully"<<endl; //Printing the message
                        break; //break statement
                    default:
                        cout << "Invalid Input! Please try again. " << endl; //Printing the message
                        goto CHOICE3; //error handling
                }
                break;  //break statement
            default:    //default statement
                cout << "Invalid Input! The program will now exit " << endl;
                break;  //break statement
        }
    } while (choice != 'q'|| choice != 'Q'); //do while loop
}
void greeting(){

    string welcome = "Welcome to the JJJound apparels ";
    string select = "Please select an option from the menu below";
    cout << setw(100)<< welcome << endl;
    cout << setw(105)<< select<< endl;
}
void showMenu(){

    cout << setw(85)<< "Menu" << endl;
    cout << "1.  Print all customers" << endl;
    cout << "2.  Sort and print Customer list in ascending or descending order " << endl;
    cout << "3.  Print out a specific customers account information" << endl;
    cout << "4.  Print the total spending for all customer\'s purchases" << endl;
    cout << "5.  Print specific customer\'s account information" << endl;
    cout << "6.  Add a new customer" << endl;
    cout << "7.  Delete customer\'s information" << endl;
    cout << "8.  Update customer\'s information" << endl;
    cout << "9.  Add new purchase\'s" << endl;
    cout << "w. Save File" << endl;
    cout << "Q.  Quit" << endl;
}
void printCustomers(vector<Customer> &customers){

    for (int i = 0; i < customers.size(); i++) { //For loop to print the customers
        customers[i].print(); //Function to print the customers
    }
}
void writeCustomers(vector<Customer> &customers){
    ofstream outFile;
    outFile.open("newFIle.txt",ofstream::out | ofstream::trunc);
    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    for (int i = 0; i < customers.size(); i++) {
        outFile << customers[i].getName() << "," << customers[i].getAddress() << "," << customers[i].getCity() << "," << customers[i].getState() << "," << customers[i].getZip() << "," << customers[i].getPhone() << "," << customers[i].getAccount() << ";" << endl;
    }
    outFile.close();
}
void writeCustomersNew(vector<Customer> &customers){
    ofstream outFile;
    outFile.open("customersUpdated.txt",ofstream::out | ofstream::trunc);
    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    for (int i = 0; i < customers.size(); i++) {
        outFile << customers[i].getName() << "," << customers[i].getAddress() << "," << customers[i].getCity() << "," << customers[i].getState() << "," << customers[i].getZip() << "," << customers[i].getPhone() << "," << customers[i].getAccount() << ";" << endl;
    }
    outFile.close();
}
void writePurchases(vector<purchases> &customerPurchases){
    ofstream outFile;
    outFile.open("newFile.csv",ofstream::out | ofstream::trunc);
    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    for (int i = 0; i < customerPurchases.size(); i++) {
        outFile << customerPurchases[i].getCustomerName() << "," << customerPurchases[i].getAccountNumber() << "," << customerPurchases[i].getItem()<<", "<< customerPurchases[i].getDate()<<"," << customerPurchases[i].getPrice()<<";" << endl;
    }
    outFile.close();
}
void writePurchasesNew(vector<purchases> &customerPurchases){
    ofstream outFile;
    outFile.open("purchasesUpdated.csv",ofstream::out | ofstream::trunc);
    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    for (int i = 0; i < customerPurchases.size(); i++) {
        outFile << customerPurchases[i].getCustomerName() << "," << customerPurchases[i].getAccountNumber() << "," << customerPurchases[i].getItem()<<", "<< customerPurchases[i].getDate()<<"," << customerPurchases[i].getPrice()<<";" << endl;
    }
    outFile.close();
}
void printSpecificCustomer(vector<Customer> &customers){
    string accountNumber;
    bool found =false;
    ACNUMBER:
    cout << "Please enter the account number of the customer you would like to print or press q to go back: ";
    cin >> accountNumber;
    if(accountNumber == "q"){
        return;
    }
    if (cin.fail() || cin.bad()) {   //case statement
        cout << "Wrong Input! Please try again " << endl;   //case statement
        cin.clear();   //case statement
        cin.ignore(10000, '\n');   //case statement
        goto ACNUMBER;   //case statement
    }   //case statement
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getAccount() == accountNumber) {
            cout<<"\n";
            printHeaders();
            customers[i].print();//Function to print the customers
            found = true;
        }
    }
    if (!found) {
        cout << "Customer not found!" << endl;
        goto ACNUMBER;
    }

}
void printHeaders(){
    cout<<setw(20)<<left<<"Name"<<setw(10)<<left<<"Account#"<<setw(25)<<left<<"Address"<<setw(15)<<left<<"City"<<setw(10)<<left<<"State"<<setw(15)<<left<<"Zip"<<setw(15)<<left<<"Phone"<<endl;//Formatting
}
void loadCustomer(vector<Customer> &customers){
    ifstream inFile;
    inFile.open("customers.csv");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);

        // Parse the line and extract the values
        string name;
        string accountNumber;
        string address;
        string city;
        string state;
        string zip;
        string phone;
        getline(ss, name, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, phone, ',');
        getline(ss, accountNumber, ';');
        Customer customer(name, accountNumber, address, city, state, zip, phone);
        customers.push_back(customer);
    }
    inFile.close();
}
void loadPurchases(vector<purchases> &customerPurchases){
    ifstream inFile;
    inFile.open("purchases.csv");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        // Parse the line and extract the values
        string customerName;
        string accountNumber;
        string item;
        string date;
        string amount;
        getline(ss,customerName,',');
        getline(ss,accountNumber,',');
        getline(ss,item,',');
        getline(ss,date,',');
        getline(ss,amount,'\n');

        purchases purchase(customerName,accountNumber,item,date,amount);
        customerPurchases.push_back(purchase);
    }
    inFile.close();
}
void addNewCustomer(vector<Customer> &customers){
    char choice;
    string name;
    string accountNumber;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    NAME:
    cout <<"Please enter the name of the customer: "<<endl;
    cin.ignore();
    getline(cin, name);
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto NAME;
    }
    while(name.size()>20){ //char length handling
        cout<<"Customer name can't be greater than 20 characters!"<<endl;
        cin.clear();
        cout<<"Please enter valid name for the customer(0-20characters): "<<endl;
        cin.ignore();
        getline(cin,name);
    }
    ACCOUNTNUMBER:
    cout << "Please enter the account number of the customer:(4 digits) "<<endl;
    cin >> accountNumber;
    bool isValidAccount = true;
    for (char c : accountNumber) {
        if (!isdigit(c)) {
            isValidAccount = false;
            break;
        }
    }
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto NAME;
    }
    while(accountNumber.size() != 4|| !isValidAccount){ //char length handling
        cout<<"We use 4 digit account numbers! Please Enter numbers only"<<endl;
        cin.clear();
        cout<<"Please enter valid account number for the customer(4 characters): "<<endl;
        cin.ignore();
        goto ACCOUNTNUMBER;
    }
    ADDRESS:
    cout << "Please enter the address of the customer: "<<endl;
    cin.ignore();   //case statement
    getline(cin, address);   //case statement
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto ADDRESS;
    }
    while(address.size() > 20){ //char length handling
        cout<<"Address too long! "<<endl;
        cin.clear();
        cout<<"Please shorten your address(Road -> rd, Lane-> ln, Avenue-> ave): "<<endl;
        cin.ignore();
        goto ADDRESS;
    }
    CITY:
    cout << "Please enter the city of the customer: "<<endl;
    cin >> city;
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto CITY;
    }
    while(city.size() > 12){ //char length handling
        cout<<"Address too long! "<<endl;
        cin.clear();
        cout<<"Please shorten your city(12 chars max): "<<endl;
        cin.ignore();
        goto CITY;
    }
    STATE:
    cout << "Please enter the abbreviations of the customers state (New York = NY ): "<<endl;
    cin >> state;
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto STATE;
    }
    while(state.size()!= 2){ //char length handling
        cout<<"Something is not right. Make sure its 2 character abbreviation."<<endl;
        cin.clear();
        cin.ignore();
        goto STATE;
    }
    ZIP:
    cout << "Please enter the zip code of the customer: "<<endl;
    cin >> zip;
    bool isValidZip = true;
            for (char c : zip) {
                if (!isdigit(c)) {
                    isValidZip = false;
                    break;
                }
    }
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto ZIP;
    }
    while(!isValidZip){
        cout<<"Type only numbers please! "<<endl;
        cin.clear();
        cin.ignore();
        goto ZIP;
    }
    while(zip.size()!= 5){ //char length handling
        cout<<"Invalid zip.Zip codes are 5 characters long. Please Enter a valid ZIP"<<endl;
        cin.clear();
        cin.ignore();
        goto ZIP;
    }
    PHONE:
    cout << "Please enter the phone number of the customer: "<<endl;
    cin >> phone;
    bool isValidPhone = true;
    for (char c : phone) {
        if (!isdigit(c)) {
            isValidAccount = false;
            break;
        }
    }
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto PHONE;
    }
    while(phone.size()!= 10|| !isValidPhone){ //char length handling
        cout<<"Don't enter country code.Please enter 10 digits phone number"<<endl;
        cout<<"Enter numbers only!"<<endl;
        cin.clear();
        cin.ignore();
        goto PHONE;
    }
    Customer customer(name, accountNumber, address, city, state, zip, phone);
    customers.push_back(customer);
    cout << "Customer added!" << endl;
    do{
        cout << "Press q to quit or any other key to add another customer: "<<endl;
        cin >> choice;
        if(choice == 'q'){
            break;
        }
        else{
            addNewCustomer(customers);
        }
    } while (choice!= 'q');
}
void deleteCustomers(vector<Customer> &customers){
    string accountNumber;
    cout << "Please enter the account number of the customer you want to delete: "<<endl;
    cin >> accountNumber;
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].getAccount() == accountNumber){
            customers.erase(customers.begin() + i);
            cout << "Customer deleted!" << endl;
            break;
        }
    }
}
void updateCustomer(vector<Customer> &customers){
    string accountNumbertoUpdate;
    UPDATE:
    cout << "Please enter the account number of the customer you want to update: "<<endl;
    cin >> accountNumbertoUpdate;
    if(cin.fail() || cin.bad()) { //error handling
        cout << "Invalid Input! Please try again. " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        goto UPDATE;
    }
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].getAccount() == accountNumbertoUpdate){
            string name;
            string accountNumber;
            string address;
            string city;
            string state;
            string zip;
            string phone;
            NAME:
            cout <<"Please enter the name of the customer: "<<endl;
            cin.ignore();
            getline(cin, name);
            if(cin.fail() || cin.bad()) { //error handling
                cout << "Invalid Input! Please try again. " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto NAME;
            }
            while(name.size()>20){ //char length handling
                cout<<"Customer name can't be greater than 20 characters!"<<endl;
                cin.clear();
                cout<<"Please enter valid name for the customer(0-20characters): "<<endl;
                cin.ignore();
                getline(cin,name);
            }
            customers[i].setName(name);
            ACCOUNT:
            cout << "Please enter the account number of the customer: "<<endl;
            cin >> accountNumber;
            bool isValidAccount = true;
            for (char c : accountNumber) {
                if (!isdigit(c)) {
                    isValidAccount = false;
                    break;
                }
            }
            if(cin.fail() || cin.bad()) { //error handling
                cout << "Invalid Input! Please try again. " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto ACCOUNT;
            }
            while(accountNumber.size()!= 4|| !isValidAccount){ //char length handling
                cout<<"Account numbers are 4 digits long. Please Enter a valid account number"<<endl;
                cin.clear();
                cin.ignore();
                goto ACCOUNT;
            }
            customers[i].setAccount(accountNumber);
            ADDRESS:
            cout << "Please enter the address of the customer: "<<endl;
            cin.ignore();
            getline(cin, address);
            if(cin.fail() || cin.bad()) { //error handling
                cout << "Invalid Input! Please try again. " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto ADDRESS;
            }
            while(address.size()>30){ //char length handling
                cout<<"Customer address can't be greater than 30 characters!"<<endl;
                cin.clear();
                cout<<"Please enter valid address for the customer(0-30characters): "<<endl;
                cin.ignore();
                getline(cin,address);
            }
            customers[i].setAddress(address);
            CITY:
            cout << "Please enter the city of the customer: "<<endl;
            cin.ignore();
            getline(cin, city);
            if(cin.fail() || cin.bad()) { //error handling
                cout << "Invalid Input! Please try again. " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto CITY;
            }
            while(city.size()>20){ //char length handling
                cout<<"Customer city can't be greater than 20 characters!"<<endl;
                cin.clear();
                cout<<"Please enter valid city for the customer(0-20characters): "<<endl;
                cin.ignore();
                getline(cin,city);
            }
            customers[i].setCity(city);
            STATE:
            cout << "Please enter the state of the customer: "<<endl;
            cin.ignore();
            getline(cin, state);
            if(cin.fail() || cin.bad()) { //error handling
                cout << "Invalid Input! Please try again. " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto STATE;
            }
            while(state.size()!=2){ //char length handling
                cout<<"Customer state can't be greater or less than 2 characters!"<<endl;
                cin.clear();
                cout<<"Please enter valid state for the customer(2characters): "<<endl;
                cin.ignore();
                getline(cin,state);
            }
            customers[i].setState(state);
            ZIP:
            cout << "Please enter the zip code of the customer: "<<endl;
            cin >> zip;
            bool isValidZip = true;
            for (char c : zip) {
                if (!isdigit(c)) {
                    isValidZip = false;
                    break;
                }
            }
            if(cin.fail() || cin.bad()) { //error handling
                cout << "Invalid Input! Please try again. " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto ZIP;
            }
            while(zip.size()!= 5|| !isValidZip){ //char length handling
                cout<<"Zip codes are 5 digits long. Please Enter a valid zip code"<<endl;
                cin.clear();
                cin.ignore();
                goto ZIP;
            }
            customers[i].setZip(zip);
            PHONE:
            cout << "Please enter the phone number of the customer: "<<endl;
            cin >> phone;
            bool isValidPhone = true;
            for (char c : phone) {
                if (!isdigit(c)) {
                    isValidPhone = false;
                    break;
                }
            }
            if(cin.fail() || cin.bad()) { //error handling
                cout << "Invalid Input! Please try again. " << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto PHONE;
            }
            while(phone.size()!= 10|| !isValidPhone){ //char length handling
                cout<<"Phone numbers are 10 digits long. Please Enter a valid phone number"<<endl;
                cin.clear();
                cin.ignore();
                goto PHONE;
            }
            customers[i].setPhone(phone);
            cout << "Customer updated successfully!" << endl;
            break;
        }
    }
}
void addPurchases(vector<purchases> &customerPurchases, vector<Customer> &customers){
        //add purchases
        string accountNumber;
        string date;
        string item;
        string quantity;
        string amount;
        char choice;
        string customerName;
        ADDPURCHASE:
        cout << "Please enter the account number of the customer: "<<endl;
        cin >> accountNumber;
        bool isValidAccount = true;
        for (char c : accountNumber) {
            if (!isdigit(c)) {
                isValidAccount = false;
                break;
            }
        }
        if(cin.fail() || cin.bad()) { //error handling
            cout << "Invalid Input! Please try again. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        while(accountNumber.size()!= 4|| !isValidAccount){ //char length handling
            cout<<"Account numbers are 4 digits long. Please Enter a valid account number"<<endl;
            cin.clear();
            cin.ignore();
        }
        for(int i=0;i<customers.size();i++){
            if (accountNumber == customers[i].getAccount()){
                customerName = customers[i].getName();
            }
        }
        ITEM:
        cout << "Please enter the name of the item purchased: "<<endl;
        cin.ignore();
        getline(cin, item);
        if(cin.fail() || cin.bad()) { //error handling
            cout << "Invalid Input! Please try again. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto ITEM;
        }
        while(item.size()>20){ //char length handling
            cout<<"Item name can't be greater than 20 characters!"<<endl;
            cin.clear();
            cout<<"Please enter valid item name(0-20characters): "<<endl;
            cin.ignore();
            getline(cin,item);
        }
        DATE:
        cout << "Please enter the date of the purchase (in the format DD-MM-YYYY or like this --> 11-DEC): "<<endl;
        cin.ignore();
        getline(cin, date);
        if(cin.fail() || cin.bad()) { //error handling
            cout << "Invalid Input! Please try again. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto DATE;
        }
        while(date.size()>10){ //char length handling
            cout<<"Date can't be greater than 10 characters!"<<endl;
            cin.clear();
            cout<<"Please enter in the format DD-MM-YYYY or like this -> 11-DEC (max 10 characters): "<<endl;
            cin.ignore();
            getline(cin,date);
        }
        PRICE:
        cout << "Please enter the price of the item: "<<endl;
        cin >> amount;
        bool isValidPrice = true;
        for (char c : amount) {
            if (!isdigit(c)) {
                isValidPrice = false;
                break;
            }
        }
        if(cin.fail() || cin.bad()) { //error handling
            cout << "Invalid Input! Please try again. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            goto PRICE;
        }
        while(amount.size()> 10|| !isValidPrice){ //char length handling
            cout<<"Price can't be greater than 10 characters!"<<endl;
            cin.clear();
            cin.ignore();
            goto PRICE;
        }
    purchases purchase(customerName,accountNumber,item,date,amount);
    customerPurchases.push_back(purchase);
    cout<<"Purchase added successfully!"<<endl;
    do{
        cout<<"Would you like to add another purchase? (Y/N)"<<endl;
        cin>>choice;
        if(choice == 'Y' || choice == 'y'){
            goto ADDPURCHASE;
        }
        else if(choice == 'N' || choice == 'n'){
            break;
        }
        else{
            cout<<"Invalid input! Please try again."<<endl;
        }
    }while (choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n');
}
