/*********************************************************************
** Program Filename: openspace.hpp
** Author: jaegeun oh
** Date: 3/19/2019
** Description: Object for openspace
** Input: -
** Output: open space object
*********************************************************************/

#ifndef _OPENSPACE_
#define _OPENSPACE_

#include"mazelocation.hpp"

using namespace std;

class Openspace: public Mazelocation {
	private:
		bool movement;
		char logo;

		bool has_student;
		bool has_ta;
		bool has_instructor;
		bool has_ladder;
		bool has_skill;
		bool has_start_point;
		bool has_map_skill;
	public:
		Openspace();
		bool get_movement();
		virtual char get_logo();

		void set_has_student(bool val);
		void set_has_ta(bool val);
		void set_has_instructor(bool val);
		void set_has_ladder(bool val);
		void set_has_skill(bool val);
		void set_has_start_point(bool val);
		void set_has_map_skill(bool val);

		bool get_has_student();
		bool get_has_ta();
		bool get_has_instructor();
		bool get_has_ladder();
		bool get_has_skill();
		bool get_has_start_point();
		bool get_has_map_skill();
};
#endif