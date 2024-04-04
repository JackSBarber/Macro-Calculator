#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

double weight, lbsPerWeek, activityLevel, height, RMR;
int age, i, g, ui, a;

string Activity, UserInput, Gender;

int main(){

    cout << "Are you Male or Female? " << endl;
    cin >> Gender;
    for(char &c : Gender){
        c = tolower(c);
    }

    cout << "How tall are you in feet? (Example: 5.8 is 5 foot 8 inches) " << endl;
    cin >> height;
    height = height * 30.48;

	cout << "Input weight in lbs: " << endl;
	cin >> weight;
	weight = weight / 2.2;

    cout << "How old are you: " << endl;
    cin >> age;

	cout << "Would you like to maintain, cut, or bulk your weight?" << endl;
	cin >> UserInput;
    for(char &c : UserInput){
        c = tolower(c);
    }

	cout << "And how active would you say you are on a daily basis? Not Active, Slightly Active, Active, or Very Active?" << endl;
	cin.ignore();
    getline(cin, Activity);
    for(char &c : Activity){
        c = tolower(c);
    }
// Gender Statements
    if(Gender == "male") {
		g = 1;
    } else if(Gender == "female"){
		g = -1;
	} else {
            cout << "Whoops! It seems that you declared your gender status incorrectly. That's okay, please input whether you were genetically born 'Male' or 'Female'" << endl;
    }
// Weight Management Statements
    if(UserInput == "maintain") {
		ui = 1;
	} else if(UserInput == "cut"){
		ui = 2;
	} else if(UserInput == "bulk"){
		ui = 3;
	} else {
        cout << "Whoops! It seems that you did not say your weight goals. That's okay, please input 'Maintain', 'Cut', or 'Bulk' based on your daily routine!" << endl;
    } 
 // Activity Statements
    if(Activity == "not active"){
		a = 1;
	} else if(Activity == "slightly active"){ 
		a = 10;
	} else if(Activity == "active"){
		a = 100;
	} else if(Activity == "very active"){
		a = 1000;
	} else{
    	cout << "Whoops! It seems that you declared your activity status incorrectly. That's okay, please input 'Not Active', 'Slightly Active', 'Active', or 'Very Active' based on your daily routine!" << endl;
	}

    i = g * ui * a;

//Assigned Activity Levels Based on Gender and How Active They Are
	if(i >= -9 && i <= 9){
		activityLevel = 1.0;
	} else if(i >= 10 && i <= 99){
		activityLevel = 1.11;
	} else if (i >= -99 && i <= -10){
		activityLevel = 1.12;
	} else if(i >= 100 && i <= 999){
		activityLevel = 1.25;
	} else if (i >= -999 && i <= -100){
		activityLevel = 1.27;
	} else if (i >= 1000 && i<= 9999){
		activityLevel = 1.48;
	} else if (i >= -9999 && i<= -1000){
		activityLevel = 1.45;
	} else {
		cout << "-----Error Error | Does Not Compute Does Not Compute | Error Error-----" << endl;
	}
//Turning Values Into 1 Digit and Making Them Positive For The Next Switch Statement
	while(i >=10 || i <= -10){
		i /= 10;
		i = abs(i);
	}
//Defining The Resting Metabolic Rate
	cout << fixed << setprecision(2);
	RMR = (((9.99 * weight) + (6.25 * height) - (4.92 * age) + 5) * activityLevel);	
//Reaching Goals for Maintaining, Cutting, Or Bulking
	switch(i){
		case 1:
		if(i == 1)
			cout << "In order to maintain your weight, on a daily basis you must consume: " << endl << RMR << " Calories" << endl << (RMR * 0.25)/9 << " g of Fat" << endl << (RMR * 0.5)/4 << "g of Carbohydrates" << endl 
    		<< (RMR * 0.25)/4 << "g of Protein" << endl;
		break;
		case 2:
			cout << "How many pounds a week would you like to lose?" << endl;
			cin >> lbsPerWeek;
			cout << "In order to lose " << lbsPerWeek << " lbs a week, on a daily basis you must consume: " << endl << RMR - (500 * lbsPerWeek) << " Calories" << endl << ((RMR - (500 * lbsPerWeek)) * 0.25)/9 << " g of Fat" << endl << ((RMR - (500 * lbsPerWeek)) * 0.5)/4 << "g of Carbohydrates" << endl 
    		<< ((RMR - (500 * lbsPerWeek)) * 0.25)/4 << "g of Protein" << endl;
			cout << "It is also worth noting that consuming less than " << RMR - 1000 << " a day can become very unhealthy for you!" << endl;
		break;
		case 3:
			cout << "How many pounds a week would you like to gain?" << endl;
			cin >> lbsPerWeek;
			cout << "In order to gain " << lbsPerWeek << " lbs a week, on a daily basis you must consume: " << endl << RMR + (500 * lbsPerWeek) << " Calories" << endl << ((RMR + (500 * lbsPerWeek)) * 0.25)/9 << " g of Fat" << endl << ((RMR + (500 * lbsPerWeek)) * 0.5)/4 << "g of Carbohydrates" << endl 
    		<< ((RMR + (500 * lbsPerWeek)) * 0.25)/4 << "g of Protein" << endl;
    		cout << "It is also worth noting that consuming more than " << RMR + 1000 << " a day can become very unhealthy for you!" << endl;
		break;
		default:
			cout <<"Whoops! It Appears You Inputted Your Values Incorrectly" << endl;
	}
	cout << endl;
	cout << "These Numbers have been supplied by the United States Government National Library of Medicine, if you request additional information please visit https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4278349/" << endl;
	cout << "Thank You For Using This Calculator to Find The Macros Right For You!" << endl;

	return 0;
}
