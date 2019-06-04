
#include "add_list.h"
#include <stdio.h>
void menu() {
	printf("**************************************\n");
	printf("********1.添加联系人信息 *************\n");
	printf("********2.删除联系人信息 *************\n");
	printf("********3.查找联系人信息 *************\n");
	printf("********4.修改联系人信息 *************\n");
	printf("********5.显示所有指定联系人信息******\n");
	printf("********6.清空所有指定联系人信息******\n");
	printf("********7.按名排序所有联系人**********\n");
	printf("********0.退出************************\n");
	printf("**************************************\n");
}

int main()
{

	printf("请选择你想创建的通讯录大小\n");
	int sizeOfAdd;
	scanf("%d", &sizeOfAdd);
	init(sizeOfAdd);
	int chose;
	do {
		menu();
		scanf("%d", &chose);
		switch (chose) {
		case 1:add_person(ppsn);
			break;
		case 2:del_person(ppsn);
			break;
		case 3:find_person(ppsn);
			break;
		case 4:update(ppsn);
			break;
		case 5:show_all(ppsn);
			break;
		case 6:clear(ppsn);
			break;
		case 7:sort_by_name(ppsn);
			break;
		default:break;

		}

	} while (chose);

	system("pause");
}
