/*********************************************************************
** Program Filename: wall.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for wall
** Input: -
** Output: WALL object
*********************************************************************/

#ifndef _WALL_
#define _WALL_

#include"mazelocation.hpp"

using namespace std;

class Wall: public Mazelocation {
	private:
		bool movement;
		char logo;
	public:
		Wall();
		bool get_movement();
		char get_logo();
};
#endif