#include "pch.h"
#include "SCE_Page.h"
#include"UmaSCE_UI.h"
#include"SCE_Setting.h"
#include<iostream>
#include<vector>
#include <cstring>
#include <string>
#include <string.h>

#include "UmaSCE_tools.h"

#ifdef _WIN32
#define strcpy strcpy_s
#endif
using namespace std;

string ch;
UmaSCE_UI ui;
extern UmaSCE_Main uma1;
extern UmaSCE_Main uma2;
extern SCE_Setting_Struct set1;
setting_rw setrw;
res_rw resrw;
inline static void eatline() { cin.clear(); while (cin.get() != '\n' || cin.get() != '\0')continue; cin.clear(); }

//#ifdef _WIN32

inline static void _pause() 
{
	#ifdef _WIN32
	system("pause > nul"); 
	#endif
	#ifdef __unix__
	system("read -n 1"); 
	#endif
}

//#endif // _WIN32



void Print_Main(int ID)
{
	//欢迎界面
	if (ID == 0)
	{
		//test
		// _pause();
		// model mo;
		// mo.check_model("../test.model");
		// _pause();
		// test
		ui.cls();
		ui.print_title("你好，训练员！");
		ui.print_text("欢迎使用SupportCard Evalator");
		//以下描述更新内容及版本号
		ui.print_text("Version:5.0B8", 5);

		ui.print_text("更新内容：", 4);
		ui.print_tip("a.修复了一些bug");
		//...
		ui.print_text("按下任意键继续...");
		ui.print_input();
	}
	//主界面
	if (ID == 1)
	{
		ui.cls();
		ui.print_title("SCE_CH3CH2CH3", 2);
		ui.print_option("开始", "001",1);
		ui.print_option("设置", "002",1);
		ui.print_option("关于", "003",1,1);
		ui.print_option("退出", "999",1);
		ui.print_input();
	}
	//开始界面
	if (ID == 11)
	{
		ui.cls();
		ui.print_title("开始", 2);
		ui.print_option("创建新的支援卡", "001",1);
		ui.print_option("打开保存的支援卡", "002",1,1);
		ui.print_option("支援卡对比", "003",1);
		ui.print_option("返回主界面", "999",1);
		ui.print_input();
	}
	//支援卡对比界面
	if(ID==113)
	{
		
		ui.cls();
		ui.print_title("支援卡对比", 2);
		ui.print_option("打开标准卡", "001", 1);
		ui.print_option("开始对比", "002",1);
		ui.print_option("返回开始界面", "999", 1);
		ui.print_input();
	}
	//开始对比支援卡界面
	if(ID==1132)
	{
		ui.cls();
		ui.print_title("支援卡对比",2);
		ui.print_text(uma1.cardname_static,6,0);
		//...
		//...
		ui.print_text(uma2.cardname_static,1);
	}
	//设置界面
	if (ID == 12)
	{
		ui.cls();
		ui.print_title("设置", 2);
		ui.print_option("显示", "001",1);
		ui.print_option("计算", "002",1);
		ui.print_option("文件", "003",1,1);
		ui.print_option("控制", "004",1);
		ui.print_option("开发者", "010",1,1);
		ui.print_option("返回主页", "999",1);
		ui.print_input();
	}


	//设置下 显示设置界面
	if (ID == 121)
	{
		ui.cls();
		ui.print_title("设置 -> 显示", 2);
		ui.print_option("评分展示{}", "001",1);
		ui.print_option("辅助面板{}", "002",1);
		if(set1.IS_RESERVE0_BONUSARR)
		{
			ui.print_option("属性加成数组显示0 -> 是", "003",1);
		}
		else
		{
			ui.print_option("属性加成数组显示0 -> 否", "003",1);
		}
		if (set1.IS_SHOW_WELCOME)
		{
			ui.print_option("欢迎界面 -> 是", "004",1);
		}
		else
		{
			ui.print_option("欢迎界面 -> 否", "004",1);
		}
		ui.print_option("数字精度 -> ", "005",0,0,4,0);
		ui.print_text(to_string(set1.FLOAT_PRECISION), 4);
		ui.print_option("返回设置", "999",1);
		ui.print_input();
	}
	//设置下 计算设置界面
	if (ID == 122)
	{
		ui.cls();
		ui.print_title("设置 -> 计算", 2);
		if (set1.IS_CALCULATE_EVALV1)
		{
			ui.print_option("计算EvalV1 -> 是", "001",1);
		}
		else
		{
			ui.print_option("计算EvalV1 -> 否", "001",1);
		}
		if (set1.IS_CALCULATE_EVALV2)
		{
			ui.print_option("计算EvalV2 -> 是", "002",1);
		}
		else
		{
			ui.print_option("计算EvalV2 -> 否", "002",1);
		}
		if (set1.IS_CALCULATE_EVALV3)
		{
			ui.print_option("计算EvalV3 -> 是", "003",1);
		}
		else
		{
			ui.print_option("计算EvalV3 -> 否", "003",1);
		}
		if (set1.IS_CALCULATE_EVALV4)
		{
			ui.print_option("计算EvalV4 -> 是", "004",1);
		}
		else
		{
			ui.print_option("计算EvalV4 -> 否", "004",1);
		}
		if (set1.IS_CALCULATE_EVALV5)
		{
			ui.print_option("计算EvalV5 -> 是", "005",1);
		}
		else
		{
			ui.print_option("计算EvalV5 -> 否", "005",1);
		}
		ui.print_option("返回设置", "999",1);
		ui.print_input();
	}
	//设置下 文件界面
	if (ID == 123)
	{
		ui.cls();
		ui.print_title("设置 -> 文件", 2);
		if (set1.IS_AUTO_SAVE)
		{
			ui.print_option("自动保存 -> 开", "001",1,2);
		}
		else
		{
			ui.print_option("自动保存 -> 关", "001",1,2);
		}
		ui.print_option("返回设置", "999",1);
		ui.print_input();
	}
	//设置下 控制界面
	if (ID == 124)
	{
		ui.cls();
		ui.print_title("设置 -> 控制", 2);
		if (set1.IS_GLOABL_CONTROL)
		{
			ui.print_option("全局控制 -> 开","001",1);
		}
		else
		{
			ui.print_option("全局控制 -> 关", "001",1);
		}
		ui.print_option("返回设置", "999",1);
		ui.print_input();
	}
	//设置下 显示设置下 评分展示界面
	if (ID == 1211)
	{
		ui.cls();
		ui.print_title("设置 -> 显示 -> 评分展示", 2);
		if(set1.IS_SHOW_EVALV3)
		{
			ui.print_option("展示EvalV3评分 -> 是", "001",1);
		}
		else
		{
			ui.print_option("展示EvalV3评分 -> 否", "001",1);
		}
		if (set1.IS_SHOW_EVALV4)
		{
			ui.print_option("展示EvalV4评分 -> 是", "002",1);
		}
		else
		{
			ui.print_option("展示EvalV4评分 -> 否", "002",1);
		}
		if (set1.IS_SHOW_EVALV5)
		{
			ui.print_option("展示EvalV5评分 -> 是", "003",1);
		}
		else
		{
			ui.print_option("展示EvalV5评分 -> 否", "003",1);
		}
		ui.print_option("返回显示", "999",1);
		ui.print_input();
	}
	//设置下 显示设置下 辅助面板界面
	if (ID == 1212)
	{
		ui.cls();
		ui.print_title("设置 -> 显示 -> 辅助面板", 2);
		if (set1.IS_SHOW_EVALV1)
		{
			ui.print_option("展示EvalV1评分 -> 是", "001",1);
		}
		else
		{
			ui.print_option("展示EvalV1评分 -> 否", "001",1);
		}
		if (set1.IS_SHOW_EVALV2)
		{
			ui.print_option("展示EvalV2评分 -> 是", "002",1);
		}
		else
		{
			ui.print_option("展示EvalV2评分 -> 否", "002",1);
		}
		if (set1.IS_SHOW_STRIKE)
		{
			ui.print_option("展示得意率 -> 是", "003",1);
		}
		else
		{
			ui.print_option("展示得意率 -> 否", "003",1);
		}
		ui.print_option("返回显示", "999",1);
		ui.print_input();
	}


	//开始下 新建支援卡界面
	if (ID == 111)
	{
		ui.cls();
		ui.print_title("开始 -> ",2,0);
		ui.print_text(uma1.cardname_static, 2, 0,'_');
		ui.print_text("预设", 2,1,'_');
		ui.print_option("支援卡类型：", "100", 0, 0, 4, 0);
		int temp_type = 0;
		try
		{
			uma1.Output<int>("type_static", temp_type);
			switch (temp_type)
			{
			case 0:ui.print_text("速度", 6); break;
			case 1:ui.print_text("耐力", 1); break;
			case 2:ui.print_text("力量", 2); break;
			case 3:ui.print_text("根性", 5); break;
			case 4:ui.print_text("智力", 3); break;
			default:ui.print_text("未知");
			}
		}
		catch (const char* err)
		{
			cerr << err << endl;
		}
		try
		{
			ui.print_option("友情加成：", "101", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_award")), 4);
			ui.endl_();
			ui.print_option("固有友情：", "102", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_static")), 4);
			ui.endl_();
			ui.endl_();
			ui.print_option("干劲加成：", "103", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("enthusiasm_award")), 4);
			ui.endl_();
			ui.print_option("训练加成：", "104", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 4);
			ui.endl_();
			ui.endl_();
			ui.print_option("得 意 率：", "105", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("strike_point")), 4);
			ui.endl_();
			ui.print_option("初期羁绊：", "106", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_point")), 4);
			ui.endl_();
			ui.endl_();

			ui.print_option("Bonus数组：{ ", "107", 0, 0, 4, 0);
			int temp;
			uma1.Output<int>("speed_bonus", temp);
			if (temp > 0)
			{
				ui.print_text(to_string(temp), 6, 0);
				ui.print_text(" ", 0, 0);
			}
			uma1.Output<int>("stamina_bonus", temp);
			if (temp > 0)
			{
				ui.print_text(to_string(temp), 1, 0);
				ui.print_text(" ", 0, 0);
			}
			uma1.Output<int>("power_bonus", temp);
			if (temp > 0)
			{
				ui.print_text(to_string(temp), 2, 0);
				ui.print_text(" ", 0, 0);
			}
			uma1.Output<int>("willpower_bonus", temp);
			if (temp > 0)
			{
				ui.print_text(to_string(temp), 5, 0);
				ui.print_text(" ", 0, 0);
			}
			uma1.Output<int>("wit_bonus", temp);
			if (temp > 0)
			{
				ui.print_text(to_string(temp), 3, 0);
				ui.print_text(" ", 0, 0);
			}
			uma1.Output<int>("sp_bonus", temp);
			if (temp > 0)
			{
				ui.print_text(to_string(temp), 4, 0);
				ui.print_text(" ", 0, 0);
			}
			ui.print_text("}", 4, 0);
			ui.endl_();
		}
		catch (const char* err)
		{
			cerr << err << endl;
		}
		ui.endl_();
		ui.print_option("开始计算", "200", 1);
		ui.print_option("清空预设", "201", 1);
		ui.print_option("修改支援卡标识名", "202", 1);
		ui.print_option("返回开始界面", "999", 1);
		ui.print_input();
	}
	//开始下 支援卡计算结果展示界面
	if (ID == 1112)
	{
		ui.cls();
		ui.print_title("开始 -> 结果展示", 2);
		ui.print_tip("支援卡信息一览", 6);
		try
		{
			ui.print_text("友情|固有：", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_award")), 0, 0);
			ui.print_text("|", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_static")), 0, 0);
			ui.endl_();
			ui.print_text("干劲|训练：", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("enthusiasm_award")), 0, 0);
			ui.print_text("|", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 0, 0);
			ui.endl_();
			ui.print_text("初羁|得意率：", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_point")), 0, 0);
			ui.print_text("|", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("strike_point")), 0, 0);
			ui.endl_();
			ui.print_text("Bonus数组：{ ", 0,0);
			{
				int temp;
				uma1.Output<int>("speed_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 6, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("stamina_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 1, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("power_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 2, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("willpower_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 5, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("wit_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 3, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("sp_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 4, 0);
					ui.print_text(" ", 0, 0);
				}
				ui.print_text("}", 0, 0);
				ui.endl_();
			}
			ui.endl_();
			ui.print_text("EvalV3 得分->", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("v3_ept")), 4, 0);
			ui.endl_();
			ui.endl_();
			ui.print_text("EvalV4 主要训练得分->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v4main_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV4 逛街训练得分->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v4fold_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV4 S P 训练得分->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v4sp_ept")), 2, 0);
			ui.endl_();

			ui.endl_();
			ui.print_text("EvalV5 主要训练得分->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v5main_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV5 逛街训练得分->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v5fold_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV5 S P 训练得分->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v5sp_ept")), 2, 0);
			ui.endl_();
		}
		catch (const char& err)
		{
			cerr << err << endl;
		}
		ui.print_option("返回编辑", "001", 1);
		ui.print_option("修改支援卡标识名", "002", 1);
		ui.print_option("保存支援卡信息", "003", 1, 1);
		ui.print_option("回到开始", "999", 1);
		ui.print_input();
	}


	//开始下 打开保存的支援卡界面
	if (ID == 112)
	{
		ui.cls();
		ui.print_title("开始 -> 打开保存的支援卡", 2);
		ui.print_tip("请输入保存的支援卡文件名", 6);
		ui.print_input(2);
	}


	//开始下 支援卡对比界面
	if (ID == 113)
	{
		;
	}


	//正在计算界面（独立的）
	if (ID == -10)
	{
		ui.cls();
		ui.print_title("正在计算评分", 4);
	}


	//不存在的界面
	if (ID == -1)
	{
		ui.cls();
		ui.print_tip("不存在的界面", 1);
		ui.print_tip("按下任意键回到主页...");
		ui.print_input();
	}
}

void Control_Main(int ID)
{
	//欢迎界面
	//加载设置
	setrw.read_setting(set1);
	if (ID == 0)
	{
		if(set1.IS_SHOW_WELCOME)
		{
			Print_Main(0);
			_pause();
		}
		Control_Main(1);
	}
	//主界面
	if (ID == 1)
	{
		Print_Main(1);
		cin >> ch;
		if (ch == "001")
		{
			Control_Main(11);
		}
		else if (ch == "002")
		{
			Control_Main(12);
		}
		else if (ch == "003")
		{
			;
		}
		else if (ch == "999")
		{
			exit(1);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(1);
		}
	}
	//开始界面
	if (ID == 11)
	{
		Print_Main(11);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			Control_Main(111);
		}
		else if (ch == "002")
		{
			Control_Main(112);
		}
		else if (ch == "003")
		{
			Control_Main(113);
		}
		else if (ch == "999")
		{
			Control_Main(1);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(11);
		}
	}
	//支援卡对比界面
	if(ID==113)
	{
		setrw.write_setting(set1);
		Print_Main(113);
		string ch;
		cin>>ch;
		if(ch=="001")
		{
			ui.print_tip("请输入标准卡名称：");
			ui.print_input();
			cin >> ch;
			resrw.read_res(ch, uma1);
			ui.print_tip("读取成功！");
			ui.print_tip("请输入对比卡名称：");
			ui.print_input();
			cin >> ch;
			resrw.read_res(ch, uma2);
			ui.print_tip("读取成功！");
			Control_Main(1132);
		}
	}
	//开始对比界面
	if(ID==1132)
	{
		Print_Main(1132);
	}
	//设置界面
	if (ID == 12)
	{
		setrw.read_setting(set1);
		Print_Main(12);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			Control_Main(121);
		}
		else if (ch == "002")
		{
			Control_Main(122);
		}
		else if (ch == "003")
		{
			Control_Main(123);
		}
		else if (ch == "004")
		{
			Control_Main(124);
		}
		else if (ch == "010")
		{
			Control_Main(1210);
		}
		else if (ch == "999")
		{
			Control_Main(1);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(12);
		}
	}


	//设置下 显示设置界面
	if (ID == 121)
	{
		Print_Main(121);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			Control_Main(1211);
		}
		else if (ch == "002")
		{
			Control_Main(1212);
		}
		else if (ch == "003")
		{
			if (set1.IS_RESERVE0_BONUSARR)
			{
				set1.IS_RESERVE0_BONUSARR = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_RESERVE0_BONUSARR = true;
				setrw.write_setting(set1);
			}
			Control_Main(121);
		}
		else if (ch == "004")
		{
			if (set1.IS_SHOW_WELCOME)
			{
				set1.IS_SHOW_WELCOME = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_SHOW_WELCOME = true;
				setrw.write_setting(set1);

			}
			Control_Main(121);
		}
		else if (ch == "005")
		{
			ui.print_tip("请输入数字精度");
			ui.print_input(3);
			cin >> set1.FLOAT_PRECISION;
			setrw.write_setting(set1);

			Control_Main(121);
		}
		else if (ch == "999")
		{
			Control_Main(12);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(121);
		}
	}
	//设置下 计算设置界面
	if (ID == 122)
	{
		Print_Main(122);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			if (set1.IS_CALCULATE_EVALV1)
			{
				set1.IS_CALCULATE_EVALV1 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_CALCULATE_EVALV1 = true;
				setrw.write_setting(set1);

			}
			Control_Main(122);
		}
		else if (ch == "002")
		{
			if (set1.IS_CALCULATE_EVALV2)
			{
				set1.IS_CALCULATE_EVALV2 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_CALCULATE_EVALV2 = true;
				setrw.write_setting(set1);

			}
			Control_Main(122);
		}
		else if (ch == "003")
		{
			if (set1.IS_CALCULATE_EVALV3)
			{
				set1.IS_CALCULATE_EVALV3 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_CALCULATE_EVALV3 = true;
				setrw.write_setting(set1);

			}
			Control_Main(122);
		}
		else if (ch == "004")
		{
			if (set1.IS_CALCULATE_EVALV4)
			{
				set1.IS_CALCULATE_EVALV4 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_CALCULATE_EVALV4 = true;
				setrw.write_setting(set1);

			}
			Control_Main(122);
		}
		else if (ch == "005")
		{
			if (set1.IS_CALCULATE_EVALV5)
			{
				set1.IS_CALCULATE_EVALV5 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_CALCULATE_EVALV5 = true;
				setrw.write_setting(set1);

			}
			Control_Main(122);
		}
		else if (ch == "999")
		{
			Control_Main(12);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(122);
		}
	}
	//设置下 文件界面
	if (ID == 123)
	{
		Print_Main(123);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			if (set1.IS_AUTO_SAVE)
			{
				set1.IS_AUTO_SAVE = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_AUTO_SAVE = true;
				setrw.write_setting(set1);

			}
		}
		else if (ch == "999")
		{
			Control_Main(12);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(123);
		}
	}
	//设置下 控制界面
	if (ID == 124)
	{
		Print_Main(124);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			if (set1.IS_GLOABL_CONTROL)
			{
				set1.IS_GLOABL_CONTROL = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_GLOABL_CONTROL = true;
				setrw.write_setting(set1);

			}
		}
		else if (ch == "999")
		{
			Control_Main(12);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续");
			_pause();
			Control_Main(124);
		}
	}
	//设置下 显示设置下 评分展示界面
	if (ID == 1211)
	{
		Print_Main(1211);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			if (set1.IS_SHOW_EVALV3)
			{
				set1.IS_SHOW_EVALV3 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_SHOW_EVALV3 = true;
				setrw.write_setting(set1);

			}
			Control_Main(1211);
		}
		else if (ch == "002")
		{
			if (set1.IS_SHOW_EVALV4)
			{
				set1.IS_SHOW_EVALV4 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_SHOW_EVALV4 = true;
				setrw.write_setting(set1);

			}
			Control_Main(1211);
		}
		else if (ch == "003")
		{
			if (set1.IS_SHOW_EVALV5)
			{
				set1.IS_SHOW_EVALV5 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_SHOW_EVALV5 = true;
				setrw.write_setting(set1);

			}
			Control_Main(1211);
		}
		else if (ch == "999")
		{
			Control_Main(121);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(1211);
		}
	}
	//设置下 显示设置下 辅助面板界面
	if (ID == 1212)
	{
		Print_Main(1212);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			if (set1.IS_SHOW_EVALV1)
			{
				set1.IS_SHOW_EVALV1 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_SHOW_EVALV1 = true;
				setrw.write_setting(set1);

			}
			Control_Main(1212);
		}
		else if (ch == "002")
		{
			if (set1.IS_SHOW_EVALV2)
			{
				set1.IS_SHOW_EVALV2 = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_SHOW_EVALV2 = true;
				setrw.write_setting(set1);

			}
			Control_Main(1212);
		}
		else if (ch == "003")
		{
			if (set1.IS_SHOW_STRIKE)
			{
				set1.IS_SHOW_STRIKE = false;
				setrw.write_setting(set1);

			}
			else
			{
				set1.IS_SHOW_STRIKE = true;
				setrw.write_setting(set1);

			}
			Control_Main(1212);
		}
		else if (ch == "999")
		{
			Control_Main(121);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(1212);
		}
	}
	

	//开始下 新建支援卡界面
	if (ID == 111)
	{
		Print_Main(111);
		string temp;
		cin >> temp;
		if (temp == "100")
		{
			ui.print_text("Changed:支援卡类型 Now:", 4, 0);
			int temp_type;
			uma1.Output<int>("type_static", temp_type);
			switch (temp_type)
			{
			case 0:ui.print_text("速度", 6); break;
			case 1:ui.print_text("耐力", 1); break;
			case 2:ui.print_text("力量", 2); break;
			case 3:ui.print_text("根性", 5); break;
			case 4:ui.print_text("智力", 3); break;
			default:ui.print_text("未知");
			}
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			try
			{
				uma1.Input("type_static", num);
			}
			catch (const char& err)
			{
				cerr << err << endl;
			}
		}
		else if (temp == "101")
		{
			ui.print_text("Changed:友情加成 Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_award")), 0, 0);
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("friendship_award", num);
		}
		else if (temp == "102")
		{
			ui.print_text("Changed:固有友情 Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_static")), 0, 0);
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("friendship_static", num);
		}
		else if (temp == "103")
		{
			ui.print_text("Changed:干劲加成 Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 0, 0);
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("enthusiasm_award", num);
		}
		else if (temp == "104")
		{
			ui.print_text("Changed:训练加成 Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 0, 0);
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("training_award", num);
		}
		else if (temp == "105")
		{
			ui.print_text("Changed:得意率 Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("strike_point")), 0, 0);
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("strike_point", num);
		}
		else if (temp == "106")
		{
			ui.print_text("Changed:初期羁绊 Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_point")), 0, 0);
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("friendship_point", num);
		}
		else if (temp == "107")
		{
			ui.print_text("Changed:Bonus数组 Now:{", 4, 0);
			{
				int temp;
				uma1.Output<int>("speed_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 6, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("stamina_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 1, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("power_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 2, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("willpower_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 5, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("wit_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 3, 0);
					ui.print_text(" ", 0, 0);
				}
				uma1.Output<int>("sp_bonus", temp);
				if (temp > 0)
				{
					ui.print_text(to_string(temp), 4, 0);
					ui.print_text(" ", 0, 0);
				}
				ui.print_text("}", 4, 0);
				ui.endl_();
			}
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			vector<unsigned>bonus{ 0,0,0,0,0,0 };
			for (auto& i : bonus)
			{
				cin >> i;
			}
			try
			{
				uma1.Input("speed_bonus", bonus[0]);
				uma1.Input("stamina_bonus", bonus[1]);
				uma1.Input("power_bonus", bonus[2]);
				uma1.Input("willpower_bonus", bonus[3]);
				uma1.Input("wit_bonus", bonus[4]);
				uma1.Input("sp_bonus", bonus[5]);
			}
			catch (const char& err)
			{
				cerr << err << endl;
			}
		}
		else if(temp == "200")
		{
			Control_Main(-10);
		}
		else if (temp == "201")
		{
			uma1.Import(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		}
		else if (temp == "202")
		{
			ui.print_text("Changed:支援卡标识 Now:", 4, 0);
			for (int i=0;i<strlen(uma1.cardname_static);i++)
			{
				ui.print_text(uma1.cardname_static[i], 0, 0);
			}
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			string cr;
			cin >> cr;
			strcpy(uma1.cardname_static, cr.c_str());
		}
		else if (temp == "999")
		{
			Control_Main(11);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(111);
		}
		Control_Main(111);
	}
	//开始下 支援卡计算结果展示界面
	if (ID == 1112)
	{
		if (set1.IS_AUTO_SAVE)
		{
			resrw.write_res(uma1.cardname_static, uma1);
		}
		Print_Main(1112);
		string ch;
		cin >> ch;
		if (ch == "001")
		{
			Control_Main(111);
		}
		else if (ch == "002")
		{
			ui.print_text("Changed:支援卡标识 Now:", 4, 0);
			for (int i = 0; i < strlen(uma1.cardname_static); i++)
			{
				ui.print_text(uma1.cardname_static[i], 0, 0);
			}
			ui.endl_();
			ui.print_tip("请输入更改的值");
			ui.print_input(3);
			string cr;
			cin >> cr;
			strcpy(uma1.cardname_static, cr.c_str());
			Control_Main(1112);
		}
		else if (ch == "003")
		{
			if (!set1.IS_AUTO_SAVE)
			{
				resrw.write_res(uma1.cardname_static,uma1);
				//if (uma1.cardname_static == "未命名")
				//{
				//	string filepath = "\"\\Assets\\Data\\Save\\";
				//	filepath = filepath + uma1.cardname_static;
				//	filepath += ".UmaSCE_Data";
				//	fstream fin(filepath, ios_base::in |ios_base::out| ios_base::binary | ios_base::app);
				//	if (fin.is_open())
				//	{
				//		fin.write(reinterpret_cast<char*>(&uma1), sizeof uma1);
				//	}
				//}
				//else
				//{
				//	ofstream fout("./Assets/Data/default.UmaSCE_Data", std::ios_base::out | std::ios_base::binary | std::ios_base::app);
				//	if (!fout) 
				//	{
				//		// file doesn't exist, create and write
				//		ifstream fi;
				//		fi.open("./Assets/Data/default.UmaSCE_Data", std::ios_base::in | std::ios_base::binary);
				//	}
				//	fout.open("./Assets/Data/default.UmaSCE_Data", std::ios_base::out | std::ios_base::binary );
				//	if (fout)
				//	{
				//		fout.write(reinterpret_cast<char*>(&uma1), sizeof(uma1));
				//		fout.close();
				//		cout << "Data written successfully." << std::endl;
				//	}
				//	else 
				//	{
				//			std::cout << "Error opening file." << std::endl;
				//	}
				//}
				ui.print_tip("保存成功！", 3);
				ui.print_tip("按下任意键继续...");
			}
			else
			{
				ui.print_tip("自动保存已开启，无需手动保存", 3);
				ui.print_tip("按下任意键继续...");
			}
			_pause();
			Control_Main(1112);
		}
		else if (ch == "999")
		{
			Control_Main(11);
		}
		else
		{
			ui.print_tip("不存在的选项", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(1112);
		}
	}


	//开始下 打开保存的支援卡界面
	if (ID == 112)
	{
		Print_Main(112);
		//获取保存的支援卡名称
		string name;
		cin>>name;
		//打开保存的文件
		/*string filepath = "\"\\Assets\\Data\\Save\\";
		filepath = filepath + name;
		filepath += ".UmaSCE_Data";
		ifstream fin(filepath, ios_base::in | ios_base::binary);
		if (fin.is_open())
		{
			fin.read(reinterpret_cast<char*>(&uma1), sizeof(uma1));
			fin.close();
			Control_Main(111);
		}
		else
		{
			ui.print_tip("文件不存在！", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(112);
		}
		*/
		int testx = resrw.read_res(name, uma1);
		if (testx==0){
			Control_Main(111);
		}
		else if (testx == 1)
		{
			ui.print_tip("文件不存在！", 1);
			ui.print_tip("按下任意键继续...");
			_pause();
			Control_Main(112);
		}
		else if (testx == 2)
		{
			Control_Main(112);
		}
	}


	//开始下 支援卡对比界面
	if (ID == 113)
	{
		Print_Main(113);
		string name;
		cin >> name;
	}

	//正在计算界面（独立的）
	if (ID == -10)
	{
		Print_Main(-10);
		ui.print_text("EvalV3...", 0, 1);
		uma1.EvalV3();
		ui.print_text("Finish!", 3);
		ui.print_text("EvalV4...", 0, 1);
		uma1.EvalV4();
		ui.print_text("Finish!", 3);
		ui.print_text("EvalV5...", 0, 1);
		uma1.EvalV5(set1.EVALV5_TIMES);
		ui.print_text("Finish!", 3);
		ui.print_text("按下任意键展示结果...");
		_pause();
		Control_Main(1112);
	}


	//不存在的界面
	if(1)
	{
		Print_Main(-1);
		_pause();
		Control_Main(1);
	}
}