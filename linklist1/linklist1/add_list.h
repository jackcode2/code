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
	char flag;   //��ǣ�=1��ʾ�˱�ɾ��
}*ppsn;
void add_person(struct Person * ppsn);   //����һ����
void del_person(struct Person * ppsn);   //ɾ��ָ����
void find_person(struct Person * ppsn);     //Ѱ��ָ����
void update(struct Person * ppsn);      //��������Ϣ
void show_all(struct Person * ppsn);    //��ʾ������
void clear();                       //���������
void sort_by_name(struct Person * ppsn);    //��������
void init(int size);        //��ʼ��
