#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NAME 20
#define PHONE 20
#define ADDRESS 50
struct Person {
	char name[NAME];
	char sex;
	int age;
	char phoneNum[PHONE];
	char address[ADDRESS];
	char flag;   //标记，=1表示人被删除
}*ppsn;
void add_person(struct Person * ppsn);   //增加一个人
void del_person(struct Person * ppsn);   //删除指定人
void find_person(struct Person * ppsn);     //寻找指定人
void update(struct Person * ppsn);      //更新人信息
void show_all(struct Person * ppsn);    //显示所有人
void clear();                       //清空所有人
void sort_by_name(struct Person * ppsn);    //按名排序
void init(int size);        //初始化
