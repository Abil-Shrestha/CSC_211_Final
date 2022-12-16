//
// Created by Abil on 12/12/2022.
//

#ifndef FINAL_CSC211_CUSTOMER_H
#define FINAL_CSC211_CUSTOMER_H
#include<string>
using namespace std;

class Customer {
public:
    //Default Constructor
    Customer() = default;
    //Copy Constructor
    Customer(string name,string account,string address,string city,string state,string zip,string phone);
    //Destructor
    ~Customer();
    //Getter functions
    [[nodiscard]] string getName() const;
    [[nodiscard]] string getAccount() const;
    [[nodiscard]] string getAddress()const;
    [[nodiscard]]string getCity()const;
    [[nodiscard]]string getState()const;
    [[nodiscard]]string getZip()const;
    [[nodiscard]]string getPhone()const;
    //Setter functions
    void setName(string name) ;
    void setAccount(string account) ;
    void setAddress(string address);
    void setCity(string city);
    void setState(string state);
    void setZip(string zip);
    void setPhone(string phone);
    void print();
private:
    string name;
    string accountNumber;
    string address;
    string city;
    string state;
    string zip;
    string phone;
};

#endif //FINAL_CSC211_CUSTOMER_H
