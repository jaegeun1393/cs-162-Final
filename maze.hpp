/*********************************************************************
** Program Filename: maze.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: set up the entire maze
** Input: -
** Output: maze object
*********************************************************************/

#ifndef _MAZE_
#define _MAZE_

#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

#include "mazelevel.hpp"
#include "intrepidstudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"
#include "mazeperson.hpp"

using namespace std;

class Maze {
	private:
		int num_levels;
		int level_height;
		int level_width;
		int current_level;
		int count_appease;

		Mazelevel** mazelevels;
		Mazeperson * student;
		Mazeperson * TA1;
		Mazeperson * TA2;
		Mazeperson * instructor;

		bool game_over; //true start
	public:
		Maze(ifstream& maze_file);
		void start_setting();
		void display_maze();
		
		void randomlocation_TA();
		void randomlocation_map_skill();

		void TA1_move();
		void TA2_move();
		void player_move();

		void touch_TA();
		void touch_instructor();
		void reset_map_skill();
		void reset_maze();
		
		void check_game_over();
		bool get_game_over();
};
#endif