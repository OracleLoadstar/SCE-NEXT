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
	//��ӭ����
	if (ID == 0)
	{
		//test
		// _pause();
		// model mo;
		// mo.check_model("../test.model");
		// _pause();
		// test
		ui.cls();
		ui.print_title("��ã�ѵ��Ա��");
		ui.print_text("��ӭʹ��SupportCard Evalator");
		//���������������ݼ��汾��
		ui.print_text("Version:5.0B8", 5);

		ui.print_text("�������ݣ�", 4);
		ui.print_tip("a.�޸���һЩbug");
		//...
		ui.print_text("�������������...");
		ui.print_input();
	}
	//������
	if (ID == 1)
	{
		ui.cls();
		ui.print_title("SCE_CH3CH2CH3", 2);
		ui.print_option("��ʼ", "001",1);
		ui.print_option("����", "002",1);
		ui.print_option("����", "003",1,1);
		ui.print_option("�˳�", "999",1);
		ui.print_input();
	}
	//��ʼ����
	if (ID == 11)
	{
		ui.cls();
		ui.print_title("��ʼ", 2);
		ui.print_option("�����µ�֧Ԯ��", "001",1);
		ui.print_option("�򿪱����֧Ԯ��", "002",1,1);
		ui.print_option("֧Ԯ���Ա�", "003",1);
		ui.print_option("����������", "999",1);
		ui.print_input();
	}
	//֧Ԯ���ԱȽ���
	if(ID==113)
	{
		
		ui.cls();
		ui.print_title("֧Ԯ���Ա�", 2);
		ui.print_option("�򿪱�׼��", "001", 1);
		ui.print_option("��ʼ�Ա�", "002",1);
		ui.print_option("���ؿ�ʼ����", "999", 1);
		ui.print_input();
	}
	//��ʼ�Ա�֧Ԯ������
	if(ID==1132)
	{
		ui.cls();
		ui.print_title("֧Ԯ���Ա�",2);
		ui.print_text(uma1.cardname_static,6,0);
		//...
		//...
		ui.print_text(uma2.cardname_static,1);
	}
	//���ý���
	if (ID == 12)
	{
		ui.cls();
		ui.print_title("����", 2);
		ui.print_option("��ʾ", "001",1);
		ui.print_option("����", "002",1);
		ui.print_option("�ļ�", "003",1,1);
		ui.print_option("����", "004",1);
		ui.print_option("������", "010",1,1);
		ui.print_option("������ҳ", "999",1);
		ui.print_input();
	}


	//������ ��ʾ���ý���
	if (ID == 121)
	{
		ui.cls();
		ui.print_title("���� -> ��ʾ", 2);
		ui.print_option("����չʾ{}", "001",1);
		ui.print_option("�������{}", "002",1);
		if(set1.IS_RESERVE0_BONUSARR)
		{
			ui.print_option("���Լӳ�������ʾ0 -> ��", "003",1);
		}
		else
		{
			ui.print_option("���Լӳ�������ʾ0 -> ��", "003",1);
		}
		if (set1.IS_SHOW_WELCOME)
		{
			ui.print_option("��ӭ���� -> ��", "004",1);
		}
		else
		{
			ui.print_option("��ӭ���� -> ��", "004",1);
		}
		ui.print_option("���־��� -> ", "005",0,0,4,0);
		ui.print_text(to_string(set1.FLOAT_PRECISION), 4);
		ui.print_option("��������", "999",1);
		ui.print_input();
	}
	//������ �������ý���
	if (ID == 122)
	{
		ui.cls();
		ui.print_title("���� -> ����", 2);
		if (set1.IS_CALCULATE_EVALV1)
		{
			ui.print_option("����EvalV1 -> ��", "001",1);
		}
		else
		{
			ui.print_option("����EvalV1 -> ��", "001",1);
		}
		if (set1.IS_CALCULATE_EVALV2)
		{
			ui.print_option("����EvalV2 -> ��", "002",1);
		}
		else
		{
			ui.print_option("����EvalV2 -> ��", "002",1);
		}
		if (set1.IS_CALCULATE_EVALV3)
		{
			ui.print_option("����EvalV3 -> ��", "003",1);
		}
		else
		{
			ui.print_option("����EvalV3 -> ��", "003",1);
		}
		if (set1.IS_CALCULATE_EVALV4)
		{
			ui.print_option("����EvalV4 -> ��", "004",1);
		}
		else
		{
			ui.print_option("����EvalV4 -> ��", "004",1);
		}
		if (set1.IS_CALCULATE_EVALV5)
		{
			ui.print_option("����EvalV5 -> ��", "005",1);
		}
		else
		{
			ui.print_option("����EvalV5 -> ��", "005",1);
		}
		ui.print_option("��������", "999",1);
		ui.print_input();
	}
	//������ �ļ�����
	if (ID == 123)
	{
		ui.cls();
		ui.print_title("���� -> �ļ�", 2);
		if (set1.IS_AUTO_SAVE)
		{
			ui.print_option("�Զ����� -> ��", "001",1,2);
		}
		else
		{
			ui.print_option("�Զ����� -> ��", "001",1,2);
		}
		ui.print_option("��������", "999",1);
		ui.print_input();
	}
	//������ ���ƽ���
	if (ID == 124)
	{
		ui.cls();
		ui.print_title("���� -> ����", 2);
		if (set1.IS_GLOABL_CONTROL)
		{
			ui.print_option("ȫ�ֿ��� -> ��","001",1);
		}
		else
		{
			ui.print_option("ȫ�ֿ��� -> ��", "001",1);
		}
		ui.print_option("��������", "999",1);
		ui.print_input();
	}
	//������ ��ʾ������ ����չʾ����
	if (ID == 1211)
	{
		ui.cls();
		ui.print_title("���� -> ��ʾ -> ����չʾ", 2);
		if(set1.IS_SHOW_EVALV3)
		{
			ui.print_option("չʾEvalV3���� -> ��", "001",1);
		}
		else
		{
			ui.print_option("չʾEvalV3���� -> ��", "001",1);
		}
		if (set1.IS_SHOW_EVALV4)
		{
			ui.print_option("չʾEvalV4���� -> ��", "002",1);
		}
		else
		{
			ui.print_option("չʾEvalV4���� -> ��", "002",1);
		}
		if (set1.IS_SHOW_EVALV5)
		{
			ui.print_option("չʾEvalV5���� -> ��", "003",1);
		}
		else
		{
			ui.print_option("չʾEvalV5���� -> ��", "003",1);
		}
		ui.print_option("������ʾ", "999",1);
		ui.print_input();
	}
	//������ ��ʾ������ ����������
	if (ID == 1212)
	{
		ui.cls();
		ui.print_title("���� -> ��ʾ -> �������", 2);
		if (set1.IS_SHOW_EVALV1)
		{
			ui.print_option("չʾEvalV1���� -> ��", "001",1);
		}
		else
		{
			ui.print_option("չʾEvalV1���� -> ��", "001",1);
		}
		if (set1.IS_SHOW_EVALV2)
		{
			ui.print_option("չʾEvalV2���� -> ��", "002",1);
		}
		else
		{
			ui.print_option("չʾEvalV2���� -> ��", "002",1);
		}
		if (set1.IS_SHOW_STRIKE)
		{
			ui.print_option("չʾ������ -> ��", "003",1);
		}
		else
		{
			ui.print_option("չʾ������ -> ��", "003",1);
		}
		ui.print_option("������ʾ", "999",1);
		ui.print_input();
	}


	//��ʼ�� �½�֧Ԯ������
	if (ID == 111)
	{
		ui.cls();
		ui.print_title("��ʼ -> ",2,0);
		ui.print_text(uma1.cardname_static, 2, 0,'_');
		ui.print_text("Ԥ��", 2,1,'_');
		ui.print_option("֧Ԯ�����ͣ�", "100", 0, 0, 4, 0);
		int temp_type = 0;
		try
		{
			uma1.Output<int>("type_static", temp_type);
			switch (temp_type)
			{
			case 0:ui.print_text("�ٶ�", 6); break;
			case 1:ui.print_text("����", 1); break;
			case 2:ui.print_text("����", 2); break;
			case 3:ui.print_text("����", 5); break;
			case 4:ui.print_text("����", 3); break;
			default:ui.print_text("δ֪");
			}
		}
		catch (const char* err)
		{
			cerr << err << endl;
		}
		try
		{
			ui.print_option("����ӳɣ�", "101", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_award")), 4);
			ui.endl_();
			ui.print_option("�������飺", "102", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_static")), 4);
			ui.endl_();
			ui.endl_();
			ui.print_option("�ɾ��ӳɣ�", "103", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("enthusiasm_award")), 4);
			ui.endl_();
			ui.print_option("ѵ���ӳɣ�", "104", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 4);
			ui.endl_();
			ui.endl_();
			ui.print_option("�� �� �ʣ�", "105", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("strike_point")), 4);
			ui.endl_();
			ui.print_option("�����", "106", 0, 0, 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_point")), 4);
			ui.endl_();
			ui.endl_();

			ui.print_option("Bonus���飺{ ", "107", 0, 0, 4, 0);
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
		ui.print_option("��ʼ����", "200", 1);
		ui.print_option("���Ԥ��", "201", 1);
		ui.print_option("�޸�֧Ԯ����ʶ��", "202", 1);
		ui.print_option("���ؿ�ʼ����", "999", 1);
		ui.print_input();
	}
	//��ʼ�� ֧Ԯ��������չʾ����
	if (ID == 1112)
	{
		ui.cls();
		ui.print_title("��ʼ -> ���չʾ", 2);
		ui.print_tip("֧Ԯ����Ϣһ��", 6);
		try
		{
			ui.print_text("����|���У�", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_award")), 0, 0);
			ui.print_text("|", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_static")), 0, 0);
			ui.endl_();
			ui.print_text("�ɾ�|ѵ����", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("enthusiasm_award")), 0, 0);
			ui.print_text("|", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 0, 0);
			ui.endl_();
			ui.print_text("���|�����ʣ�", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_point")), 0, 0);
			ui.print_text("|", 0, 0);
			ui.print_text(to_string(uma1.Output<int>("strike_point")), 0, 0);
			ui.endl_();
			ui.print_text("Bonus���飺{ ", 0,0);
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
			ui.print_text("EvalV3 �÷�->", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("v3_ept")), 4, 0);
			ui.endl_();
			ui.endl_();
			ui.print_text("EvalV4 ��Ҫѵ���÷�->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v4main_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV4 ���ѵ���÷�->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v4fold_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV4 S P ѵ���÷�->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v4sp_ept")), 2, 0);
			ui.endl_();

			ui.endl_();
			ui.print_text("EvalV5 ��Ҫѵ���÷�->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v5main_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV5 ���ѵ���÷�->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v5fold_ept")), 2, 0);
			ui.endl_();
			ui.print_text("EvalV5 S P ѵ���÷�->", 2, 0);
			ui.print_text(to_string(uma1.Output<int>("v5sp_ept")), 2, 0);
			ui.endl_();
		}
		catch (const char& err)
		{
			cerr << err << endl;
		}
		ui.print_option("���ر༭", "001", 1);
		ui.print_option("�޸�֧Ԯ����ʶ��", "002", 1);
		ui.print_option("����֧Ԯ����Ϣ", "003", 1, 1);
		ui.print_option("�ص���ʼ", "999", 1);
		ui.print_input();
	}


	//��ʼ�� �򿪱����֧Ԯ������
	if (ID == 112)
	{
		ui.cls();
		ui.print_title("��ʼ -> �򿪱����֧Ԯ��", 2);
		ui.print_tip("�����뱣���֧Ԯ���ļ���", 6);
		ui.print_input(2);
	}


	//��ʼ�� ֧Ԯ���ԱȽ���
	if (ID == 113)
	{
		;
	}


	//���ڼ�����棨�����ģ�
	if (ID == -10)
	{
		ui.cls();
		ui.print_title("���ڼ�������", 4);
	}


	//�����ڵĽ���
	if (ID == -1)
	{
		ui.cls();
		ui.print_tip("�����ڵĽ���", 1);
		ui.print_tip("����������ص���ҳ...");
		ui.print_input();
	}
}

void Control_Main(int ID)
{
	//��ӭ����
	//��������
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
	//������
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(1);
		}
	}
	//��ʼ����
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(11);
		}
	}
	//֧Ԯ���ԱȽ���
	if(ID==113)
	{
		setrw.write_setting(set1);
		Print_Main(113);
		string ch;
		cin>>ch;
		if(ch=="001")
		{
			ui.print_tip("�������׼�����ƣ�");
			ui.print_input();
			cin >> ch;
			resrw.read_res(ch, uma1);
			ui.print_tip("��ȡ�ɹ���");
			ui.print_tip("������Աȿ����ƣ�");
			ui.print_input();
			cin >> ch;
			resrw.read_res(ch, uma2);
			ui.print_tip("��ȡ�ɹ���");
			Control_Main(1132);
		}
	}
	//��ʼ�ԱȽ���
	if(ID==1132)
	{
		Print_Main(1132);
	}
	//���ý���
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(12);
		}
	}


	//������ ��ʾ���ý���
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
			ui.print_tip("���������־���");
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(121);
		}
	}
	//������ �������ý���
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(122);
		}
	}
	//������ �ļ�����
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(123);
		}
	}
	//������ ���ƽ���
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������");
			_pause();
			Control_Main(124);
		}
	}
	//������ ��ʾ������ ����չʾ����
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(1211);
		}
	}
	//������ ��ʾ������ ����������
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(1212);
		}
	}
	

	//��ʼ�� �½�֧Ԯ������
	if (ID == 111)
	{
		Print_Main(111);
		string temp;
		cin >> temp;
		if (temp == "100")
		{
			ui.print_text("Changed:֧Ԯ������ Now:", 4, 0);
			int temp_type;
			uma1.Output<int>("type_static", temp_type);
			switch (temp_type)
			{
			case 0:ui.print_text("�ٶ�", 6); break;
			case 1:ui.print_text("����", 1); break;
			case 2:ui.print_text("����", 2); break;
			case 3:ui.print_text("����", 5); break;
			case 4:ui.print_text("����", 3); break;
			default:ui.print_text("δ֪");
			}
			ui.print_tip("��������ĵ�ֵ");
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
			ui.print_text("Changed:����ӳ� Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_award")), 0, 0);
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("friendship_award", num);
		}
		else if (temp == "102")
		{
			ui.print_text("Changed:�������� Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_static")), 0, 0);
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("friendship_static", num);
		}
		else if (temp == "103")
		{
			ui.print_text("Changed:�ɾ��ӳ� Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 0, 0);
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("enthusiasm_award", num);
		}
		else if (temp == "104")
		{
			ui.print_text("Changed:ѵ���ӳ� Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("training_award")), 0, 0);
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("training_award", num);
		}
		else if (temp == "105")
		{
			ui.print_text("Changed:������ Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("strike_point")), 0, 0);
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("strike_point", num);
		}
		else if (temp == "106")
		{
			ui.print_text("Changed:����� Now:", 4, 0);
			ui.print_text(to_string(uma1.Output<int>("friendship_point")), 0, 0);
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
			ui.print_input(3);
			unsigned num;
			cin >> num;
			uma1.Input("friendship_point", num);
		}
		else if (temp == "107")
		{
			ui.print_text("Changed:Bonus���� Now:{", 4, 0);
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
			ui.print_tip("��������ĵ�ֵ");
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
			ui.print_text("Changed:֧Ԯ����ʶ Now:", 4, 0);
			for (int i=0;i<strlen(uma1.cardname_static);i++)
			{
				ui.print_text(uma1.cardname_static[i], 0, 0);
			}
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(111);
		}
		Control_Main(111);
	}
	//��ʼ�� ֧Ԯ��������չʾ����
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
			ui.print_text("Changed:֧Ԯ����ʶ Now:", 4, 0);
			for (int i = 0; i < strlen(uma1.cardname_static); i++)
			{
				ui.print_text(uma1.cardname_static[i], 0, 0);
			}
			ui.endl_();
			ui.print_tip("��������ĵ�ֵ");
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
				//if (uma1.cardname_static == "δ����")
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
				ui.print_tip("����ɹ���", 3);
				ui.print_tip("�������������...");
			}
			else
			{
				ui.print_tip("�Զ������ѿ����������ֶ�����", 3);
				ui.print_tip("�������������...");
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
			ui.print_tip("�����ڵ�ѡ��", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(1112);
		}
	}


	//��ʼ�� �򿪱����֧Ԯ������
	if (ID == 112)
	{
		Print_Main(112);
		//��ȡ�����֧Ԯ������
		string name;
		cin>>name;
		//�򿪱�����ļ�
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
			ui.print_tip("�ļ������ڣ�", 1);
			ui.print_tip("�������������...");
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
			ui.print_tip("�ļ������ڣ�", 1);
			ui.print_tip("�������������...");
			_pause();
			Control_Main(112);
		}
		else if (testx == 2)
		{
			Control_Main(112);
		}
	}


	//��ʼ�� ֧Ԯ���ԱȽ���
	if (ID == 113)
	{
		Print_Main(113);
		string name;
		cin >> name;
	}

	//���ڼ�����棨�����ģ�
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
		ui.print_text("���������չʾ���...");
		_pause();
		Control_Main(1112);
	}


	//�����ڵĽ���
	if(1)
	{
		Print_Main(-1);
		_pause();
		Control_Main(1);
	}
}