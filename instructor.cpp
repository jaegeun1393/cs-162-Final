/*********************************************************************
** Program Filename: instructor.cpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for instructor
** Input: -
** Output: instructor object
*********************************************************************/
#include"instructor.hpp"

#include<iostream>
#include<cstdlib>
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
Instructor::Instructor() {
	//nothing to set
}

/*********************************************************************
** Function: get_move
** Description: does not has to return because this object is not movement
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: 0
*********************************************************************/ 
int Instructor::get_move() {
	return 0;
}

/*********************************************************************
** Function: set_location
** Description: set the location of the instructor
** Parameters: int
** Pre-Conditions: r, c
** Post-Conditions: none
*********************************************************************/ 
void Instructor::set_location(int r, int c) {
	row = r;
	col = c;
}

/*********************************************************************
** Function: get_row
** Description: return the row of the object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: row
*********************************************************************/ 
int Instructor::get_row() {
	return row;
}

/*********************************************************************
** Function: get_col
** Description: return the col of the object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: col
*********************************************************************/ 
int Instructor::get_col() {
	return col;
}

