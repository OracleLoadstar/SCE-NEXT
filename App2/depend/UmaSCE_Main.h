///////////////////////
//   UmaSCE_Main     //
//   By LaT-SKY      //
///////////////////////
#pragma once

#include<string>
#include<map>
using namespace std;

class UmaSCE_Main
{
protected:

	int type_static=0;
	int friendship_static=0;

	int friendship_award=0;
	int enthusiasm_award=0;
	int training_award=0;

	int strike_point=0;
	int friendship_point=0;

	int speed_bonus=0;
	int stamina_bonus=0;
	int power_bonus=0;
	int willpower_bonus=0;
	int wit_bonus=0;
	int sp_bonus=0;

	double v1_ept=0;
	double v2_ept=0;
	double v3_ept=0;

	int v4main_ept=0;
	int v4fold_ept=0;
	int v4sp_ept=0;

	int v5main_ept=0;
	int v5fold_ept=0;
	int v5sp_ept=0;
public:

	char cardname_static[20] = "未命名";

	struct UmaSCE_Main_Diset
	{
		int abex_di[5] = {};
		int tolerance_di[5] = {};
	};

	struct UmaSCE_Main_V5click
	{
		int ground[5];
	};

	void Exchange(UmaSCE_Main&);//a与b交换
	void Copy(UmaSCE_Main);//a从b复制（b的值给a)
	void Input(string Val_Typename,int Val);//从外部赋值给a
	void Import(int type_static_, int friendship_static_, int friendship_award_, int enthusiasm_award_, int training_award_, int strike_point_, int friendship_point_, int speed_bonus_, int stamina_bonus_, int power_bonus_, int willpower_bonus_, int wit_bonus_, int sp_bonus_);//批量赋值给a
	void Export(int& type_static_, int& friendship_static_, int& friendship_award_, int& enthusiasm_award_, int& training_award_, int& strike_point_, int& friendship_point_, int& speed_bonus_, int& stamina_bonus_, int& power_bonus_, int& willpower_bonus_, int& wit_bonus_, int& sp_bonus_) const;//批量输出a的值,此方法不包括各种得分
	void Export(double& v1_ept_, double& v2_ept_, double& v3_ept_, int& v4main_ept_, int& v4fold_ept_, int& v4sp_ept_, int& v5main_ept_, int& v5fold_ept_, int& v5sp_ept_) const;//批量输出ept的值
	template<typename T> T Output(string Val_Typename) const;//依据Val_Typename提供属性
	template<typename T> void Output(string Val_Typename, T& Carrier) const;//依据Val_Typename提供属性
	void Destroy();//清空a的值
	void Destroy(string Val_Typename);//依据类型a清空a的值

	void Layout(string Val_Typename, int Val);//对Uma_SCE_Main进行布局，即设置

	void EvalV1();//计算v1
	double EvalV1(bool is_return);//直接返回值
	void EvalV1(double& Carrier);//直接获得v1_ept

	void EvalV2();//计算v2
	double EvalV2(bool is_return);//直接返回值
	void EvalV2(double& Carrier);//直接获得v2_ept

	void EvalV3();//计算v3
	double EvalV3(bool is_return);//直接返回值
	void EvalV3(double& strike_rate, double& unstrike_rate) const;//获得得意率
	void EvalV3(double& Carrier);//直接获得v3_ept

	void EvalV4();//计算v4
	void EvalV4(int& Carrier_main, int& Carrier_fold, int& Carrier_sp);//直接获得v4_ept
	void EvalV4(double& Carrier_failure_rate);//直接获得failure_rate

	void EvalDi(UmaSCE_Main_Diset diset);//计算di
	void EvalDi(UmaSCE_Main_Diset diset, int& Carrier_main, int& Carrier_fold, int& Carrier_sp);//直接获得di

	void EvalV5(int times);//计算v5

private:
	
	double unstrike_v1_ept=0;
	bool is_notice=true;
	bool is_dominant_lead=false;
	int length=10;
	int present_ground=-1;
	int present_friendship_point=0;
	UmaSCE_Main_V5click v5click = {};
	//map<string, int> valmap_int{};
	//map<string, double> valmap_double{};
	//map<string, bool> valmap_bool{};
	//void Maprefresh();//更新map
};
