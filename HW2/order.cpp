//Function Definitions
#include <string>
#include <iostream>
#include "order.h"

using namespace std;

string CustomerInterface::order_request(){
	string order_num;
  int order_rand = rand();

  cout << "**********Item's**********\n";
  cout << "Item [1]\n Item [2]\n Item [3]\n Item [4]\n Item [5]\n"; 
	cout << "Enter in item number you want to purchase: ";
	cin >> order_num;
  int ord_n = order_rand * stoi(order_num);
  return to_string(ord_n);
    //return random order number times the order item purchased

}

//purchase order functions

int CreditCard::credit_card(){
  string credit;
  int ans;

  cout << "**********Payment**********\n";
  cout << "[cancel] or Enter in credit card number: ";
  cin >> credit;

  if(credit == "cancel"){
    return 0;
  }else{
    while(1){
      ans = credit_check();
      if(ans == 0){
        return 1;//credit is approved
      }else if(ans == 1){
        return 0;
      }
    }

  }
}

int CreditCard::credit_check(){
  string check;
  
  cout << "--------------------\n";
  cout << "Admin - Enter [yes] or [no] for credit check: ";
  cin >> check;

  if(check == "yes"){
    return 0;
  }else if(check == "no"){
    return 1;
  }else{
    cout << "not valid answer";
    return 2;
  }
}

string CustomerAccount::account_id(){
  int choice;
  string success;

  cout << "--------------------\n";
  cout << "[1] I have a login\n[2] I would like to register\nPlease select [1] or [2]: ";
  cin >> choice;

  switch(choice)
  {
    case 1:
      success = login();
      if(success != "0")
        return success;
      else
        return "0";
    case 2:
      register_id();
      success = login();
      if(success != "0")
        return success;
      else
        return "0";
    default:
      cout << "Invalid try agian\n";
      break;

  }
}

string CustomerAccount::login(){
  string line;
  string username;
  string password;
  string user_pass;

  fstream accounts;
  accounts.open("accounts.txt");

  cout << "**********Login**********\n";
  cout << "Enter in Username: ";
  cin >> username;
  cout << "Enter Password: ";
  cin >> password;

  user_pass = username + "/" + password;

  while(getline(accounts, line)) {
    if(line.find(user_pass) != string::npos){
      return username;
    }
  }
  return "0";
}

int CustomerAccount::register_id(){
  string reg_username;
  string reg_password;

  cout << "**********Registration**********\n";
  cout << "Enter in Username: ";
  cin >> reg_username;
  cout << "\nEnter in Password: ";
  cin >> reg_password;

  ofstream account("accounts.txt");
  account << reg_username << "/" << reg_password << "\n";

  return 0;
}

string DeliveryOrder::purchase_num(){
  int rand_int = rand();
  return (to_string(rand_int));
}

string DeliveryOrder::delivery_order(string order_details, string customer_id, string credit_auth_num){
  string confirm;
  string order_confirmation_num;
  int rand_order_int = rand();
  order_confirmation_num = to_string(rand_order_int);

  cout << "**********Order Details**********\n";
  cout << "Order request number: " + order_details << endl;
  cout << "Customer ID: " + customer_id << endl;
  cout << "Credit card authorization number: " + credit_auth_num << endl;

  cout << "--------------------\n";
  cout << "Confirm order [yes] or [no]: ";
  cin >> confirm;

  if(confirm == "yes"){
    cout << "Your order has been approved!" << endl;
    cout << "--------------------\n";
    cout << "Your order confirmation number is: " + order_confirmation_num << endl;
    return order_confirmation_num;
  }else
    return "noconfirm";
}

void PurchaseOrderManager::Pur_Man(){
  string order;
  string name;
  string purch_num;
  string conf_num;

  while(1){
    order = CustomerInterface::order_request();
    name = CustomerAccount::account_id();
    while(1){
      if(CreditCard::credit_card() == 1){
        break;
      }
    }
    purch_num = DeliveryOrder::purchase_num();
    conf_num = DeliveryOrder::delivery_order(order, name, purch_num);
    EmailServiceInterface::email();
  }
}

void EmailServiceInterface::email(){
  string email;
  cout << "Enter in email to send confirmation: " << endl;
  cin >> email;
  cout << "Email sent to: " + email << endl;
  cout << "*************END***************" << endl;
}
