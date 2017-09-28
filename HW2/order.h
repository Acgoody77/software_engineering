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
    static string order_request();
      //get order request from user
      //TODO: fix to select an order not enter num.
};

class PurchaseOrderManager{
  public:
    static void Pur_Man();
      //function manager;
};

class CreditCard{
  public:
    static int credit_card();
      //enter in credit card details
    static int credit_check();
      //Admin credit check of user credit card
};

class CustomerAccount{
  public:
    static string account_id();
      //customer decied to create account or login.
    static string login();
      //customer login with accounts.txt
    static int register_id();
      //customer register and save to accounts.txt
};

class DeliveryOrder{
  public:
    static string purchase_num();
      //create a purchase number for order
    static string delivery_order(string order_details, string customer_id, string credit_auth_num);
      //create and show delivery details with order
};

class EmailServiceInterface{
  public:
    static void email();
};

#endif
