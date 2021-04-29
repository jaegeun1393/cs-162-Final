/*********************************************************************
** Program Filename: mazeperson.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: set the person(ch object)
** Input: -
** Output: player object
*********************************************************************/

#ifndef _MAZEPERSON_
#define _MAZEPERSON_

using namespace std;

class Mazeperson{
	public:
		virtual int get_move() = 0;
		virtual int get_row() = 0;
		virtual int get_col() = 0;
		virtual int get_map_skills() {}
		virtual bool get_appease() {}

		virtual void set_appease(bool val) {}
		virtual int set_map_skills(int val) {}
		virtual void set_location(int r, int c) = 0;

		virtual void cal_map_skills(int val) {}		
};
#endif