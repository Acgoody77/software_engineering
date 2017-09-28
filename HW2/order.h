//Header file

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ORDER_H
#define ORDER_H

class CustomerInterface{
  public:
    string order_request();
      //get order request from user
      //TODO: fix to select an order not enter num.
};

class PurchaseOrderManager{
  //TODO:create "function manager"
};

class CreditCard{
  public:
    int credit_card();
      //enter in credit card details
    int credit_check();
      //Admin credit check of user credit card
};

class CustomerAccount{
  public:
    string account_id();
      //customer decied to create account or login.
    string login();
      //customer login with accounts.txt
    int register_id();
      //customer register and save to accounts.txt
};

class DeliveryOrder{
  public:
    string purchase_num();
      //create a purchase number for order
    void delivery_order(string order_details, string customer_id, string credit_auth_num);
      //create and show delivery details with order
      //TODO: return a order confirmation to purchase order man
};

class EmailServiceInterface{
  //TODO:create email 
};

#endif
