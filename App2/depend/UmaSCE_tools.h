#pragma once
///////////////////////////////////
// tools.h   SCE���ܺ���         //
// 1.��Դ����                    //
// 2.debug                       //
// 3.������                    //
// 4.��ʼ��                      //
///////////////////////////////////
// Developer:xingguangcuican6666 //
///////////////////////////////////
#include <string>
#include<filesystem>
#include "UmaSCE_UI.h"
#ifdef _WIN32
#define CLS "cls"
#else
#define CLS "clear"
#endif // _WIN32
#include "json.hpp"
#include <fstream>
#include <cstring>
#include "UmaSCE_Main.h"
#include <iostream>
#include "SCE_Setting.h"
#include <filesystem>
#ifdef _WIN32
#include <direct.h>
#endif
using namespace std;
using json = nlohmann::json;    
extern UmaSCE_Main uma1;
//UmaSCE_Main runtime;

// ��Դ��д

#define ism ifstream
#define osm ofstream
#define isetp i("../assets/setting",ios_base::binary)
#define jsetp j("../assets/setting",ios_base::binary)
#define ksetp k("../assets/setting",ios_base::binary)
#define osetp o("../assets/setting",ios_base::binary)
#define iresp i("../assets/res",ios_base::binary)
#define jresp j("../assets/res",ios_base::binary)
#define kresp k("../assets/res",ios_base::binary)
#define oresp o("../assets/res",ios_base::binary)

//res-rw
class res_rw {
public:
    void sce_error(string type,string resname,UmaSCE_Main runtime){
        string temp_resname="../Assets/Data/User/"+resname+".UmaSCE_Data";
        string temp_directory="../Assets/Data/User/";
        if(std::filesystem::exists(temp_directory)){
            std::filesystem::create_directory(temp_directory);
        }
        if(type=="RE"){
            string option;
            system(CLS);
            ui.print_tip("��������֧Ԯ���洢�ļ���ȡʧ�ܣ�",1);
            ui.print_option("�������ɸ��ļ��������ļ�����","001",0,3,4,false,(char)32);
            ui.print_text("(��ѡ����������Ӧ��֧Ԯ�������¼�������ѡ��)",2);
            ui.print_option("����","002");
            ui.print_input();
            cin >> option;
            if(option=="001"){
                //filesystem::remove(temp_resname);
                osm ocl(temp_resname);
                ocl<<"\0";
                osm o(temp_resname,ios_base::binary|ios_base::out);
                o.write((char*)&runtime,sizeof(runtime));
                o.close();
            }
            else if (option=="002"){
                return;
            }
            else{
                ui.print_tip("�������",1);
                //string a;
                _pause();
                ui.print_text("�밴���������...");
                //cin >> a;
                sce_error("RE",resname,runtime);
            }
        };
        if(type=="NF"){
            system(CLS);
            ui.print_tip("��������֧Ԯ���洢�ļ������ڣ�",1);
            ui.print_text("�����ļ��Ƿ���ڣ������Ƿ��ƶ���",2);
            ui.print_text("������ֶ�ɾ�����ļ���SCE���Զ��ؽ���",2,false);
            ui.print_text("[ע�⣺�˲���ʮ��Σ�գ���ᶪʧ�㱣���֧Ԯ�����ݣ������������]",1);
            ui.print_text("����������ء�",4);
            _pause();
            return;
        };
        if(type=="WE"){
            system(CLS);
            ui.print_tip("��������֧Ԯ���洢�ļ��޷�д�룡",1);
            ui.print_text("����Assets�ļ����Ƿ����");
            ui.print_text("����������ء�",4);
            _pause();
            return;
        }
    };
    
    int read_res(string resname,UmaSCE_Main &runtime){
        string temp_resname="../Assets/Data/User/"+resname+".UmaSCE_Data";
        ism i(temp_resname,ios_base::binary|ios_base::in);
        if(!i.is_open()){
            return 1;
        }
        i.read((char*)&runtime,sizeof(runtime));
        if(!i){
            sce_error("RE",resname,runtime);
            return 2;
        };
        i.close();
        return 0;
    };
    void write_res(string resname,UmaSCE_Main runtime){
        string temp_resname="../Assets/Data/User/"+resname+".UmaSCE_Data";
        osm o(temp_resname,ios_base::out|ios_base::binary);
        if(!o){
            sce_error("WE",resname,runtime);
        }
        o.write((char*)&runtime,sizeof(runtime));
        if(!o){
            sce_error("WE",resname,runtime);
        };
    }
private:
    UmaSCE_UI ui;
    void _pause(){
        #ifdef _WIN32
        system("pause > nul");
        #endif
        #ifdef __unix__
        system("read -n 1");
        #endif
    }

};
// model sideload
class model {
  public:
    bool check_model(string modelname){
        ifstream i(modelname);
        if(!i){
            ui.cls();
            ui.print_text("�� �������� ",1,0);
            ui.print_text(modelname+" ģ���ļ������ڣ� ��",1,1);
            return 1;
        };
        char temp_char;int line = 1; int column = 1; int column_important = 1;
        bool enter_line=0;string lltemp_word;string ltemp_word; string temp_word;
        string temp_line; bool at_catch=0;int found_error=0;int error_line=0;int error_column=0;
        string error_line_in;bool word_end=0;
        int at_import=0;int at_name=0;int at_by=0;int at_eof=0;
        string error_show;
        while(i.get(temp_char)){
            //cout << "Now at " << line << "," << column << ":" << temp_char << endl;
            if(temp_char=='\n'){
                enter_line=1;
                if(at_catch){
                    if(temp_word=="import"){
                        error_line=line;
                        error_column=column;
                        error_line_in=temp_line;
                        column_important=column+1;
                        at_catch=0;

                        detail_print(modelname,error_line,error_column+2,column_important,error_line_in,"E","��Ч����");
                        ui.print_text("UmaSCE_Build ECheckPoint:0x0001",4,1);
                    }
                    else if(temp_word=="name"){
                        error_line=line;
                        error_column=column;
                        error_line_in=temp_line;
                        column_important=column+1;
                        at_catch=0;
                        detail_print(modelname,error_line,error_column+2,column_important,error_line_in,"E","δ�ҵ���Ч�ַ���");
                        ui.print_text("UmaSCE_Build ECheckPoint:0x0002",4,1);

                    }
                    else if(temp_word=="by"){
                        error_line=line;
                        error_column=column;
                        error_line_in=temp_line;
                        column_important=column+1;
                        at_catch=0;
                        detail_print(modelname,error_line,error_column+2,column_important,error_line_in,"E","δ�ҵ���Ч�ַ���");
                        ui.print_text("UmaSCE_Build ECheckPoint:0x0003",4,1);

                    }
                    else if(temp_word=="eof"){
                        return 0;
                    }
                    else
                    {
                        //error_line_in=temp_line;
                        //at_catch=0;
                        //detail_print(modelname,error_line,error_column,column_important,error_line_in,"E","δ�ҵ���Ч�ַ���");
                        error_line=line;
                        error_column=column;
                        error_line_in=temp_line;
                        at_catch=0;
                        detail_print(modelname,error_line,error_column+2,column+1,error_line_in,"E","δ�ҵ���Ч�ַ���");
                        ui.print_text("UmaSCE_Build ECheckPoint:0x0004",4,1);
                        at_import=0;
                    }
                    
                }
                if(at_import && found_error){
                    at_import=0;
                    found_error=1;
                    error_line=line;
                    error_show="̫��Ĳ�����ֻ����һ�������������ҵ�������";
                } else if(at_import && !found_error){
                    if(temp_word!="base_val"){
                        column_important=column_important+1;
                        error_column=column;
                        error_line=line;
                        error_line_in=temp_line;
                        error_show="δ�ҵ���ģ��";
                        found_error=1;
                        at_import=0;
                    }
                    else{
                        at_import=0;
                    }
                }
            }
            if(temp_char==' '){
                word_end=1;
                if(at_catch){
                    if(temp_word!="import" && temp_word!="name" && temp_word!="by" && temp_word!="eof")
                    {
                        found_error=1;
                        error_column=column-1;
                        at_catch=0;
                        error_line=line;
                        error_column=column;
                    }else if(temp_word=="import")
                    {
                        at_import=1;
                        at_catch=0;
                        column_important=column+1;

                    }
                    else if(temp_word=="name")
                    {
                        at_name=1;
                        at_catch=0;
                        column_important=column+1;

                    }
                    else if(temp_word=="by")
                    {
                        at_by=1;
                        at_catch=0;
                        column_important=column+1;

                    }
                    else if(temp_word=="eof")
                    {
                        at_eof=1;
                        at_catch=0;
                        column_important=column+1;

                    }
                }
                if(at_import){
                    column_important=column;
                }
            }
            if(temp_char=='@'&& !at_catch){
                at_catch=1;
                column_important=column;
            }

            if(found_error && temp_char=='\n'){
                if(error_show=="")
                {
                    error_line_in=temp_line;
                    detail_print(modelname,error_line,error_column,column_important,error_line_in,"E","��Ч����");
                    found_error=0;
                    ui.print_text("UmaSCE_Build ECheckPoint:0x0005",4,1);

                }
                else {
                    error_line_in=temp_line;
                    detail_print(modelname,error_line,error_column,column_important,error_line_in,"E",error_show);
                    found_error=0; 
                    ui.print_text("UmaSCE_Build ECheckPoint:0x0006",4,1);
                    error_show="";
                }
            };
            if(enter_line){
                enter_line=0;
                line++;
                column=0;
                temp_line="";
                temp_word="";
                ltemp_word="";
                lltemp_word="";
            }
            else{
                temp_line+=string(1,temp_char);
            }
            if(word_end){
                lltemp_word=ltemp_word;
                ltemp_word=temp_word;
                temp_word="";
                word_end=0;
            }
            else if(temp_char!='@'&& temp_char!='\n'){
                temp_word+=string(1,temp_char);
            }
            column++;
        }
    };
    void load_base(string name){
        if(name=="base_val"){
            //�����û�����ֵ
        }
    }
  private:
    UmaSCE_UI ui;
    void _pause(){
      #ifdef _WIN32
      system("pause > nul");
      #endif
      #ifdef __unix__
      system("read -n 1");
      #endif
    }
    void detail_print(string modelname, int line, int column,int column_important,string line_in,string errortype,string show)
    {
        int x_show=0;
        if(errortype=="E"){
            ui.print_text("�� �ڼ���ģ��"+modelname+"ʱ��������",1,0);
            ui.print_text(show+" ��",1,1);
            ui.print_text("������ܷ�����"+modelname+":("+to_string(line)+","+to_string(column_important)+")",4,1);
        }

        string line_temp=to_string(line);
        size_t line_form=line_temp.length();

        while(x_show<4-line_form){
          ui.print_text(" ",1,0);
          x_show++;
        }
        ui.print_text(to_string(line),6,0);
        ui.print_text("| ",5,0);
        //char temp_char_a;



        ui.print_text(line_in,4,1);
        //ui.print_retrack(4);
        ui.print_text("    ",4,0);
        ui.print_text("| ",5,0);
        x_show=1;
        int e_line_length=(column)-column_important;
        while(x_show<column_important){
          ui.print_text(" ",1,0);
          x_show++;
        };
        x_show=0;
        while(x_show<e_line_length){
          ui.print_text("^",3,0);
          x_show++;
        };
        ui.print_text(" ",1,1);
        x_show=1;
        //ui.print_retrack(4);
        ui.print_text("    ",4,0);
        ui.print_text("| ",5,0);
        while(x_show<column_important){
          ui.print_text(" ",1,0);
          x_show++;
        };
        ui.print_text("(here)",2,1);
        ui.print_text("<�ȴ������������>",4);
    }
  

};
//���ö�д
class setting_rw {
public:
    void sce_error(string type,SCE_Setting_Struct runtime){
        if(type=="RE"){
            string option;
            system(CLS);
            ui.print_tip("��������SCE�����ļ���ȡʧ�ܣ�",1);
            ui.print_option("�������ɸ��ļ��������ļ�����","001",0,3,4,false,(char)32);
            ui.print_text("(��ѡ�������������ã������ѡ��)",2);
            ui.print_option("����","002");
            ui.print_input();
            cin >> option;
            if(option=="001"){
                if(!filesystem::is_directory("../Assets/Config/")){
                    filesystem::create_directory("../Assets/Config/");
                }
                
                //filesystem::remove(temp_resname);
                osm ocl("../Assets/Config/Setting.UmaSCE_Conf");
                ocl<<"\0";
                osm o("../Assets/Config/Setting.UmaSCE_Conf",ios_base::binary|ios_base::out);

                o.write((char*)&runtime,sizeof(runtime));
                o.close();
            }
            else if (option=="002"){
                return;
            }
            else{
                ui.print_tip("�������",1);
                //string a;
                _pause();
                ui.print_text("�밴���������...");
                //cin >> a;
                sce_error("RE",runtime);
            }
        };
        if(type=="NF"){
            system(CLS);
            ui.print_tip("��������SCE�����ļ������ڣ�",1);
            ui.print_text("�����ļ��Ƿ���ڣ������Ƿ��ƶ���",2);
            ui.print_text("������ֶ�ɾ�����ļ���SCE���Զ��ؽ���",2,false);
            ui.print_text("[ע�⣺�˲���ʮ��Σ�գ���ᶪʧ�㱣���֧Ԯ�����ݣ������������]",1);
            ui.print_text("����������ء�",4);
            _pause();
            return;
        };
        if(type=="WE"){
            system(CLS);
            ui.print_tip("��������SCE�����ļ��޷�д�룡",1);
            ui.print_text("����Assets�ļ����Ƿ����");
            ui.print_text("����������ء�",4);
            _pause();
            return;
        }
    };
    void write_setting(SCE_Setting_Struct runtime){
        if(!filesystem::is_directory("../Assets/Config/")){
            filesystem::create_directory("../Assets/Config/");
        };

        osm o("../Assets/Config/Setting.UmaSCE_Conf",ios_base::out|ios_base::binary);
        if(!o){
            sce_error("WE",runtime);
            return;
        }
        o.write((char*)&runtime,sizeof(runtime));
        if(!o){
            sce_error("WE",runtime);
        };
    };
    void read_setting(SCE_Setting_Struct &runtime){
        ism i("../Assets/Config/Setting.UmaSCE_Conf",ios_base::in|ios_base::binary);
        i.read((char*)&runtime,sizeof(runtime));
        if(!i){
            sce_error("RE",runtime);
        }
    }

private:
    UmaSCE_UI ui;
    void _pause(){
        #ifdef _WIN32
        system("pause > nul");
        #endif
        #ifdef __unix__
        system("read -n 1");
        #endif
    }
};
struct modlist
{
	map <string, int> modindex_x;
	map <string, int> modindex_y;
}modlist{};
json modlist_json;
map <int, string> modname;

class debug :public UmaSCE_Main {
protected:
    void create_modlist() {
        //����modΨһid
        modlist_json["SCEsh"] = {
            {"x",0},
            {"y",0}
		}; modname[0] = "SCEsh";
		//�����Ϸ���ʽ���mod
		//����modidע��
		modname[1] = "end";
        //modע��
        int x = 0;
        for (x = 0; x < 999; x++) {
            if (modname[x] == "end") {
                return;
            };
            modlist.modindex_x[modname[x]] = modlist_json[modname[x]]["x"];
            modlist.modindex_y[modname[x]] = modlist_json[modname[x]]["y"];
        };
    };
	void modloader(string modname) {
        int x;
        int y;
        try
        {
			x = modlist.modindex_x[modname];
			y = modlist.modindex_y[modname];
        }
        catch (const std::exception&)
        {
            osm o("../assets/logs/log.log");
            o << "loadmod" << modname << "error!" << endl;
            o.close();
        };
		//mod����
        if (x == 0 && y == 0) {
            ;
        };
	};
private:
    //SCEshʵ��
    int is_firstload_SCEsh = 0; 
    bool is_root = 0;
    void SCEsh() {
        if (is_firstload_SCEsh == 0) {
            cout << "SCEshell [�汾 V5.0B8]\n(c) SCEshell����������Ȩ����\n";
            cout << "\033[33m���棺��Shellû���κ�input����������������ʹ�ã�\033["
                "0m\n";
            is_firstload_SCEsh = 1;
        };
        if (is_root == 0) {
            cout << "SCEsh / #";
		}
		else {
			cout << "SCEsh / $ ";
		};
    }
};


