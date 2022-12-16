//
// Created by IIIIIIIIII on 12/12/2022.
//
#include "Customer.h"
#include <iostream>
#include<string>
#include<iomanip>
#include <cmath>
using namespace std;

string Customer::getName() const { //getting name
    return name;
}

string Customer::getAccount()const { //getting account
    return accountNumber;
}

string Customer::getAddress()const { //getting address
    return address;
}

string Customer::getCity()const { //getting city
    return city;
}

string Customer::getState()const { //getting state
    return state;
}

string Customer::getZip()const { //getting zip
    return zip;
}

string Customer::getPhone()const { //getting phone
    return phone;
}

void Customer::setName(string name) { //Setting name
 this->name = name;
}

void Customer::setAccount(string accountNumber) { //Setting account
this->accountNumber=accountNumber;
}

void Customer::setAddress(string address) {  //Setting address
    this->address = address;
}

void Customer::setCity(string city) { //Setting city
    this->city=city;
}

void Customer::setState(string state) { //Setting state
    this->state=state;
}

void Customer::setZip(string zip) { //Setting zip
    this->zip=zip;
}

void Customer::setPhone(string phone) { //Setting phone
    this->phone=phone;
}

Customer::Customer(string name, string account, string address, string city, string state, string zip, string phone) {
    this->setName(std::move(name));
    this->setAccount(account);
    this->setAddress(std::move(address));
    this->setCity(std::move(city));
    this->setState(std::move(state));
    this->setZip(zip);
    this->setPhone(phone);
}

Customer::~Customer() {

}

void Customer::print() { //Printing the customer information
    // Setting the width of each column
    const int nameWidth = 20;
    const int accountNumberWidth = 10;
    const int addressWidth = 25;
    const int cityWidth = 15;
    const int stateWidth = 10;
    const int zipWidth = 15;
    const int phoneWidth = 15;

    // Using setw to align the data in each column
    cout << left << setw(nameWidth)  << name ;
    cout << left << setw(accountNumberWidth)  << accountNumber ;
    cout << left << setw(addressWidth) << address ;
    cout << left << setw(cityWidth) << city ;
    cout << left << setw(stateWidth) << state ;
    cout << left << setw(zipWidth)<< zip ;
    cout << left << setw(phoneWidth) << phone << endl;
}
