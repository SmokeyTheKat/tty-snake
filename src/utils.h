#ifndef __snake_utils__
#define __snake_utils__

#include "../lib/ddcString/ddcString.h"
#include "../lib/ddcPrint/ddcPrint.h"
#include "../lib/ddcTime/ddcTime.h"
#include "../lib/ddcDef/ddcDef.h"
#include "../lib/ddcArguments/ddcArguments.h"
#include "../lib/ddcScreen/ddcApplication/ddcApplication.h"
#include "../lib/ddcScreen/ddcCursor/ddcCursor.h"
#include "letters.h"

void exit_game(int _c)
{
	cursor_clear();
	exit(0);
}

void draw_title(void)
{
	cursor_color_push();
	ddVec2 s = make_ddVec2(67,2);
	cursor_set_fg_color_rgb(255,0,0);
	draw_letter_s(s);
	s.x+=5;
	cursor_set_fg_color_rgb(255,255,0);
	draw_letter_n(s);
	s.x+=7;
	cursor_set_fg_color_rgb(0,255,0);
	draw_letter_a(s);
	s.x+=11;
	cursor_set_fg_color_rgb(0,255,255);
	draw_letter_k(s);
	s.x+=7;
	cursor_set_fg_color_rgb(0,0,255);
	draw_letter_e(s);
	cursor_color_pop();
}

void draw_borders(void)
{
	cursor_color_push();
	cursor_set_fg_color_rgb(255,0,0);
	ddVec2 p1 = make_ddVec2(23,9);
	ddVec2 p2 = make_ddVec2(170-24,47-3);

	draw_thick_line_points(make_ddVec2(p1.x,p1.y),
				make_ddVec2(p2.x,p1.y),
				cset_block);

	draw_thick_line_points(make_ddVec2(p1.x,p1.y),
				make_ddVec2(p1.x,p2.y),
				cset_block);
	draw_thick_line_points(make_ddVec2(p1.x-1,p1.y),
				make_ddVec2(p1.x-1,p2.y),
				cset_block);

	draw_thick_line_points(make_ddVec2(p2.x,p2.y),
				make_ddVec2(p1.x,p2.y),
				cset_block);

	draw_thick_line_points(make_ddVec2(p2.x,p2.y),
				make_ddVec2(p2.x,p1.y),
				cset_block);
	draw_thick_line_points(make_ddVec2(p2.x+1,p2.y),
				make_ddVec2(p2.x+1,p1.y),
				cset_block);


	cursor_color_pop();
}





#endif
