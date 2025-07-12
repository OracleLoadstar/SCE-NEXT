#include "pch.h"
#include "UmaSCE_UI.h"
#include "SCE_Setting.h"
#include<iostream>
#include<string>
#include<iomanip>
#include <vector>

extern SCE_Setting_Struct set1;
using namespace std;
void UmaSCE_UI::UIcolor(int color)//1:Red,2:Yellow,3:Green,4:White,5:×ÏÉ«,6:ÇàÉ«,Another:Default.

{
	switch (color)
	{
	case 1:cout << "\033[1m\033[31m"; break;
	case 2:cout << "\033[1m\033[33m"; break;
	case 3:cout << "\033[1m\033[32m"; break;
	case 4:cout << "\033[1m\033[37m"; break;
	case 5:cout << "\033[1m\033[35m"; break;
	case 6:cout << "\033[1m\033[36m"; break;
	default:cout << "\033[39m"; break;
	}
}

void UmaSCE_UI::UIspecific(char spec)
{
	if (spec == '_')
		cout << "\033[1m\033[4m";
	else if (spec == '-')
		cout << "\033[1m\033[9m";
}

void UmaSCE_UI::UIreset()
{
	cout << "\033[0m";
}

void UmaSCE_UI::print_title(string title, int color, bool enter, char spec)
{
	UIcolor(color);
	UIspecific(spec);
	UIspecific('_');
	cout << setw(40) << setfill(' ');
	cout << "\b\b\b\b\b\b\b\b\b\b" << "\b\b\b\b\b\b\b\b\b\b" << "\b\b\b\b\b\b\b\b\b\b" << "\b\b\b\b\b\b\b\b\b\b";
	cout << "-> " << title ;
	UIreset();
	if (enter)
	{
		cout << endl;

	}
}


void UmaSCE_UI::print_text(string text, int color, bool enter, char spec)
{
	UIcolor(color);
	UIspecific(spec);
	cout << text;
	UIreset();
	if (enter)
	{
		cout << endl;
	}
}

void UmaSCE_UI::print_text(char text, int color, bool enter, char spec)
{
	UIcolor(color);
	UIspecific(spec);
	cout<<text;
	UIreset();
	if (enter)
	{
		cout << endl;
	}
}

void UmaSCE_UI::print_option(string option, string key, bool is_status, int status_level, int color, bool enter, char spec)
{
	UIcolor(color);
	UIspecific(spec);
	cout << "  [" << key << "] " << option;
	if (is_status)
	{
		print_status(status_level);
	}
	UIreset();
	if (enter)
	{
		cout << endl;
	}
}

void UmaSCE_UI::print_tip(string tip, int color, bool enter, char spec)
{
	UIcolor(color);
	UIspecific(spec);
	switch (color)
	{
	case 1:cout << "¡Á " << tip << " ¡Á"; break;
	case 2:cout << "! " << tip << " !"; break;
	default:cout << "- " << tip << " -"; break;
	}
	UIreset();
	if (enter)
	{
		cout << endl;
	}

}

void UmaSCE_UI::print_retrack(int width_, int level)
{
	string blank;
	for (int i = 0; i < width_; i++)
	{
		blank[i] = ' ';
	}
	for (int i = 1; i <= level; i++)
	{
		cout << blank;
	}
	UIreset();
}

void UmaSCE_UI::print_input(int level)
{
	UIcolor(level);
	cout << "# ";
	UIreset();
}

void UmaSCE_UI::print_status(int level)
{
	UIcolor(level);
	cout << " ¡¤";
}

void UmaSCE_UI::endl_()
{
	cout << endl;
}

void UmaSCE_UI::cls()
{
    #ifdef _WIN32
	system("cls");
	#endif
	#ifdef __unix__
	system("clear");
	#endif
}

void UmaSCE_UI::print_compare(int bv, int cv, string txt)
{
	if(bv==0)
	{
		for(int i=0;i<10;i++)
		{
			cout<<"\033[2m\033[46m ";
			return;
		}
	}
	else if(cv==0)
	{
		for(int i=0;i<10;i++)
		{
			cout<<"\033[2m\033[41m ";
			return;
		}
	}
	int sum=cv+bv;
	double bvr=bv/static_cast<double>(sum);
	double cvr=1-bvr;

	int bvi=bvr*10;
	int cvi=cvr*10;
	if(10 != bvi+cvi)
	{
		if(bvi>cvi)
		{
			++bvi;
		}
		else
		{
			++cvi;
		}
	}
	cout<<"sum:"<<bvi+cvi;
	cout<<" "<<txt<<" ";
	cout<<"\033[2m\033[46m";
	for(int i=0;i<bvi;i++)
	{
		cout<<"  ";
	}
	cout<<"\033[2m\033[41m";
	for(int i=0;i<cvi;i++)
	{
		cout<<"  ";
	}
	cout<<"\033[0m";
	cout<<" "<<txt<<" ";
}

void UmaSCE_UI::print_emojicomp(int bv, int cv, int lv)
{
	if(set1.USE_EMOJI)
	{
		vector<string>bad{};
	}
}
