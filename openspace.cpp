/*********************************************************************
** Program Filename: openspace.cpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for openspace
** Input: -
** Output: open space object
*********************************************************************/

#include"openspace.hpp"

using namespace std;


/*********************************************************************
** Function: openspace
** Description: setting up the basic open space
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Openspace::Openspace() {
	movement = true;
	logo = ' ';
	has_student=false;
	has_ta=false;
	has_instructor=false;
	has_ladder=false;
	has_skill=false;
	has_start_point=false;
	has_map_skill= false;
}

/*********************************************************************
** Function: get_movement
** Description:  return the object is moveable
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: movement
*********************************************************************/ 
bool Openspace::get_movement() { 
	return movement;
}

/*********************************************************************
** Function: get_logo
** Description:  return the logo of the object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: logo
*********************************************************************/ 
char Openspace::get_logo() {
	return logo;
}

/*********************************************************************
** Function: set_has_student
** Description:  set the 'set_has_student' in bool type
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Openspace::set_has_student(bool val) {
	has_student = val;	
}

/*********************************************************************
** Function: set_has_ta
** Description: set the 'has_ta' function equal to the val
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Openspace::set_has_ta(bool val) {
	has_ta = val;
}

/*********************************************************************
** Function: set_has_instructor
** Description:  set the instructor in bool type
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Openspace::set_has_instructor(bool val) {
	has_instructor = val;
}

/*********************************************************************
** Function: set_has_ladder
** Description: set the 'has_ladder' in bool type
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Openspace::set_has_ladder(bool val) {
	has_ladder = val;
}

/*********************************************************************
** Function: set_has_skill
** Description: check has_skill in bool type
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: row
*********************************************************************/ 
void Openspace::set_has_skill(bool val) {
	has_skill = val;
}

/*********************************************************************
** Function: set_has_start_point
** Description:  set up the start point is true
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Openspace::set_has_start_point(bool val) {
	has_start_point = val;
}

/*********************************************************************
** Function: set_has_map_skill
** Description:  set up skill is present on the maze
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Openspace::set_has_map_skill(bool val) {
	has_map_skill = val;
}

/*********************************************************************
** Function: get_has_student
** Description:  return has_student
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_student
*********************************************************************/ 
bool Openspace::get_has_student() {
	return has_student;
}

/*********************************************************************
** Function: get_has_ta
** Description:  return has_ta
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_ta
*********************************************************************/ 
bool Openspace::get_has_ta() {
	return has_ta;
}

/*********************************************************************
** Function: get_has_instructor
** Description:  return has_instructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_instructor
*********************************************************************/ 
bool Openspace::get_has_instructor() {
	return has_instructor;
}

/*********************************************************************
** Function: get_has_ladder
** Description:  return has_ladder
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_ladder
*********************************************************************/ 
bool Openspace::get_has_ladder() {
	return has_ladder;
}

/*********************************************************************
** Function: get_has_skill
** Description:  return has_skill
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_skill
*********************************************************************/ 
bool Openspace::get_has_skill() {
	return has_skill;
}

/*********************************************************************
** Function: get_has_start_point
** Description:  return has_start_point
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_start_point
*********************************************************************/ 
bool Openspace::get_has_start_point() {
	return has_start_point;
}

/*********************************************************************
** Function: get_has_map_skill
** Description:  return has_map_skill
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: has_map_skill
*********************************************************************/ 
bool Openspace::get_has_map_skill() {
	return has_map_skill;
}
