/*********************************************************************
** Program Filename: mazelocation.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: set the objects are true or not
** Input: -
** Output: none
*********************************************************************/

#ifndef _MAZELOCATION_
#define _MAZELOCATION_

using namespace std;

class Mazelocation {
	public:
		virtual bool get_movement() = 0;
		virtual char get_logo() = 0;
		
		virtual void set_has_ladder(bool val) {}
		virtual void set_has_start_point(bool val) {}
		virtual void set_has_instructor(bool val) {}
		virtual void set_has_student(bool val) {}
		virtual void set_has_ta(bool val) {}
		virtual void set_has_map_skill(bool val) {}

		virtual bool get_has_ladder() {}		
		virtual bool get_has_start_point() {}
		virtual bool get_has_instructor() {}
		virtual bool get_has_student() {}
		virtual bool get_has_ta() {}
		virtual bool get_has_map_skill() {}
};
#endif