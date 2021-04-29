/*********************************************************************
** Program Filename: mazelevel.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: set up the maze each level
** Output: mazelevel
*********************************************************************/

#ifndef _MAZELEVEL_
#define _MAZELEVEL_

#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

#include "mazelocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"

using namespace std;

class Mazelevel {
	private:
		vector<vector<Mazelocation*> > locations;		
		int level_height;
		int level_width;
		int instructor_row;	
		int instructor_col;

	public:
		Mazelevel(ifstream& file,int input_height, int input_width);
		void display_mazelevel();
		void set_student(int row, int col);
		void delete_student(int row, int col);
		void set_ta(int row, int col);
		void delete_ta(int row, int col);
		void set_map_skill(int row, int col);
		void delete_skill(int row, int col);

		bool get_ta(int row, int col);
		bool get_instructor(int row, int col);
		bool get_map_skill(int row, int col);
		bool get_ladder(int row, int col);
		bool check_movement(int row, int col);

		int get_instructor_row();
		int get_instructor_col();
		~Mazelevel();
};
#endif