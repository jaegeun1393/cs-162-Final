/*********************************************************************
** Program Filename: ta.cpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for ta
** Input: -
** Output: TA object
*********************************************************************/

#include"ta.hpp"

#include<iostream>
#include<cstdlib>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

using namespace std;	

/*********************************************************************
** Function: Ta
** Description:  the basic ta
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Ta::Ta() {
	srand(time(NULL));
}

/*********************************************************************
** Function: get_move
** Description: just have it for player object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
int Ta::get_move() {
	return 0;
}

/*********************************************************************
** Function: set_location
** Description: get values to set up the location
** Parameters: int
** Pre-Conditions: r, c
** Post-Conditions: row and col
*********************************************************************/ 
void Ta::set_location(int r , int c) {
	this->row = r;
	this->col = c;
}

/*********************************************************************
** Function: get_row
** Description:  return the row value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: row
*********************************************************************/ 
int Ta::get_row() {
	return row;
}

/*********************************************************************
** Function: get_col
** Description:  return the col value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: col
*********************************************************************/ 
int Ta::get_col() {
	return col;
}
