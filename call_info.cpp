
/********************************************************************************************************
Name: Caroline Navega Desouza      Z#: 23019431
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: January 24th,2016        Due Time: 11:59pm
Total Points: 100
Assignment 1: January 24, 2016 call_info.cpp

Description:
In this assignment a program call management system is implemented. The program uses three functions:
input, output, and process. The function Input gets input from the user, the function Process performs
the necessary calculations, and the function Output prints the results.
*********************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
void Input(string &cell_num, int &relays, int &call_length);
void Output(const string cell_num, const int relays, const int call_length, const double &net_cost, const double &call_tax, const double &total_cost_of_call);
void Process(const int relays, const int call_length, double &net_cost, double &call_tax, double &total_cost_of_call);

//Main Function
int main()
{
	//assigned variables to program
	string cell_num;
	int relays, call_length;
	double net_cost, call_tax, total_cost_of_call;
	char let = NULL;

	//loop to execute program once & continuously ask if they want to compute info for more employees until user says no
	do{
		Input(cell_num, relays, call_length);
		Process(relays, call_length, net_cost, call_tax, total_cost_of_call);
		Output(cell_num, relays, call_length, net_cost, call_tax, total_cost_of_call);

		cout << "\nWould you like to enter information for another employee? Y or N?" << endl;
		cin >> let;

	} while (let == 'y' || let == 'Y');

	//user entered no, program quits
	cout << "Goodbye!" << endl;

	return 0;
}
//Function Implementations

/****************************************************************************************************
//Name: Input
Precondition: Values not yet assigned to each variable
Postcondition: Values are given to each variable from the user
Description: Gets input from user: cell phone number, number of relay stations and the length of call
*****************************************************************************************************/
void Input(string &cell_num, int &relays, int &call_length)
{
	cout << "Enter your cell phone number: ";
	cin >> cell_num;
	cout << "Enter the number of relay stations: ";
	cin >> relays;
	cout << "Enter the length of the call in minutes: ";
	cin >> call_length;
}

/****************************************************************************************************
//Name: Process
Precondition: User input received, but calculations not yet performed
Postcondition: Calculations are performed 
Description: Based on user input, calculates the net cost, call tax and total cost of call
*****************************************************************************************************/
void Process(const int relays, const int call_length, double &net_cost, double &call_tax, double &total_cost_of_call)
{
	//assigned local variable to store the tax rate
	double tax_rate = 0;

	//calculate net cost
	net_cost = relays / 50.0 * .40 * call_length;

	//verifies which condition is true & applies tax calculations accordingly
	if ((relays >= 1) && (relays <= 5))
	{
		tax_rate = .01;
		call_tax = net_cost * tax_rate;
	}
	if ((relays >= 6) && (relays <= 11))
	{
		tax_rate = .03;
		call_tax = net_cost * tax_rate;
	}
	if ((relays >= 12) && (relays <= 20))
	{
		tax_rate = .05;
		call_tax = net_cost * tax_rate;
	}
	if ((relays >= 21) && (relays <= 50))
	{
		tax_rate = .08;
		call_tax = net_cost * tax_rate;
	}
	else if (relays > 50)
	{
		tax_rate = .12;
		call_tax = net_cost * tax_rate;
	}

	//calculates total cost of the call based on above calculations
	total_cost_of_call = net_cost + call_tax;
	
}

/****************************************************************************************************
//Name: Output
Precondition: User unaware of results until they are displayed onscreen
Postcondition: User is shown all the details of the call based on the info they gave the program
Description: Outputs the user's inputs and the program's calculations onscreen 
*****************************************************************************************************/
void Output(const string cell_num, const int relays, const int call_length, const double &net_cost, 
			const double &call_tax, const double &total_cost_of_call)
{
	//Formula to format output values
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//displays user inputs & program calculations onscreen
	cout << "\n***********************************************\n" 
		 << "Cell Phone Number: \t" << cell_num << endl
		 << "***********************************************\n\n" << endl;
	cout << "Number of relay stations:\t" << relays << endl;
	cout << "\nLength of Call in Minutes:\t" << call_length << endl;
	cout << "\nNet Cost of Call: \t\t$" << net_cost << endl;
	cout << "\nTax of Call: \t\t\t$" << call_tax << endl;
	cout << "\nTotal Cost of Call: \t\t$" << total_cost_of_call << endl;

}

