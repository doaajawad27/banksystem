#include<iostream>
#include"clsLoginScreen.h"
#include"global.h"

using namespace std;

int main()
{

	while(true){
		if (!clsLoginScreen::showLoginScreen()) {
			break;
		}
		
	}
	
	return 0;


}
