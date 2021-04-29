/*********************************************************************
** Program Filename: intrepidstudent.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for player
** Input: -
** Output: player object
*********************************************************************/

#ifndef _INTREPIDSTUDENT_
#define _INTREPIDSTUDENT_

#include<cstdlib>
#include<iostream>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

#include "mazeperson.hpp"

using namespace std;


class Intrepidstudent: public Mazeperson {
	private:
		int row;
		int col;
		int map_skills;
		bool bol_appease;
	public:
		Intrepidstudent();
		int get_move();
		int get_row();
		int get_col();
		int get_map_skills();
		bool get_appease();

		void set_location(int r , int c);
		int set_map_skills(int val);
		void set_appease(bool val);

		void cal_map_skills(int val);
};
#endif