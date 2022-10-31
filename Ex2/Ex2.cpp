// Ex2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void CLIOptions() {
	printf("本程序命令格式：\n-e <inputfilepath> <outputfilepath>     设置编码文件路径\n-d <inputfilepath> <outputfilepath>     设置解码文件路径");//程序命令格式说明
	exit(0);//触发本提示应为命令行or终端直接调用，故退出即可，无需等待
}

int main(int argc, char** argv) {
	char content[1000];
	int flag_m = 0;
	if (argc >= 3) {
		if (strcmp(argv[1], "-e") == 0 && argc >= 3) {//-e文件编码
			FILE* fp;
			fp = fopen(argv[2], "r");//传入输入文件名
			if (fp == NULL) {
				printf("文件读取失败");
				exit(0);
			}
			else {
				fgets(content, 1000, fp);//读入
				printf("传入内容为：%s", content);
			}
			fclose(fp);
			flag_m = 1;
		}
		else if (strcmp(argv[1], "-o") == 0 && argc >= 3) {//-d文件解码
			FILE* fp;
			fp = fopen(argv[2], "r");//传入输入文件名
			if (fp == NULL) {
				printf("文件读取失败");
				exit(0);
			}
			else {
				fgets(content, 1000, fp);//读入
				printf("传入内容为：%s", content);
			}
			fclose(fp);
			flag_m = 2;
		}
		else {
			CLIOptions();//参数错误，输出命令行使用说明
		}
	}
	else {
		CLIOptions();//参数错误，输出命令行使用说明
	}
	return 0;
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
