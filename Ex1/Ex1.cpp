// Ex1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<assert.h>
#include<locale>
#include<iostream>
#include <cstdio>

typedef int status;
typedef char ElemType1;
typedef int ElemType2;

typedef struct StackNode{
	ElemType1 data;	//数据域
	struct StackNode* next;	//指针域
}StackNode, * LinkList;

typedef struct StackNode2 {
	ElemType2 data;	//数据域
	struct StackNode2* next;	//指针域
}StackNode2, * LinkList2;

status InitStack(LinkList& S) {
	S = (StackNode*)malloc(sizeof(StackNode));
	if (S == NULL) exit(0);
	S->next = NULL;
	return 1;
}

status InitStack2(LinkList2& S) {
	S = (StackNode2*)malloc(sizeof(StackNode2));
	if (S == NULL) exit(0);
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

int GetStackLength(LinkList S)    //获取栈元素个数
{
	StackNode* p = S;
	int i = 0;
	while (p->next){
		i++;
		p = p->next;
	}
	return i;
}

int GetStackLength2(LinkList2 S)    //获取栈元素个数
{
	StackNode2* p = S;
	int i = 0;
	while (p->next) {
		i++;
		p = p->next;
	}
	return i;
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

int setPriority(ElemType1 E)    //比较优先级
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
	case '(':
		i = 2;
		break;
	case ')':
		i = 3;
		break;
	case '@':
		i = 4;
		break;
	default:
		break;
	}
	return i;
}

char comparePriority(ElemType1 E1, ElemType1 E2)    //比较优先级
{
	if (setPriority(E1) == 4 && setPriority(E2) == 5)return '=';
	if (setPriority(E1) == 3 && setPriority(E2) == 2)return '0';
	if (setPriority(E1) == 2 && setPriority(E2) == 4)return '0';
	if (setPriority(E1) == 4 && setPriority(E2) == 3)return '0';
	if (setPriority(E1) == 4)return '<';
	if (setPriority(E1) == setPriority(E2)==2)return '<';
	if (setPriority(E1) == setPriority(E2))return '>';
	if (setPriority(E1) > setPriority(E2))return '>';
	if (setPriority(E1) < setPriority(E2))return '<';
	return '0';
}

int calc(char* str) {
	int result=0;
	LinkList optr;
	LinkList2 opnd;
	InitStack(optr);
	InitStack2(opnd);
	push(optr, '@');
	int i = 0;
	int j = 0;
	char exp1[100];
	//do something
	return result;
}

int main(int argc, char** argv){
	char expression[100];
	int result;
	if (argc < 2) {
		printf("请输入算术表达式：");
		gets_s(expression);
	}
	result = calc(expression);
	printf("\n后缀表达式为：%d", result);
	printf("\n所求结果为：%d", result);
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
