#include "add_list.h"
#include <stdio.h>
#include <stdlib.h>
//通讯录目前总人数
int sumCount = 0;
//动态开辟的大小
int sizeOfAdd = 0;
void init(int size)
{
	sizeOfAdd = size;
	ppsn = NULL;
	ppsn = (struct Person *)malloc(size * sizeof(struct Person));
}
void clear() {
	free(ppsn);
	ppsn = (struct Person *)malloc(sizeOfAdd * sizeof(struct Person));
	if (ppsn == NULL) {
		printf("清空失败");
	}
}
void add_person(struct Person * ppsn)
{
	ppsn += sumCount;
	if (ppsn != NULL) {
		printf("Please Enter Name: ");
		scanf("%s", ppsn->name);
		printf("Please Enter Sex: ");
		scanf(" %c", &(ppsn->sex));
		printf("Please Enter Age: ");
		scanf(" %u", &(ppsn->age));
		printf("Please Enter Tel: ");
		scanf(" %s", ppsn->phoneNum);
		printf("Please Enter Addr: ");
		scanf(" %s", ppsn->address);
		ppsn->flag = 0;
		sumCount += 1;
	}
}
void del_person(struct Person * ppsn)
{
	char name[NAME];
	printf("请输入删除人的姓名\n");
	scanf("%s", name);
	if (ppsn == NULL) {
		return;
	}
	int count = sumCount;
	for (; ppsn != NULL&&count; count--, ppsn++) {
		if (strcmp(ppsn->name, name) == 0 && !(ppsn->flag)) {
			printf("已经删除 %s %c %d %s %s\n", ppsn->name, ppsn->sex, ppsn->age, ppsn->phoneNum, ppsn->address);
			ppsn->flag = 1;
			return;
		}
	}

}
void show_all(struct Person * ppsn)
{
	int count = sumCount;
	while (ppsn != NULL && count--) {
		if (!(ppsn->flag))
			printf("%s %c %d %s %s\n", ppsn->name, ppsn->sex, ppsn->age, ppsn->phoneNum, ppsn->address);
		ppsn++;
	}
}

int cmp(const void *a, const void *b) {
	struct Person *pa = (struct Person *)a;
	struct Person *pb = (struct Person *)b;
	return strcmp(pa->name, pb->name);
}
void sort_by_name(struct Person * ppsn) {
	if (ppsn == NULL) {
		return;
	}
	qsort(ppsn, sumCount, sizeof(struct Person), cmp);
}
void find_person(struct Person * ppsn) {
	char name[NAME];
	printf("请输入删除人的姓名\n");
	scanf("%s", name);
	if (NULL == name || ppsn == NULL) {
		return;
	}
	int count = sumCount;
	for (; ppsn != NULL && count; count--, ppsn++) {
		if (strcmp(ppsn->name, name) == 0 && !(ppsn->flag)) {
			printf("%s %c %d %s %s\n", ppsn->name, ppsn->sex, ppsn->age, ppsn->phoneNum, ppsn->address);
			return;
		}
	}
	printf("没有找到\n");
}

void update(struct Person * ppsn) {
	char name[NAME];
	printf("请输入删除人的姓名\n");
	scanf("%s", name);
	if (NULL == name || ppsn == NULL) {
		return;
	}
	int count = sumCount;
	for (; ppsn != NULL && count; count--, ppsn++) {
		if (strcmp(ppsn->name, name) == 0 && !(ppsn->flag)) {
			printf("找到联系人，请依次输入姓名 性别 年龄 电话 地址，中间用空格隔开\n");
			scanf("%s %c %d %s %s", ppsn->name, &ppsn->sex, &ppsn->age, ppsn->phoneNum, ppsn->address);
			return;
		}
	}
	printf("没有找到\n");
}
