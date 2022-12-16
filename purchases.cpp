//
// Created by IIIIIIIIII on 12/15/2022.
//
#include "Customer.h"
#include "purchases.h"

#include <iostream>
#include<string>
#include<iomanip>
#include <cmath>
#include <utility>

using namespace std;    //using namespace std

purchases::~purchases() = default;

purchases::purchases(string customerName,string accountNumber,string item,string date,string price) {
        this->customerName=std::move(customerName);
        this->accountNumber=std::move(accountNumber);
        this->item=std::move(item);
        this->date=std::move(date);
        this->price=price;
}

string purchases::getCustomerName() const {
    return this->customerName;
}

string purchases::getAccountNumber() const {
    return this->accountNumber;
}

string purchases::getItem() const {
    return this->item;
}

string purchases::getDate() const {
    return this->date;
}

string purchases::getPrice() const {
    return this->price;
}

void purchases::setCustomerName(string customerName) {
    this->customerName=std::move(customerName);
}

void purchases::setAccountNumber(string accountNumber) {
    this->accountNumber=std::move(accountNumber);
}

void purchases::setItem(string item) {
    this->item=std::move(item);
}

void purchases::setPrice(string price) {
    this->price=price;
}

void purchases::setDate(string date) {
    this->date=std::move(date);
}

void purchases::print() {
    //formatting output nicely for the user
    cout<<left<<setw(20)<<getCustomerName()<<setw(20)<<getItem()<<setw(20)<<getDate()<<setw(20)<<getPrice()<<endl;
}


