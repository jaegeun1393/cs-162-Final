/*********************************************************************
** Program Filename: mazelevel.cpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: set up the maze each level
** Output: mazelevel
*********************************************************************/

#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

#include"mazelevel.hpp"
#include "wall.hpp"
#include "openspace.hpp"

using namespace std;

/*********************************************************************
** Function: mazelevel
** Description: set up the objects on each slot
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Mazelevel::Mazelevel(ifstream& file,int input_height, int input_width) {
	srand(time(NULL));	
	level_height = input_height;
	level_width = input_width;
	for(int	r =0; r<input_height; r++) {
		vector<Mazelocation*> rV;
		for(int	c =0; c<input_width; c++) {
			char temp;
			file.get(temp);
			if (temp == '#' ) {
				rV.push_back(new Wall);
			}
			else if (temp == ' ' ) {
				rV.push_back(new Openspace);
			}
			else if(temp == '@'  ) {
				rV.push_back(new Openspace);
				rV[c]->set_has_start_point(true);
				rV[c]->set_has_student(true);
			}
			else if (temp == '^' ) {
				rV.push_back(new Openspace);
				rV[c]->set_has_ladder(true);
			}	
			else if (temp == '%' ) {
				rV.push_back(new Openspace);
				instructor_row =  r;
				instructor_col =  c;
				rV[c]->set_has_instructor(true);	
			}	
			else{
				c=c-1;

			}

			if(file.eof()) {
				return;
			}
		}
		cout<<endl;
		locations.push_back(rV);
	}

	locations[1][1]->set_has_student(true);


}

/*********************************************************************
** Function: display_mazelevel
** Description: print out the maze
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Mazelevel::display_mazelevel() {
	for(int	r =0; r<level_height; r++) {
		for(int	c =0; c<level_width; c++) {
			if( (locations[r][c]->get_movement()) && (locations[r][c]->get_has_student()) )  {
				cout<<'*';
			}
			else if( (locations[r][c]->get_movement()) && (locations[r][c]->get_has_ta()) ) {  //These if statements check the method is true and if it is an empty space
				cout<<'T';
			}
			else if( (locations[r][c]->get_movement()) && (locations[r][c]->get_has_map_skill()) ) {  
				cout<<'$';
			}
			else if( (locations[r][c]->get_movement()) && (locations[r][c]->get_has_ladder()) ) {  //These if statements check the method is true and if it is an empty space
				cout<<'^';
			}
			else if( (locations[r][c]->get_movement()) && (locations[r][c]->get_has_start_point()) ) {
				cout<<'@';
			}
			else if( (locations[r][c]->get_movement()) && (locations[r][c]->get_has_instructor()) ) {
				cout<<'%';
			}
			else {
				cout<<locations[r][c]->get_logo();
			}
		}
		cout << endl;
	}	
}

/*********************************************************************
** Function: set_student
** Description: set up the student survive or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Mazelevel::set_student(int row, int col) {
	locations[row][col]->set_has_student(true);
}

/*********************************************************************
** Function: delete_student
** Description: set the student suriviving to false
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Mazelevel::delete_student(int row, int col) {
	locations[row][col]->set_has_student(false);
}

/*********************************************************************
** Function: set_ta
** Description: set the ta true
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Mazelevel::set_ta(int row, int col) {
	locations[row][col]->set_has_ta(true);
}

/*********************************************************************
** Function: delete_ta
** Description: set ta aliving to false
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Mazelevel::delete_ta(int row, int col) {
	locations[row][col]->set_has_ta(false);
}

/*********************************************************************
** Function: set_map_skill
** Description: set the map skill is true
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Mazelevel::set_map_skill(int row, int col) {
	locations[row][col]->set_has_map_skill(true);
}

/*********************************************************************
** Function: delete_skill
** Description: it happen when the player touch the skill object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Mazelevel::delete_skill(int row, int col) {
	locations[row][col]->set_has_map_skill(false);
}

/*********************************************************************
** Function: get_ta
** Description: return ta object at the row and col
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool Mazelevel::get_ta(int row, int col) {
	return locations[row][col]->get_has_ta();
}

/*********************************************************************
** Function: get_instructor
** Description: get the instructor at the row and col it set
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool Mazelevel::get_instructor(int row, int col) {
	return locations[row][col]->get_has_instructor();
}

/*********************************************************************
** Function: get_map_skill
** Description: get the map skill location
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool Mazelevel::get_map_skill(int row, int col) {
	return locations[row][col]->get_has_map_skill();
}

/*********************************************************************
** Function: get_ladder
** Description: set up the ladder at the row and col
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool Mazelevel::get_ladder(int row, int col) {
	return locations[row][col]->get_has_ladder();
}

/*********************************************************************
** Function: check_movement
** Description: check up the pre movement before the object move
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
bool Mazelevel::check_movement(int row, int col) {
	return locations[row][col]->get_movement();

}

/*********************************************************************
** Function: get_instructor_row
** Description: get the information of instructor's row
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: instructor_row
*********************************************************************/ 
int Mazelevel::get_instructor_row() {
	return instructor_row;
}	

/*********************************************************************
** Function: get_instructor_col
** Description: get the insturctor col
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: instructor_col
*********************************************************************/ 
int Mazelevel::get_instructor_col() {
	return instructor_col;
}	




Mazelevel::~Mazelevel() {
	for(int r = 0; r < 19; r++) {
		for(int c = 0; c < 19; c++) {
			delete locations[r][c];
		}
		locations[r].clear();
	}
	locations.clear();
}
