
#include "add_list.h"
#include <stdio.h>
void menu() {
	printf("**************************************\n");
	printf("********1.�����ϵ����Ϣ *************\n");
	printf("********2.ɾ����ϵ����Ϣ *************\n");
	printf("********3.������ϵ����Ϣ *************\n");
	printf("********4.�޸���ϵ����Ϣ *************\n");
	printf("********5.��ʾ����ָ����ϵ����Ϣ******\n");
	printf("********6.�������ָ����ϵ����Ϣ******\n");
	printf("********7.��������������ϵ��**********\n");
	printf("********0.�˳�************************\n");
	printf("**************************************\n");
}

int main()
{

	printf("��ѡ�����봴����ͨѶ¼��С\n");
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
