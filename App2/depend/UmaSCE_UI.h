#pragma once
#include "UmaSCE_Main.h"
class UmaSCE_UI :private UmaSCE_Main
{
public:
	//1:Red,2:Yellow,3:Green,4:White,5:×ÏÉ«,6:ÇàÉ«,Another:Default.
	void UIcolor(int color);

	void UIspecific(char spec);
	void UIreset();

	void print_title(string title, int color=0, bool enter=1, char spec=' ');

	void print_text(string text, int color=0, bool enter=1, char spec=' ');
	void print_text(char text, int color = 0, bool enter = 1, char spec = ' ');

	void print_status(int level = 0);

	void print_option(string option, string key, bool is_stuts = 0, int status_level = 3, int color = 4, bool enter = 1, char spec = ' ');

	void print_tip(string tip, int color=0, bool enter=1, char spec=' ');

	void print_retrack(int width_, int level=1);

	void print_compare(int bv,int cv,string txt);

	void print_emojicomp(int bv,int cv,int lv);

	void print_input(int level=2);

	void endl_();
	void cls();
};
