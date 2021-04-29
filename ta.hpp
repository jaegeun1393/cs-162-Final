/*********************************************************************
** Program Filename: ta.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for ta
** Input: -
** Output: TA object
*********************************************************************/

#ifndef _TA_
#define _TA_

#include<cstdlib>
#include<iostream>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h> 

#include "mazeperson.hpp"

using namespace std;

class Ta: public Mazeperson {
	private:
		int row;
		int col;
	public:
		Ta();
		int get_move();
		void set_location(int r, int c);
		int get_row();
		int get_col();
};
#endif