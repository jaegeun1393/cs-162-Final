/*********************************************************************
** Program Filename: intrepidstudent.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for player
** Input: -
** Output: player object
*********************************************************************/

#include"intrepidstudent.hpp"

#include<iostream>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

using namespace std;

/*********************************************************************
** Function: instructor
** Description: basic setting
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Intrepidstudent::Intrepidstudent() {
	row = 1; 
	col = 1;
	map_skills = 0;
	bol_appease = false;
}

/*********************************************************************
** Function: get_move
** Description: get the movement from the input value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: movement
*********************************************************************/ 
int Intrepidstudent::get_move() {
	bool again = true;
	int num;
	char input;
	while(again) {
		cout << "Enter the direction you would like to move: " << endl;
		cout << "Skills: " << map_skills << endl;
		cout << "W for Up \nS for Down \nA for Right \nD for Left" << endl;
		cout << "U use the Ladder" << endl;
		cout << "P to demonstate a skill" << endl;
		cout << "ENTER: ";
		cin >> input;
		cout << endl;
		if(input == 'w') {
			num = 1;
			}
		else if( input == 's') {
			num = 2;
			}
		else if( input == 'a') {
			num = 3;
			}
		else if(input == 'd') {
			num = 4;
			}
		else if(input == 'u') {
			num = 5;
		}
		else if(input == 'p') {
			num = 6;
		}
		return num;
	}
}

/*********************************************************************
** Function: get_row
** Description: get the row
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: row
*********************************************************************/ 
int Intrepidstudent::get_row() {
	return row;
}

/*********************************************************************
** Function: get_col
** Description: get the col
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: col
*********************************************************************/ 
int Intrepidstudent::get_col() {
	return col;
}

/*********************************************************************
** Function: get_map_skills
** Description: get skills
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: map_skills
*********************************************************************/ 
int Intrepidstudent::get_map_skills() {
	return map_skills;
}

/*********************************************************************
** Function: get_appease
** Description: get the appease in bool type
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: bol_appease
*********************************************************************/ 
bool Intrepidstudent::get_appease() {
	return bol_appease;
}

/*********************************************************************
** Function: set_location
** Description: set the location of the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Intrepidstudent::set_location(int r, int c) {
	row = r;
	col = c;
}

/*********************************************************************
** Function: set_map_skills
** Description: set the map skill
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
int Intrepidstudent::set_map_skills(int val) {
	map_skills = val;
}

/*********************************************************************
** Function: set_appease
** Description: set the appease
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Intrepidstudent::set_appease(bool val) {
	bol_appease = val;
}

/*********************************************************************
** Function: cal_map_skills
** Description: calculating map skills
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Intrepidstudent::cal_map_skills(int val) {
	if(val == 0) {
		map_skills -= 1;
	} else {
		map_skills += 1;
	}
}
