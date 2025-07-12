#pragma once
struct SCE_Setting_Struct
{
	//展示得意率
	bool IS_SHOW_STRIKE;
	//展示EvalV1评分
	bool IS_SHOW_EVALV1;
	//计算EvalV1评分
	bool IS_CALCULATE_EVALV1;
	//展示EvalV2评分
	bool IS_SHOW_EVALV2;
	//计算EvalV2评分
	bool IS_CALCULATE_EVALV2;
	//展示EvalV3评分
	bool IS_SHOW_EVALV3;
	//计算EvalV3评分
	bool IS_CALCULATE_EVALV3;
	//展示EvalV4评分
	bool IS_SHOW_EVALV4;
	//计算EvalV4评分
	bool IS_CALCULATE_EVALV4;
	//展示EvalV5评分
	bool IS_SHOW_EVALV5;
	//计算EvalV5评分
	bool IS_CALCULATE_EVALV5;
	//Bonus数组展示0
	bool IS_RESERVE0_BONUSARR;
	//数字精度
	int FLOAT_PRECISION;
	//欢迎界面
	bool IS_SHOW_WELCOME;
	//自动保存
	bool IS_AUTO_SAVE;
	//全局控制
	bool IS_GLOABL_CONTROL;
	//EvalV5计算次数
	unsigned EVALV5_TIMES;
	//显示Emoji
	bool USE_EMOJI;
	//随机显示Emoji
	bool RAND_EMOJI;
};