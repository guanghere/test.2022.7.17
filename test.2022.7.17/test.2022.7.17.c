#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//写一个猜数字游戏
// 1 . 产生1到100之间的随机值
// 2 . 猜数字
// （1） . 猜对了，游戏结束
// （2） . 猜错了，会提醒大了还是小了，再继续猜，直到正确
// 3 . 自行选择退出

// 1 先写一个主函数
// 2 采用do while 循环  先执行（玩）后判断（选择是否结束）
// 3 先打印一个菜单			menu（打印菜单）自定义函数 
//



void menu()
{
	printf(" ***********************************\n");
	printf(" *********  1 . play    ************\n");
	printf(" *********  0 . over    ************\n");
	printf(" ***********************************\n");
}

void game()		//猜数字游戏的主体
{				//生成随机数 再猜数字
				//rand 库函数 作用是生成随机值
	 //设置一个随机的起点
			    //括号里面写多少都是固定的“随机值”
				//想生成随机值 需要srand生成随机值才可以让rand生成随机值
				// 了解时间戳（时间钟）		时间戳就是时间转换的一个随机数字  时间点
				//time	库函数就是时间戳
				//time会返回一个时间戳	返回的时间戳是调用这个函数的时间点和计算机的启始时间时间的时间戳
				//time

	int ret = rand() % 100 + 1;	//%100的余数是0到99，然后+1，得到的就是1到100

	//printf("%d\n", ret);//生成的都是固定的“随机值”
						   //再调用rand函数之前还需要调用一个srand函数来设置这个随机值的生成器

		//猜数字
	int guess = 0;
	while (1)	//死循环的猜
	{
		printf("请猜数字!\n");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了！\n");
		}
		else if (guess > ret)
		{
			printf("猜大了!\n");
		}
		else
		{
			printf("猜对了！");
			break;
		}
	}

}

int main()
{

	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();	//打印菜单
		printf("请选择!\n");
		scanf("%d",&input);
		switch (input)	//判断输入的是什么
		{
		case 1:
			game();	//封装一个game函数
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:		//default只有在case匹配失败的时候才会执行
			printf("选择错误，重新选择!\n");
			break;
		}
		//switch 语句的break结束后 跳到这里！
		// do while循环的执行阶段已经结束	下面的是判断部分
		//	如果判断input里面为真（非零）那么就继续
		//	如果判断input里面为假（为零）那么就结束
		//	如果判断input里面既不为真也不为假 那么就default 重新选择
	}while(input);

	return 0;
}