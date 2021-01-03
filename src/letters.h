#ifndef __snake_letters__
#define __snake_letters__


#include "../lib/ddcString/ddcString.h"
#include "../lib/ddcPrint/ddcPrint.h"
#include "../lib/ddcTime/ddcTime.h"
#include "../lib/ddcDef/ddcDef.h"
#include "../lib/ddcArguments/ddcArguments.h"
#include "../lib/ddcScreen/ddcApplication/ddcApplication.h"
#include "../lib/ddcScreen/ddcCursor/ddcCursor.h"

void draw_letter_s(ddVec2 s)
{
	draw_thick_line_points(make_ddVec2(s.x,s.y),
				make_ddVec2(s.x+2,s.y),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y),
				make_ddVec2(s.x,s.y+2),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y+2),
				make_ddVec2(s.x+2,s.y+2),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x+2,s.y+2),
				make_ddVec2(s.x+2,s.y+4),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x+2,s.y+4),
				make_ddVec2(s.x,s.y+4),
				cset_block);
}
void draw_letter_n(ddVec2 s)
{
	draw_thick_line_points(make_ddVec2(s.x,s.y),
				make_ddVec2(s.x,s.y+4),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y),
				make_ddVec2(s.x+4,s.y+4),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x+4,s.y+4),
				make_ddVec2(s.x+4,s.y),
				cset_block);
}
void draw_letter_a(ddVec2 s)
{
	draw_thick_line_points(make_ddVec2(s.x,s.y+4),
				make_ddVec2(s.x+4,s.y),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x+2,s.y),
				make_ddVec2(s.x+8,s.y+4),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x+1,s.y+3),
				make_ddVec2(s.x+5,s.y+3),
				cset_block);
}
void draw_letter_k(ddVec2 s)
{
	draw_thick_line_points(make_ddVec2(s.x,s.y),
				make_ddVec2(s.x,s.y+4),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y+1),
				make_ddVec2(s.x+4,s.y),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y+2),
				make_ddVec2(s.x+4,s.y+4),
				cset_block);
}
void draw_letter_e(ddVec2 s)
{
	draw_thick_line_points(make_ddVec2(s.x,s.y),
				make_ddVec2(s.x,s.y+4),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y),
				make_ddVec2(s.x+4,s.y),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y+4),
				make_ddVec2(s.x+4,s.y+4),
				cset_block);
	draw_thick_line_points(make_ddVec2(s.x,s.y+2),
				make_ddVec2(s.x+4,s.y+2),
				cset_block);
}



#endif
