//
// Created by IIIIIIIIII on 12/15/2022.
//

#ifndef FINAL_CSC211_PURCHASES_H
#define FINAL_CSC211_PURCHASES_H
#include<string>
using namespace std;

class purchases{
public:
    //Default Constructor
    purchases()=default;
    //Copy Constructor
    purchases(string customerName,string accountNumber,string item,string date,string price);
    //Destructor
    ~purchases();
    //Getter functions
    [[nodiscard]] string getCustomerName() const;
    [[nodiscard]] string getAccountNumber() const;
    [[nodiscard]] string getItem() const;
    [[nodiscard]] string getDate() const;
    [[nodiscard]] string getPrice()const;

    //Setter functions
    void setCustomerName(string customerName);
    void setAccountNumber(string accountNumber);
    void setItem(string item) ;
    void setPrice(string price);
    void setDate(string date);
    void print();

private:
    string customerName;
    string accountNumber;
    string item;
    string date;
    string price;
};


#endif //FINAL_CSC211_PURCHASES_H
