###### (｡･∀･)ﾉﾞ嗨，欢迎来到UmaSCE项目的开发文档!
希望这份文档会对你有一定的帮助。  
首先，让我们来学习UmaSCE_Main的使用方法！
***
# UmaSCE_Main
## 成员列表
### poctected成员
#### type_static
这是一个`int`变量，用于储存支援卡的类型  
取值范围：**[ 0 , 4 ]**  
其中，0代表速度，1代表耐力，2代表力量，3代表根性，4代表智力  
> 你可以尝试赋值一个值域范围之外的数值，在早期的设计中，这是不被允许的，程序会因此报错，并调用`abort()`退出程序。但现在只会发出抛出一串`char`错误码
***
#### friendship_static
这是一个`int`变量，用于储存支援卡的固有友情加成  
~其实，没什么好说的......~
***
#### friendship_award
这是一个`int`变量，用于储存支援卡的友情加成
***
#### enthusiasm_award
这是一个`int`变量，用于储存支援卡的干劲加成
***
#### training_award
这是一个`int`变量，用于储存支援卡的训练加成
***
#### strike_point
这是一个`int`变量，用于储存支援卡的得意率
***
#### friendship_point
这是一个`int`变量，用于储存支援卡的初羁绊
***
#### *_bonus
都是`int变量，分别储存支援卡的各种属性加成  
包含如下：  
1. speed - 速度
2. stamina - 耐力
3. power - 力量
4. willpower - 根性
5. wit - 智力
6. sp - 技能点
***
#### v1_ept
这是一个`double`变量，用于储存v1_ept评分  
> 在早期，我们没有提供这个方法。在SCE.exe中，我们称之为`友情倍率`，现在我们提供了相应的算法，并且你可以直接使用了
***
#### v2_ept
这是一个`double`变量，用于储存v2_ept评分  
> 同样的，在早期，我们没有提供相应的方法。以前，我们称之为`总友情倍率`，不过现在，你可以直接使用了
***
#### v3_ept
这是一个`double`变量，用于存储v3_ept评分  
> 本质上，v3_ept就是V3G1评分，不过现在我们稍微修葺了一下
#### v4*_ept
这是一坨`int`变量，用于存储v4_ept评分  
包含如下：  
1. main - 得意训练评分
2. fold - 逛街训练评分
3. sp - 技能点评分
> 本质上，v4_ept就是V4G1评分，不过现在我们大刀阔斧的修改了一番
***
#### v5*_ept
这是一坨`int`变量，用于存储v5_ept评分  
包含如下：  
1. main - 得意训练评分
2. fold - 逛街训练评分
3. sp - 技能点评分
> 在早期，这个想法因为技术不成熟被嘎了，现在强势回归！
***
### public成员
#### cardname_static
这是一个`char[]`变量，用于储存支援卡标识  
长度：`20`  
> 本来我是不准备添加这个玩意的，但是有总比没有好......
***
#### UmaSCE_Main_Diset
这是一个`struct`  
包含如下成员：  
1. abex_di</br>类型：`int[]` 长度：`5`  </br>用于储存Di计算中的绝对期待值
2. tolerance_di</br>类型：`int[]` 长度：`5`  </br>用于储存Di计算中的宽容度
***
#### UmaSCE_Main_V5click
这是一个`struct`  
包含如下成员：  
1. ground</br>类型：`int[]` 长度：`5`  </br>用于储存EvalV5中的各场地点击次数
***
### private成员
#### unstrike_v1
这是一个`double`变量，虽然开发者们也用不到吧。用来储存非得意训练的友情倍率
***
#### is_notice
这是一个`bool`变量，这个开发者们就用的到了，虽然有些bug。用来控制是否在在出现错误的时候抛出错误码
***
#### is_dominant_lead
这是一个`bool`变量，用于EvalV5决定跑法是否为大逃
***
#### length
这是一个`int`变量，用于EvalV5储存比赛距离  
其中：  
1 - 短距离  
2 - 英里  
3 - 中距离  
4 - 长距离  
***
#### present_ground
这是一个`int`变量，用于EvalV5储存支援卡当前处于的训练场地，值域同type_static
***
#### present_friendship_point
这个一个`int`变量，用于EvalV5储存支援卡当前羁绊
***
#### v5click
这是一个`UmaSCE_Main_V5click`变量，用于EvalV5储存各个场地的点击次数
***
## 方法列表
### public方法
> 其实我们只有public方法
#### UmaSCE_Main()
UmaSCE_Main使用了隐式构造函数，尽力了尽力了
***
#### ~UmaSCE_Main()
UmaSCE_Main使用了隐式析构函数，尽力了尽力了，不过这个类也不需用析构函数
***
#### Exchange(UmaSCE_Main&)
返回值：`void`  
用于交换两个`UmaSCE_Main`值
***
#### Copy(UmaSCE_Main)
返回值：`void`  
用于将源对象赋值给目标对象
***
#### Input(string Val_Typename,int Val)
返回值：`void`  
将Val赋值给Val_Typename对象，Val_Typename的值为protected成员
***
#### Import(int type_static_, int friendship_static_, int friendship_award_, int enthusiasm_award_, int training_award_, int strike_point_, int friendship_point_, int speed_bonus_, int stamina_bonus_, int power_bonus_, int willpower_bonus_, int wit_bonus_, int sp_bonus_)
返回值：`void`  
批量赋值，等效于构造函数
***
#### Export(int& type_static_, int& friendship_static_, int& friendship_award_, int& enthusiasm_award_, int& training_award_, int& strike_point_, int& friendship_point_, int& speed_bonus_, int& stamina_bonus_, int& power_bonus_, int& willpower_bonus_, int& wit_bonus_, int& sp_bonus_) const
返回值：`void`  
用于将`UmaSCE_Main`的值导出
***
#### Export(double& v1_ept_, double& v2_ept_, double& v3_ept_, int& v4main_ept_, int& v4fold_ept_, int& v4sp_ept_, int& v5main_ept_, int& v5fold_ept_, int& v5sp_ept_) const
返回值：`void`
用于将`UmaSCE_Main`的值导出，不过是导出各个评分的版本
***
#### Output(string Val_Typename) const
返回值：`void`
用于打印Val_Typename，注意是直接打印！
*** 
#### void Output(string Val_Typename, int& Carrier) const
返回值：`void`  
用于将 Val_Typename导出至Carrier
> 一个莫名奇妙的方法，`Output(string Val_Typename) const`方法是直接输出，而`void Output(string Val_Typename, int& Carrier) const`方法却是导出Val_Typename的值，这来源我莫名其妙的主意
***
#### Output(string Val_Typename, double& Carrier) const
返回值：`void`  
用于将 Val_Typename导出至Carrier
> 更加莫名其妙的重载版本，虽然模板是更好的做法......
***
#### Destroy()
返回值：`void`  
用于清空`UmaSCE_Main`的值
***
#### Destroy(string Val_Typename)
返回值：`void`  
用于清空`UmaSCE_Main`的特定值  
其中，Val_Typename的值包括：
1. ALL - 所有
2. EPT - 评分
3. VAL - 评分的补集
> Destroy()版本似乎是多余的，因为可以使用默认参数
***
#### Layout(string Val_Typename, int Val)
返回值：`void`  
用于设置一些private成员  
其中，Val_Typename包括：
1. notice
2. is_dominant_lead
3. length
***
#### EvalV1()
返回值：`void`  
仅进行计算EvalV1
***
#### EvalV1(bool is_return）
返回值：`double`  
计算后同时会返回`v1_ept`
***
#### EvalV1(double& Carrier)
返回值：`void`  
计算后同时会将`v1_ept`赋值给`Carrier`
***