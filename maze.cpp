/*********************************************************************
** Program Filename: maze.cpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: set up the basic rules of playing maze
** Input: -
** Output: maze
*********************************************************************/

#include<cstdlib>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 
 
#include "maze.hpp"
#include "mazelevel.hpp"
#include "mazeperson.hpp"
#include "intrepidstudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"

using namespace std;

/*********************************************************************
** Function: maze
** Description: get informations from the text file and creat objects to start the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
Maze::Maze(ifstream& maze_file) {
	srand(time(NULL));

	game_over = true; 
	current_level = 0;
	count_appease = 10;
	maze_file >> num_levels; 
	maze_file >> level_height;
	maze_file >> level_width;

	student = new Intrepidstudent;
	TA1 = new Ta;
	TA2 = new Ta;
	instructor = new Instructor;
	mazelevels = new Mazelevel * [num_levels]; 
	
	for(int i=0; i<num_levels; i++) {
		mazelevels[i] = new Mazelevel(maze_file, level_height, level_width);
	}
}

/*********************************************************************
** Function: start_setting
** Description:  set the location of ta and skill locations
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::start_setting() {
	randomlocation_TA();
	randomlocation_map_skill();
	randomlocation_map_skill();
}

/*********************************************************************
** Function: randomlocation_TA
** Description:  set the random location of ta1 and ta2
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::randomlocation_TA() {
	bool again = true;
	while (again) {
		TA1->set_location(rand()%17, rand()%17); //top - bot = 17
		TA2->set_location(rand()%17, rand()%17);
		if((mazelevels[current_level]->check_movement(TA1->get_row(), TA1->get_col()) ) && (mazelevels[current_level]->check_movement(TA2->get_row(), TA2->get_col()) ) ) {
			mazelevels[current_level]->set_ta(TA1->get_row(), TA1->get_col());
			mazelevels[current_level]->set_ta(TA2->get_row(), TA2->get_col());
			again = false;
		}
	}
}

/*********************************************************************
** Function: randomlocation_map_skill
** Description:  set up the programming skill at the openspace
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::randomlocation_map_skill() {
	bool again = true;
	while (again) {
		int skill_row = rand()%17;
		int skill_col = rand()%17;
		if((mazelevels[current_level]->check_movement(skill_row, skill_col) )) {
			mazelevels[current_level]->set_map_skill(skill_row, skill_col);
			again = false;
		}
	}
}

/*********************************************************************
** Function: display_maze
** Description:  display each object's logo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::display_maze() {
	mazelevels[current_level]->display_mazelevel();
}

/*********************************************************************
** Function: player_move
** Description:  get the movement information and move them when the location is open space
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::player_move() {
	int movement;
	movement = student->get_move();
	int student_row = student->get_row();
	int student_col = student->get_col();
	
	if (movement == 1 && mazelevels[current_level]->check_movement(student_row-1,student_col)) {  
		mazelevels[current_level]->delete_student(student_row,student_col);		
		student->set_location((student_row)-1, student_col);					
		mazelevels[current_level]->set_student(student->get_row(),student->get_col());
	}		
	else if (movement == 2 && mazelevels[current_level]->check_movement(student_row+1,student_col)) {
		mazelevels[current_level]->delete_student(student_row,student_col); 
		student->set_location((student_row)+1, student_col);
		mazelevels[current_level]->set_student(student->get_row(),student->get_col());
	}		
	else if (movement == 3 && mazelevels[current_level]->check_movement(student_row,student_col-1)) {
		mazelevels[current_level]->delete_student(student_row,student_col); 
		student->set_location((student_row), student_col-1);
		mazelevels[current_level]->set_student(student->get_row(),student->get_col());
	}
	else if (movement == 4 && mazelevels[current_level]->check_movement(student_row,student_col+1)) {
		mazelevels[current_level]->delete_student(student_row,student_col); 
		student->set_location((student_row), student_col+1);
		mazelevels[current_level]->set_student(student->get_row(),student->get_col()); 
	}
	else if(movement == 5) {							
		if(mazelevels[current_level]->get_ladder(student->get_row(),student->get_col())) {
		current_level++;
		student->set_location(1,1);
		randomlocation_TA();
		randomlocation_map_skill();
		randomlocation_map_skill();
		student->set_appease(false);	
		}
	}
	else if(movement == 6) {	
		if(student->get_map_skills()>0) {
			student->set_appease(true);		
			student->cal_map_skills(0); 
		}
	}
	if(mazelevels[current_level]->get_map_skill(student->get_row(), student->get_col())) {
		cout << " You picked up the programming skill" << endl;
		student->cal_map_skills(1);
		mazelevels[current_level]->delete_skill(student->get_row(), student->get_col());  
	}
	if(student->get_appease()) {
		cout << "Appease turns left " << count_appease << endl;
		count_appease--;
		if (count_appease == 0) {
			count_appease = 10;
			student->set_appease(false);
		}
	}
}

/*********************************************************************
** Function: TA1_move
** Description:  set the ta1's movement
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::TA1_move() { 				
	int row = TA1->get_row(), col = TA1->get_col();
	bool again = true;
	while(again) {
		int num = rand()%4;
	if( (num == 0) && (mazelevels[current_level]->check_movement(row-1,col)) ) { 
		mazelevels[current_level]->delete_ta(row, col);
		TA1->set_location(row-1,col);
		mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());
		again = false;
		}		
	else if( (num == 1) && (mazelevels[current_level]->check_movement(row+1,col)) ) {
		mazelevels[current_level]->delete_ta(row, col);
		TA1->set_location(row+1,col);
		mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());
		again = false;
		}		
	else if( (num == 2) && (mazelevels[current_level]->check_movement(row,col-1)) ) {
		mazelevels[current_level]->delete_ta(row, col);
		TA1->set_location(row,col-1);
		mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());
		again = false;
		}
	else if( (num == 3) && (mazelevels[current_level]->check_movement(row,col+1)) ) { 
		mazelevels[current_level]->delete_ta(row, col);
		TA1->set_location(row,col+1);
		mazelevels[current_level]->set_ta(TA1->get_row(),TA1->get_col());
		again = false;
		}
	}
}

/*********************************************************************
** Function: TA2_move
** Description: set the ta2 movement when the space is open
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::TA2_move() { 				
	int row = TA2->get_row(), col = TA2->get_col();
	bool again = true;
	while(again) {
		int num = rand()%4;
	if( (num == 0) && (mazelevels[current_level]->check_movement(row-1,col)) ) { 
		mazelevels[current_level]->delete_ta(row, col);
		TA2->set_location(row-1,col);
		mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
		again = false;
		}		
	else if( (num == 1) && (mazelevels[current_level]->check_movement(row+1,col)) ) {
		mazelevels[current_level]->delete_ta(row, col);
		TA2->set_location(row+1,col);
		mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
		again = false;
		}		
	else if( (num == 2) && (mazelevels[current_level]->check_movement(row,col-1)) ) {
		mazelevels[current_level]->delete_ta(row, col);
		TA2->set_location(row,col-1);
		mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
		again = false;
		}
	else if( (num == 3) && (mazelevels[current_level]->check_movement(row,col+1)) ) { 
		mazelevels[current_level]->delete_ta(row, col);
		TA2->set_location(row,col+1);
		mazelevels[current_level]->set_ta(TA2->get_row(),TA2->get_col());
		again = false;
		}
	}
}

/*********************************************************************
** Function: check_game_over
** Description: check the gameover is false or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::check_game_over() {
	touch_TA();
	touch_instructor();
}

/*********************************************************************
** Function: touch_TA
** Description:  check the player touch the ta
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::touch_TA() {
	int student_row = student->get_row(), student_col = student->get_col();
	int ta1_row = TA1->get_row(), ta1_col = TA1->get_col(), ta2_row = TA2->get_row(), ta2_col = TA2->get_col();
	mazelevels[current_level]->check_movement(student_row,student_col);
	if(!(student->get_appease()) ) {
		if(((student_row == ta1_row) && (student_col == ta1_col)) || ((student_row == ta2_row) && (student_col == ta2_col))) {
			cout << "|-TA catch you!\n|-You have to move back to the start point!" << endl;
			mazelevels[current_level]->delete_student(student_row,student_col); 
			student->set_location(1,1);
			student->set_map_skills(0);
			reset_map_skill();
		}
	}
}

/*********************************************************************
** Function: reset_map_skill
** Description: remove all skills and place 3 programming skills
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::reset_map_skill() {
	for(int r = 0; r < level_height; r++) {
		for(int c = 0; c < level_width; c++) {
		mazelevels[current_level]->delete_skill(r, c);
		mazelevels[current_level]->delete_ta(r, c);
		}
	}
	randomlocation_map_skill();
	randomlocation_map_skill();
	randomlocation_map_skill();
	cout << "|-Player go back to the start point and programming skills are set" << endl;
}

/*********************************************************************
** Function: reset_map_skill
** Description: remove all skills and place 3 programming skills
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::reset_maze() {
	for(int i = 0; i < 3; i++) {
		for(int r = 0; r < level_height; r++) {
			for(int c = 0; c < level_width; c++) {
				mazelevels[i]->delete_skill(r, c);
				mazelevels[i]->delete_ta(r, c);
				mazelevels[i]->delete_student(r, c);
			}
		}
	}
}

/*********************************************************************
** Function: touch_instructor
** Description: check the player touch the instructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/ 
void Maze::touch_instructor() {
	int student_row = student->get_row(), student_col = student->get_col();
	int instructor_row = instructor->get_row(), instructor_col = instructor->get_col();
	mazelevels[current_level]->check_movement(student_row,student_col);

	if(mazelevels[current_level]->get_instructor_row() >0 &&mazelevels[current_level]->get_instructor_col()>0) {
		instructor->set_location(mazelevels[current_level]->get_instructor_row(),mazelevels[current_level]->get_instructor_col());
	}
	if( (current_level == 2) && (student_row == instructor_row) && (student_col == instructor_col)) {
		if(student->get_map_skills() < 3) {
			cout << "|-Instructor find you!\n|-You also have less than 3 progamming skills!" << endl;
			cout << "|-Instructor bring you back to the first level!" << endl;
			mazelevels[current_level]->delete_student(student_row,student_col); 
			student->set_location(1,1);
			current_level = 0;
			student->set_map_skills(0);
			reset_maze();
			randomlocation_map_skill();
			randomlocation_map_skill();
		}
		else{
			cout << "|-Instructor find you!" << endl;
			cout << "|-You have enough skills to pass the maze!" << endl;
			cout << "|-Nice job Jaegeun!\n|-You pass the CS162 class" << endl;
			game_over = false;
		}
	}
}

/*********************************************************************
** Function: get_game_over
** Description: return game_over
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game_over
*********************************************************************/ 
bool Maze::get_game_over() {
	return game_over;
}