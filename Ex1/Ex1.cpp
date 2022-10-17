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
typedef char ElemType;

typedef struct Node{
	ElemType data;	//数据域
	struct Node* next;	//指针域
}Node, * LinkList;

status  InitStack(LinkList *S) {
	*S = (Node*)malloc(sizeof(Node));
	if (*S == NULL) exit(0);
	(* S)->next = NULL;
	return 1;
}

int calc(char* str) {
	int result;
	//do something
	return result;
}

int main(int argc, char** argv){
	char expression[100];
	int result;
	printf("请输入算术表达式：");
	gets_s(expression);
	result = calc(expression);
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
