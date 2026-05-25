#include<iostream>
#include"clsBankClient.h"

using namespace std;

int main()
{
	clsBankClient client1 = clsBankClient::find("A101");//find by just account number 
	client1.print();

	clsBankClient client2 = clsBankClient::find("A1010", "1234");//find by account number & pin code

	client2.print();
	 
}
