/*********************************************************************
** Program Filename: application.cpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Start the game 
** Input: User input
** Output: result from the user input
*********************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

#include "maze.hpp"
#include "mazelevel.hpp"
#include "wall.hpp"
#include "openspace.hpp"
#include "mazelocation.hpp"
#include "mazeperson.hpp"

using namespace std;

int main(int argc, char** argv) {
	bool game = true;

	ifstream maze_file;
	maze_file.open(argv[1]);

	if(maze_file.fail()) {
		cout << "Please run the program with the data file" << endl;
		return 0;
	}

	Maze maze1(maze_file);
	maze1.start_setting();

	while(game) {
		maze1.display_maze();
		maze1.player_move();
		maze1.TA1_move();
		maze1.TA2_move();
		maze1.check_game_over();
		game = maze1.get_game_over();
	}
	cout << "Thanks for play!" << endl;
}