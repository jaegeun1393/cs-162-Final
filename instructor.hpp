/*********************************************************************
** Program Filename: instructor.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for instructor
** Input: -
** Output: instructor object
*********************************************************************/

#ifndef _INSTRUCTOR_
#define _INSTRUCTOR_

#include<cstdlib>
#include<iostream>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

#include "mazeperson.hpp"

using namespace std;


class Instructor: public Mazeperson {
	private:
		int row;
		int col;
	public:
		Instructor();
		int get_move();
		void set_location(int r, int c);
		int get_row();
		int get_col();
};



#endif