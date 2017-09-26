#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string order_request();
string account_id();
string login();
int register_id();
int credit_card();
int credit_check();
string purchase_num();
void delivery_order(string order_details, string customer_id, string credit_auth_num);


int main(void){
	string order;
	string name;
	string purch_num;

	while(1){
		order = order_request();
		name = account_id();
		while(1){
			if(credit_card() == 1){
				break;
			}
		}
		purch_num = purchase_num();
		delivery_order(order, name, purch_num);
	}

	return 0;
}

string order_request(){
	string order_num; 
	cout << "Enter in order request number: ";
	cin >> order_num;
	return order_num;
}

string account_id(){
	int choice;
	string success;
	
	cout << "--------------------\n";
	cout<< "[1] I have a login\n[2] I would like to register\nPlease select [1] or [2]: ";
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

string login(){
	string line;
	string username;
	string password;
	string user_pass;

	fstream accounts;
	accounts.open ("accounts.txt");

	cout << "**********Login**********\n";
	cout << "Enter in Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	user_pass = username + "/" + password;
	

	while(getline(accounts, line)) {
		if(line.find(user_pass) != string::npos){
			return username;
			//user and pass are correct
		}
	}
	return "0";
}

int register_id(){
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

int credit_card(){
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
				return 1;//go to next step
			}else if(ans == 1){
				return 0;
			}
		}

	}

}

int credit_check(){
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

string purchase_num(){
	int rand_int = rand();
	return (to_string(rand_int));

}

void delivery_order(string order_details, string customer_id, string credit_auth_num){
	string confirm;

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
	}
}
