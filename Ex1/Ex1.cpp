// Ex1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<assert.h>
#include<locale>
#include<iostream>
#include <cstdio>

typedef int status;
typedef char ElemType1;
typedef double ElemType2;

typedef struct StackNode {
	ElemType1 data;	//数据域
	struct StackNode* next;	//指针域
}StackNode, * LinkList;

typedef struct StackNode2 {
	ElemType2 data;	//数据域
	struct StackNode2* next;	//指针域
}StackNode2, * LinkList2;

status InitStack(LinkList& S) {
	S = (StackNode*)malloc(sizeof(StackNode));	//分配
	if (S == NULL) exit(0);	//分配出错
	S->next = NULL;
	return 1;
}

status InitStack2(LinkList2& S) {
	S = (StackNode2*)malloc(sizeof(StackNode2));	//分配
	if (S == NULL) exit(0);	//分配出错
	S->next = NULL;
	return 1;
}

status GetTopElem(LinkList& S, ElemType1& E)    //获取栈顶元素
{
	if (S->next == NULL) return 0;
	E = S->next->data;
	return 1;
}

status GetTopElem2(LinkList2& S, ElemType2& E)    //获取栈顶元素
{
	if (S->next == NULL) return 0;
	E = S->next->data;
	return 1;
}

status push(LinkList& S, ElemType1 E)	//进栈
{
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL) exit(0);
	p->data = E;
	p->next = S->next;
	S->next = p;
	return 1;
}

status pop(LinkList& S, ElemType1& E)	//出栈
{
	if (S->next == NULL) return 0;
	E = S->next->data;
	StackNode* p = S->next;
	S->next = p->next;	//修改栈顶指针
	free(p);
	return 1;
}

status push2(LinkList2& S, ElemType2 E)	//进栈
{
	StackNode2* p = (StackNode2*)malloc(sizeof(StackNode2));
	if (p == NULL) exit(0);
	p->data = E;
	p->next = S->next;
	S->next = p;
	return 1;
}

status pop2(LinkList2& S, ElemType2& E)	//出栈
{
	if (S->next == NULL) return 0;
	E = S->next->data;
	StackNode2* p = S->next;
	S->next = p->next;	//修改栈顶指针
	free(p);
	return 1;
}

int setPriority(ElemType1 E)    //设置优先级
{
	int i;
	switch (E)
	{
	case '+':
		i = 0;
		break;
	case '-':
		i = 0;
		break;
	case '*':
		i = 1;
		break;
	case '/':
		i = 1;
		break;
	case '^':
		i = 2;
		break;
	case '(':
		i = 3;
		break;
	case ')':
		i = 4;
		break;
	case '=':
		i = 5;
		break;
	default:
		i = -1;
		break;
	}
	return i;
}

char compPriority(ElemType1 E1, ElemType1 E2)    //比较优先级
{
	int i = setPriority(E1), j = setPriority(E2);//获取优先级数值
	if ((i == 5) && (j == 5))return '=';
	if ((i == 4) && (j == 3))return '0';
	if ((i == 3) && (j == 4))return '=';
	if ((i == 3) && (j == 5))return '0';
	if ((i == 5) && (j == 4))return '0';
	if (i == 3)return '<';
	if (j == 3)return '<';
	if (i == 4)return '>';
	if (j == 4)return '>';
	if (i == 5)return '<';
	if (j == 5)return '>';
	if ((i == j) && (j == 3))return '<';
	if (i == j)return '>';
	if (i > j)return '>';
	if (i < j)return '<';
	return '0';
}

double _atod(char* str, int leng) //传入字符及长度，转换为double返回
{
	int i=0;
	char str1[100];
	assert(str != NULL);
	for (; i < leng; i++)
	{
		str1[i]=str[i];//转录
	}
	double data = strtod(str1, NULL);//字符串str1类型转换double
	return data;
}

ElemType2 Optr(ElemType2 a, char optr, ElemType2 b) {
	ElemType2 result;
	switch (optr) {//进行指定操作
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break; 
	case '^':
		result = (ElemType2)pow(a,b);
		break;
	default:
		break;
	}
	return result;
}

double calc(char* str) {
	double result = 0;
	LinkList optr;
	LinkList2 opnd;
	InitStack(optr);
	InitStack2(opnd);
	push(optr, '=');
	int i = 0, j = 0;
	bool flag = 0;
	bool flag_a = 0;//首次输出
	bool flag_b = 0;//记录上一步操作
	int flag_c = 1;//实现#操作
	ElemType1 r, s;
	ElemType2 a, b, data;
	char t;
	GetTopElem(optr, r);
	char exp1[100];
	while (str[i] != '=' || r != '=') {
		if ((str[i] >= '0' && str[i] <= '9')||str[i]=='#') {//操作数
			if (str[i] == '#') {
				i++;
				flag_c = -1;
			}
			exp1[j] = str[i];
			i++;
			j++;
			if (str[i] < '0' || str[i] > '9') {//非数值
				if (str[i] != '.') {//非小数点则说明结束
					flag = 1;
				}
				else {
					exp1[j] = str[i];
					i++;
					j++;
				}
			}
			if (flag == 1 && j > 0) {
				data = _atod(exp1, j);
				data *= flag_c;
				flag_c = 1;
				push2(opnd, data);
				flag_b = 0;
				flag = 0;
				j = 0;
			}
		}
		else {//非操作数
			if ((str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '=' && str[i] != '^' && str[i] != '(' && str[i] != ')')||(str[i]=='('&&(str[i-1] >= '0' && str[i-1] <= '9'))) {
				printf("输入表达式有误，程序即将退出！");
				Sleep(1000);
				exit(0);
			}
			
			GetTopElem(optr, r);
			t = compPriority(r, str[i]);
			switch (t) {
			case '<':
				push(optr, str[i]);
				i++;
				break;
			case '>':
				pop(optr, s);//操作符出栈
				pop2(opnd, b);//2操作数出栈
				pop2(opnd, a);
				if (flag_a == 0) {//首次输出时两操作数均为原始数据，输出
					printf("%lf %lf %c ", a, b, s);
					flag_a = 1;
				}else {
					if (flag_b == 1) {
						printf("%lf %c ", a, s);
					}else {
						printf("%lf %c ", b, s);
					}

				}
				push2(opnd, Optr(a, s, b));//存入运算结果
				flag_b = 1;
				break;
			case '=':
				pop(optr, s);
				i++;
				break;
			default:
				break;
			}
		}
		GetTopElem(optr, r);
	}
	GetTopElem2(opnd, result);
	return result;
}

void CLIOptions() {
	printf("本程序命令格式：\n-f <filepath>                   设置读入文件路径\n-e <expression>                 直接传入表达式");//程序命令格式说明
	exit(0);//触发本提示应为命令行or终端直接调用，故退出即可，无需等待
}

int main(int argc, char** argv) {
	char expression[100];
	int n, p, flag=0;
	double result;
	while (1) {
		if (flag == 1) {
			argc = 1;
		}
		if (argc < 2) {
			printf("\n请输入算术表达式（输入exit退出）：");
			gets_s(expression);
		}
		else {
			if (strcmp(argv[1], "-f") == 0 && argc >= 3) {//-f文件读入
				FILE* fp;
				fp = fopen(argv[2], "r");//参数二文件
				if (fp == NULL) {
					printf("文件读取失败");
					exit(0);
				}
				else {
					fgets(expression, 100, fp);//读入表达式
					printf("传入表达式为：%s", expression);
				}
				fclose(fp);
			}
			else if (strcmp(argv[1], "-e") == 0 && argc >= 3) {//-e直接传入表达式
				strcpy_s(expression, argv[2]);
				printf("传入表达式为：%s", expression);
			}
			else {
				CLIOptions();//参数错误，输出命令行使用说明
			}
			flag = 1;
		}
		if (strcmp(expression, "exit\0") == 0) break;//exit退出
		for (n = 0; n < 100 && expression[n] != '\0'; n++) {}
		if (expression[0] == '-') {//负号补零
			for (p = n; p >= 0; p--) {
				expression[p + 1] = expression[p];
			}
			expression[0] = '0';
			n++;
		}
		if (expression[n - 1] != '=') {//末尾补充等号
			if ((expression[n - 1] >= '0' && expression[n - 1] <= '9' )|| expression[n - 1]==')') {//末尾为数字，补等号结尾
				expression[n] = '=';//补充末尾等号
				expression[n + 1] = '\0';//表达式结束符
			}else {//末尾为算符，表达式非法
				printf("\n表达式非法！\n");
				printf("\n表达式非法！\n");
				printf("\n表达式非法！\n");
				continue;//下一次循环
			}
		}
		printf("\n后缀表达式为：");//表达式在calc()中输出
		result = calc(expression);
		printf("\n所求结果为：%lf", result);
		if (argc >= 4) {
			if (strcmp(argv[3], "-m") == 0) {//从MFC外壳调用模式，输出结果后停留退出
				Sleep(1000);
				break;
			}
		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
