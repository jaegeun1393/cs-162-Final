/*********************************************************************
** Program Filename: wall.cpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for wall
** Input: -
** Output: WALL object
*********************************************************************/

#include"wall.hpp"
using namespace std;


/*********************************************************************
** Function: wall
** Description:  set up the basic logo and moveable status
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Wall::Wall(){
	movement = false;
	logo = '#';
}

/*********************************************************************
** Function: get_movement
** Description: check the object is moveable
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: movement
*********************************************************************/ 
bool Wall::get_movement() { 
	return movement;
}

/*********************************************************************
** Function: get_logo
** Description:  return the logo of the wall
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: logo
*********************************************************************/ 
char Wall::get_logo() {
	return logo;
}