
#include "IaGUI.h"
#include "Client2.h"
#include "MainMenu.h"
#include "Login.h"
#include <iostream>
#include <cstdlib>
#include "BD.h"


using namespace std;


void f1() {
	onlineGUI();
}
void f2() {
	Client2();
}
int main()
{
	
	/*thread th1(f1);

	thread th2(f2);

	th1.join();

	th2.join();*/

	
	Login();
	
	

	return 0;
}






//int main() {
//
//
//	//IaGUI(true); //true -> IA  |  false -> PvP
//	//MainMenu();
//	//Login();
//	//GUIonline();
//	onlineGUI();
//	//Client2();
//	
//	return 0;
//}
