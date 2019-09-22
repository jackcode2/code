#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>

#define up 'w'
#define dowm 's'
#define right 'd'
#define left 'a'
#define stop 'p'


void welcome();               //��ʼ����
void Finish();                //��������
void creatgraph();            //Χǽ��ӡ

void gotoxy(int x, int y);    //�����ת����ΪX 0,1,2..
void gotoprint(int x, int y); //��ת��ӡ
void gotodelete(int x, int y);//��תɾ��
void creatfood();             //ʳ�����
int ClickControl();           //��ȡ�����ź�
int Judge();                  //��Ϸ�����ж�
void MovingBody();      //�ߵ��ƶ� 
void Eating();                //�߳Ե�������Ĳ������쳤��
void ChangeBody(int a, int b); //�ߵ�����任,��һ������ǰһ��STRUCT,a,bΪhead֮ǰ���� 


typedef struct Snake{
	int x;
	int y;
	struct Snake *next;  //�ṹ��Ƕ��
}snake;

snake *head, *tail;

struct Food{
	int x;
	int y;
}food;


char name[20];  //�������
int score; //�÷�
char click; //
int speed;  //�ƶ��ٶ�



int main(){
	system("color 0B");
	welcome();
	creatgraph();
	creatfood();

	if (ClickControl() == 0) return 0;
	return 0;
}
void welcome(){
	gotoxy(15, 10);
	printf("****************************************");
	gotoxy(15, 20);
	printf("****************************************");
	gotoxy(20, 13);
	printf("Welcome To Eating Snakes!!");
	gotoxy(17, 16);
	printf("w a s d �ƶ���p��ͣ�������Է����ƶ� ");
	gotoxy(20, 18);
	printf("Please Inter Your Name:");
	scanf("%s", name);
	system("cls");
}
void gotoxy(int x, int y){
	COORD pos;  //windos�����һ�ֽṹ��   ��ʾһ���ַ�����Ļ�ϵ�����
	HANDLE hOutput; //���  һ�����Ķ�����ĳһ��������Ψһ����  ׼ȷ�ķ��ʶ���
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hOutput, pos);    //���þ��
}

void creatgraph()
{
	int i;
	for (i = 0; i < 58; i += 2){  //26 *26 �ķ�Χ  �ַ���ֱռ1���ֽ� ˮƽռ�����ֽ�
		gotoprint(i, 0);
		gotoprint(i, 26);
	}
	for (i = 1; i < 26; i++){
		gotoprint(0, i);
		gotoprint(56, i);
	}
	gotoxy(63, 10);
	printf("hello,%s,welcome to play", name);
	gotoxy(63, 15);
	printf("Your score is %d", score);
	gotoxy(63, 17);
	printf("Made by Huang_");

	head = (snake*)malloc(sizeof(snake));
	tail = (snake*)malloc(sizeof(snake));
	snake *p = (snake*)malloc(sizeof(snake));
	snake *q = (snake*)malloc(sizeof(snake));

	head->x = 16;   //x���������ż�� 
	head->y = 15;
	p->x = 16;
	p->y = 16;
	q->x = 16;
	q->y = 17;

	tail->x = 4;
	tail->y = 2;

	head->next = p;
	p->next = q;
	q->next = tail;
	tail->next = NULL;
}
void gotodelete(int x, int y){
	gotoxy(x, y);
	printf(" ");
}
void gotoprint(int x, int y)
{
	gotoxy(x, y);
	printf("��");
}
void creatfood()
{
	srand((int)time(NULL));
lable: //��ǩ
	food.y = rand() % (25 - 1 + 1) + 1;  //����a-b������� rand����%(b-a)+a
	food.x = rand() % (54 - 2 + 1) + 2;
	if (food.x % 2 != 0)
	{
		food.x = food.x + 1;
	}
	snake *judge = head;
	while (1)					//�����ų������ظ�!!!!!  ��ͷ��㿪ʼ���� һֱ��β�ڵ�  ��֤���������food�������ڲ�
	{
		if (judge->next == NULL) break;
		if (food.x == judge->x&&food.y == judge->y)
		{
			goto lable;  //���ر�ǩλ�� ��������food
		}
		judge = judge->next;
	}
	gotoxy(food.x, food.y);
	printf("��");
}
int ClickControl()
{
	while (1){
		if (Judge() == 0) return 0;
		if (_kbhit()){   //����Ƿ��м�������
			click = _getch();  //�Ӽ����϶�ȡ�����ַ�
		}
		MovingBody();
		Eating();
	}
	return 1;
}
void MovingBody()
{
	int count = 0;  //�����ٶ�
	int a = head->x;
	int b = head->y;
	snake *p = head;
	while (1){
		if (p->next == NULL)  break;
		gotodelete(p->x, p->y);
		count++;
		p = p->next;
	}
	switch (click)
	{
	case up:
		head->y -= 1;
		ChangeBody(a, b);
		break;
	case dowm:
		head->y += 1;
		ChangeBody(a, b);
		break;
	case left:
		head->x -= 2;
		ChangeBody(a, b);
		break;
	case right:
		head->x += 2;
		ChangeBody(a, b);
		break;
	case stop:
		_getch();  //��ͣ �ȴ��Ӽ����϶�ȡ���ַ�
		break;
	}
	p = head;
	while (1){
		if (p->next == NULL)  break;
		gotoprint(p->x, p->y);
		p = p->next;
	}
	p = head;
	gotoxy(0, 28);


	if (count <= 10) speed = 150;
	else if (count > 10 && count <= 20) speed = 100;
	else if (count > 20 && count <= 40) speed = 50;
	else speed = 10;
	Sleep(speed);
}
void Eating(){
	if (head->x == food.x && head->y == food.y){
		creatfood();
		snake *_new = (snake*)malloc(sizeof(snake));
		snake *p;
		p = head;
		while (1){
			if (p->next->next == NULL) break;
			p = p->next;
		}
		p->next = _new;
		_new->next = tail;
		score += 10;
		gotoxy(77, 15);
		printf("%d", score);
	}
}
void ChangeBody(int a, int b)
{
	snake *p = head->next;
	int mid1, mid2, _mid1, _mid2;
	mid1 = p->x;
	mid2 = p->y;
	while (1){
		if (p->next->next == NULL)  break;

		_mid1 = p->next->x;
		_mid2 = p->next->y;
		p->next->x = mid1;
		p->next->y = mid2;
		mid1 = _mid1;
		mid2 = _mid2;

		p = p->next;
	}
	p = head->next;
	p->x = a;
	p->y = b;

}
int Judge()  //�ж� ײǽʧ�� �� ͷ����β�ɹ�  
{
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26){
		Finish();
		return 0;
	}
	snake *p = head->next;
	while (1){
		if (p->next == NULL) break;
		if (head->x == p->x&&head->y == p->y){
			Finish();
			return 0;
		}
		p = p->next;
	}
	return 1;
}

void Finish()
{
	system("cls");
	gotoxy(15, 10);
	printf("/**********************************************/");
	gotoxy(15, 20);
	printf("/**********************************************/");
	gotoxy(18, 14);
	printf("GAME   OVER      o(*������*)o");
	gotoxy(20, 16);
	printf("Your Score is %d    hiahiahia", score);
	gotoxy(18, 18);
	printf("������Ŷ��     ����Ŭ��O(��_��)O");
	gotoxy(0, 27);
	system("pause");
}