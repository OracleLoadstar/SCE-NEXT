#include "pch.h"

#include"UmaSCE_Main.h"
#include"SCE_Page.h"
#include"SCE_Setting.h"
#include"UmaSCE_UI.h"
#include <limits>
#include<iostream>
using namespace std;
#ifdef _WIN32
#include <io.h>
#include <direct.h>
#endif
#ifdef __unix__
#include "lio.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h> 
#endif

UmaSCE_Main uma1;
UmaSCE_Main uma2;
SCE_Setting_Struct set1;
//初始�?
void init() {
	//初始�?
	//初始化项目文�?
	#ifdef _WIN32
	if(_access("../Assets",0)==-1){
		_mkdir("../Assets");
	};
	if(_access("../Assets/Data",0)==-1){
		_mkdir("../Assets/Data");
	};
	if(_access("../Assets/Data/User",0)==-1){
		_mkdir("../Assets/Data/User");
	};
	if(_access("../Assets/Data/Save",0)==-1){
		_mkdir("../Assets/Data/Save");
	};
	#endif
	#ifdef __unix__
	if(access("../Assets",0)==-1){
		mkdir("../Assets",S_IRWXU);
	};
	if(access("../Assets/Data",0)==-1){
		mkdir("../Assets/Data",S_IRWXU);
	};
	if(access("../Assets/Data/User",0)==-1){
		mkdir("../Assets/Data/User",S_IRWXU);
	};
	if(access("../Assets/Data/Save",0)==-1){
		mkdir("../Assets/Data/Save",S_IRWXU);
	};
	#endif

}
//初始�?

int main()
{
	//仅针对CMD有效
	//system("mode con cols=50 lines=30");
	init();
	UmaSCE_UI ui1;
	uma1.Import(0, 10, 30, 0, 0, 0, 35, 1, 2, 1, 6, 1, 2);
	set1 = {1,1,1,1,1,1,1,1,1,1,1,0,4,1,0,0,1,1};
	Control_Main(0);
}


