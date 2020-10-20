#include <ddcString.h>
#include <ddcPrint.h>
#include <ddcTime.h>
#include <ddcDef.h>
#include <ddcArguments.h>
#include <ddcApplication.h>
#include <ddcCursor.h>
#include <ddcKeyboard.h>
#include <ddcCharSets.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include "letters.h"
#include "utils.h"

ddApplication v_da;

typedef struct snake snake;

struct snake
{
	ddVec2 snakeVel;
	ddVec2* snakePoss;
	ddsize snakeLength;
	ddsize snakeCapacity;
	ddColor snakeColor;
};

snake make_snake(ddsize _sc, ddColor _sfg)
{
	snake _o;
	_o.snakeVel = make_ddVec2(1,0);
	_o.snakePoss = make(ddVec2, _sc);
	_o.snakePoss[0] = make_ddVec2(12,10);
	_o.snakeCapacity = _sc;
	_o.snakeLength = 1;
	_o.snakeColor = _sfg;

	return _o;
}
void draw_snake(snake s)
{
	cursor_colorPush();
	cursor_setFGColor(s.snakeColor);
	for (int i = 0; i < s.snakeLength; i++)
	{
		cursor_moveTo(s.snakePoss[i].x*2, s.snakePoss[i].y);
		cursor_chWrite(cset_block);
		cursor_chWrite(cset_block);
	}
	cursor_colorPop();
}
void clear_snake(snake s)
{
	cursor_colorPush();
	cursor_setFGColorRGB(0,0,0);
	for (int i = 0; i < s.snakeLength; i++)
	{
		cursor_moveTo(s.snakePoss[i].x*2, s.snakePoss[i].y);
		cursor_chWrite(cset_block);
		cursor_chWrite(cset_block);
	}
	cursor_colorPop();

}
void clear_snake_head(snake s)
{
	cursor_colorPush();
	cursor_setFGColorRGB(0,0,0);
	cursor_moveTo(s.snakePoss[0].x*2, s.snakePoss[0].y);
	cursor_chWrite(cset_block);
	cursor_chWrite(cset_block);
	cursor_moveTo(s.snakePoss[s.snakeLength-1].x*2, s.snakePoss[s.snakeLength-1].y);
	cursor_chWrite(cset_block);
	cursor_chWrite(cset_block);
	cursor_colorPop();

}
void shift_snake(snake* s)
{
	s->snakeLength++;
	for (int i = s->snakeLength-2; i >= 0; i--)
	{
		s->snakePoss[i+1] = s->snakePoss[i];
	}
	s->snakePoss[0] = make_ddVec2(-1,-1);
}
void pop_snake(snake* s)
{
	s->snakePoss[s->snakeLength-1] = make_ddVec2(-1,-1);
	s->snakeLength--;
}
void push_snake(snake* s, ddVec2 nv)
{
	shift_snake(s);
	s->snakePoss[0] = nv;
}
void move_snake(snake* s, bool* m)
{
	ddVec2 nv = make_ddVec2(s->snakePoss[0].x+s->snakeVel.x,
					s->snakePoss[0].y+s->snakeVel.y);
	if (!(*m))
	{
		pop_snake(s);
	}
	else
		(*m) = false;
	push_snake(s, nv);
}

ddKeyInfo c_input;
bool gameRun = true;

void* read_input(void* __vp)
{
	for(;;)
	{
		c_input = ddKey_getch();
		if (c_input == DDK_p) gameRun = !gameRun;
	}
}

ddVec2 random_food(void)
{
	return make_ddVec2(12+(int)(rand() % (62-12) + 1), 10+(int)(rand() % (35-10) + 1));
}

void draw_food(ddVec2 f)
{
	cursor_colorPush();
	cursor_setFGColorRGB(0,255,0);
	cursor_moveTo(f.x*2, f.y);
	cursor_chWrite(cset_block);
	cursor_chWrite(cset_block);
	cursor_colorPop();
}
void snake_eat_food(snake* s, ddVec2* f)
{
/*
	*f = random_food();
	draw_food(*f);
	if (s->snakeLength+1 > s->snakeCapacity) return;
	ddVec2 nv = make_ddVec2(s->snakePoss[0].x+s->snakeVel.x, s->snakePoss[0].y+s->snakeVel.y);
	shift_snake(s);
	s->snakePoss[0] = nv;
	s->snakeLength++;
*/
}
bool snake_bite_self(snake* s)
{
	for (int i = 0; i < s->snakeLength; i++)
		for (int j = 0; j < s->snakeLength; j++)
			if (ddVec2_compare(s->snakePoss[i], s->snakePoss[j]) && i != j) return true;
	return false;
}

void main_game(int _c)
{
	srand(time(null));
	pthread_t getkeys;
	pthread_create(&getkeys, null, read_input, null);

	ddsize dt = 100000;
	cursor_clear();
	draw_title();
	draw_borders();
	snake pl = make_snake(300, make_ddColor(255,255,0));
	pl.snakeLength=4;
	pl.snakePoss[0] = make_ddVec2(15,10);
	pl.snakePoss[1] = make_ddVec2(14,10);
	pl.snakePoss[2] = make_ddVec2(13,10);
	pl.snakePoss[3] = make_ddVec2(12,10);
	ddVec2 food = random_food();
	
	draw_snake(pl);
	draw_food(food);
	cursor_home();
	usleep(dt);
	clear_snake_head(pl);
	bool eatfood = false;
	for (;;)
	{
		if (c_input == DDK_UP && pl.snakeVel.y != 1)
		{
			pl.snakeVel = make_ddVec2(0,-1);
			c_input = null;
		}
		else if (c_input == DDK_DOWN && pl.snakeVel.y != -1)
		{
			pl.snakeVel = make_ddVec2(0,1);
			c_input = null;
		}
		else if (c_input == DDK_LEFT && pl.snakeVel.x != 1)
		{
			pl.snakeVel = make_ddVec2(-1,0);
			c_input = null;
		}
		else if (c_input == DDK_RIGHT && pl.snakeVel.x != -1)
		{
			pl.snakeVel = make_ddVec2(1,0);
			c_input = null;
		}
		else if (c_input == DDK_r)
		{
			c_input = null;
			main_game(_c);
			return;
		}
		move_snake(&pl, &eatfood);
		draw_snake(pl);
		if (!gameRun) {while(!gameRun);};
		if (pl.snakePoss[0].x < 12)
		{
			main_game(_c);
			return;
		}
		else if (pl.snakePoss[0].x > 72)
		{
			main_game(_c);
			return;
		}
		else if (pl.snakePoss[0].y < 10)
		{
			main_game(_c);
			return;
		}
		else if (pl.snakePoss[0].y > 43)
		{
			main_game(_c);
			return;
		}
		else if (snake_bite_self(&pl))
		{
			main_game(_c);
			return;
		}
		if (ddVec2_compare(pl.snakePoss[0], food))
		{
			//snake_eat_food(&pl, &food);
			eatfood = true;
			food = random_food();
			draw_food(food);
			
		}
		cursor_home();
		usleep(dt);
		clear_snake(pl);
	}
}

int main(ddsize agsc, char** ags)
{
	ddArgs dar = init_ddArgs(ags, agsc);
	if (ddArgs_has_cstring(dar, "yo"))
	{
		ddPrint_cstring_nl("yo yo yo");
	}

	init_cursor();
	cursor_clear();

	ddApplication v_da = init_ddApplication(make_constant_ddString("test"), make_ddColor(255,255,255), make_ddColor(0,0,0));

	ddSelect ds = make_ddSelect(make_ddVec2(70,12),
				      make_ddVec2(30,20),
				      make_dft_ddText(make_constant_ddString("SNAKE")),
				      make_ddColor(255,255,0), 5, make_ddColor(0,255,255));

	ddSelect_addOption(&ds, make_dft_ddText(make_ddString("Play")), main_game);
	ddSelect_addOption(&ds, make_dft_ddText(make_ddString("Exit")), exit_game);



	ddGArray_push(&(v_da.drawStack), ds);
	v_da.drawStackElems[0] = DDAE_DDSELECT;
	ddGArray_push(&(v_da.drawStack), draw_title);
	v_da.drawStackElems[1] = DDAE_GRAPHICSFUNCTION;

	run_ddApplication(&v_da);

	cursor_moveTo(0,40);

	exit_ddApplication(&v_da);

	return 0;
}
