#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//菜单展示界面
void Showmenu(){
    cout<<"**********************"<<endl;
    cout<<"*****1.添加联系人*****"<<endl;
    cout<<"*****2.显示联系人*****"<<endl;
    cout<<"*****3.删除联系人*****"<<endl;
    cout<<"*****4.查找联系人*****"<<endl;
    cout<<"*****5.修改联系人*****"<<endl;
    cout<<"*****6.清空联系人*****"<<endl;
    cout<<"*****0.退出通讯录*****"<<endl;
    cout<<"**********************"<<endl;
}

//联系人结构体创建
struct Person{
    string name;
    int sex;
    int age;
    string phone;
    string addr;
};
//通讯录结构体创建 
struct Addressbooks{
   Person person_arr[MAX];    
   int size=0;
}; 
//功能1的实现——添加联系人函数
void Addperson(Addressbooks *abs){
if(abs->size>=MAX){cout<<"通讯录已满";}
else{cout<<"姓名"<<endl;      cin>>abs->person_arr[abs->size].name; 
//性别的录入   运用if保证规范
    while(1){ cout<<"性别"<<endl<<"1——男"<<"2——女"<<endl;  cin>>abs->person_arr[abs->size].sex;  if(abs->person_arr[abs->size].sex==1||abs->person_arr[abs->size].sex==2){break;}}   
cout<<"年龄"<<endl;         cin>>abs->person_arr[abs->size].age;
cout<<"电话"<<endl;            cin>>abs->person_arr[abs->size].phone;
cout<<"地址"<<endl;              cin>>abs->person_arr[abs->size].addr;//数组只有在初次声明时 []里可以不写索引 
abs->size++;
}}
//功能2的实现——查看联系人函数     
void Showperson(Addressbooks abs){ 
if(abs.size==0){cout<<"通讯录为空";}
else{ for(int i=0;i<abs.size;i++)
{cout<<"姓名"<<abs.person_arr[i].name<<'\t';
cout<<"性别"<<abs.person_arr[i].sex<<'\t';
cout<<"年龄"<<abs.person_arr[i].age<<'\t';
cout<<"电话"<<abs.person_arr[i].phone<<'\t';
cout<<"地址"<<abs.person_arr[i].addr<<endl;}
}
}
//功能3的实现——删除联系人函数
void Deleteperson(string &name,Addressbooks &abs){
if(abs.size==0) {cout<<"通讯录为空";return;}
cout<<"请输入你想删除的联系人的名字";
cin>>name;
for(int i=0;i<abs.size;i++){
if(name==abs.person_arr[i].name){
    for(int j=i;j<abs.size;j++){
   abs.person_arr[j].name=abs.person_arr[j+1].name;
   abs.person_arr[j].sex=abs.person_arr[j+1].sex;
   abs.person_arr[j].age=abs.person_arr[j+1].age;
   abs.person_arr[j].phone=abs.person_arr[j+1].phone;
   abs.person_arr[j].addr=abs.person_arr[j+1].addr;
     }abs.size--;cout<<"删除成功";
}
}}
//功能4的实现——查找联系人函数    
int Findperson(Addressbooks abs){
    if(abs.size==0) {cout<<"通讯录为空";return -1;}
    int ret=-1;string name;
cout<<"请输入你要查找的联系人";
cin>>name;
bool Find=1;
for(int i=0;i<abs.size;i++) {if(name==abs.person_arr[i].name){Find =0;}}
switch(Find){
case 0: {  for(int i=0;i<abs.size;i++) { 
if(name==abs.person_arr[i].name) 
{ret=i;
cout<<"姓名"<<abs.person_arr[i].name<<'\t';
cout<<"性别"<<abs.person_arr[i].sex<<'\t';
cout<<"年龄"<<abs.person_arr[i].age<<'\t';
cout<<"电话"<<abs.person_arr[i].phone<<'\t';
cout<<"地址"<<abs.person_arr[i].addr<<endl;
break;}
} break;} 
case 1: cout<<"未找到联系人";
}
return ret;   //返回查找的联系人所在位置
}
//功能5的实现——修改联系人函数     这一块有问题！
void Modifyperson(Addressbooks &abs){
    if(abs.size==0) {cout<<"通讯录为空"<<endl;return;}
    string name;
    cout<<"请输入要修改的联系人姓名: ";
    cin>>name;
    
    bool found = false;
    for(int i=0; i<abs.size; i++){
        if(name == abs.person_arr[i].name) {
            found = true;
            int temp;
            cout<<"请选择要修改"<<name<<"的什么信息:"<<endl;
            cout<<"1-姓名 2-性别 3-年龄 4-电话 5-地址: ";
            cin>>temp;
            
            switch(temp){
                case 1:
                    cout<<"修改为: ";
                    cin>>abs.person_arr[i].name; 
                    cout<<"修改成功"<<endl;
                    break;
                case 2:
                    cout<<"修改为: ";
                    while(1){
                        cin>>abs.person_arr[i].sex;  
                        if(abs.person_arr[i].sex==1 || abs.person_arr[i].sex==2){
                            break;
                        } else {
                            cout<<"输入有误，请重新输入(1-男 2-女): ";
                        }
                    } 
                    cout<<"修改成功"<<endl;
                    break; 
                case 3:
                    cout<<"修改为: ";
                    cin>>abs.person_arr[i].age;
                    cout<<"修改成功"<<endl;
                    break;
                case 4:
                    cout<<"修改为: ";
                    cin>>abs.person_arr[i].phone; 
                    cout<<"修改成功"<<endl;
                    break;
                case 5:
                    cout<<"修改为: ";
                    cin>>abs.person_arr[i].addr; 
                    cout<<"修改成功"<<endl;
                    break; 
                default:
                    cout<<"输入有误"<<endl;
                    break;
            }
            break;  // 修改完成后跳出循环
        }
    }
    
    if(!found){
        cout<<"未找到联系人: "<<name<<endl;
    }
}

//功能6的实现——清除通讯录  （覆盖思路 其实是伪清除）
void Cleanperson(Addressbooks &abs){
abs.size=0;
}
int  main(){ system("chcp 65001");
    int select;
   Addressbooks abs;
   abs.size=0;
   while(1){
   Showmenu();
   cin>>select;//问题  怎么防止用户输入其他select 比如字母啥的？
   
//根据用户选择呈现对应界面
   switch(select){
   //1添加
    case 1:Addperson(&abs);cout<<"添加成功"<<endl;system("pause");system("cls");break;
    //2显示
   case 2:{Showperson(abs);system("pause");system("cls");break;}
    //3删除
   case 3:{string name; Deleteperson(name,abs);system("pause");system("cls");break;}
   //4查找
   case 4:{Findperson(abs);system("pause");system("cls");break;}
   //5修改
   case 5:{Modifyperson(abs);system("pause");system("cls");break;}
   //6清空
   case 6:{Cleanperson(abs);cout<<"清除成功";system("pause");system("cls");break;}
   //0退出
   case 0: {cout<<"欢迎下次使用";system("pause");system("cls");return 0;break;}
   default:break;} 
   }
    return 0;
}