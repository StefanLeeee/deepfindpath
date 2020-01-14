// 深度寻路.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyStack.h"
#include <stdlib.h>
//地图行数 Y
#define ROW  10
//地图列数 X
#define COL  10
//速度
#define SPEED 100

struct MyPoint{
	int row;
	int col;
};

//表示方向的枚举
enum MyDir{p_up,p_down,p_left,p_right};

struct MyPath{
	int		val;	//障碍or路
	MyDir	dir;	//方向
	bool	isFind;	//true:走过 false:没有走过
};


void drawMap(int map[ROW][COL], MyPoint point){
	system("cls");//清屏

	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (map[i][j] == 1){//墙
				printf("墙");
			}
			else if (point.row == i && point.col == j){//人
				printf("人");
			}
			else{//路
				printf("  ");
			}
		}
		printf("\n");
	}
	_sleep(SPEED);
}



int _tmain(int argc, _TCHAR* argv[])
{

#if 0
	MyStack<int> stack;
	for (int i = 0; i < 10; i++){
		stack.push(i);
	}

	while (stack.isStackEmpty() == false){
		printf("%d\n", stack.getStackTop());
		stack.pop();
	}
	printf("over!\n");

#else

	//地图 0:路 1:障碍
	int map[ROW][COL] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	//辅助地图
	MyPath pathMap[ROW][COL] = { 0 };//方向都是p_up isFind都是false
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			pathMap[i][j].val = map[i][j];
		}
	}

	MyPoint begPos = { 1, 1 };
	MyPoint endPos = { 8, 8 };
	MyStack<MyPoint> stack;
	stack.push(begPos);

	MyPoint searchPos = begPos;
	MyPoint currentPos;

	while (1){
		currentPos = searchPos;

		switch (pathMap[searchPos.row][searchPos.col].dir)
		{
		case p_up:
			currentPos.row--;
			//方向改变
			pathMap[searchPos.row][searchPos.col].dir = p_down;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//可以走
				
				//记录走过
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//入栈
				stack.push(currentPos);
				//走
				searchPos = currentPos;
			}
			break;
		case p_down:
			currentPos.row++;
			//方向改变
			pathMap[searchPos.row][searchPos.col].dir = p_left;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//可以走

				//记录走过
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//入栈
				stack.push(currentPos);
				//走
				searchPos = currentPos;
			}
			break;
		case p_left:
			currentPos.col--;
			//方向改变
			pathMap[searchPos.row][searchPos.col].dir = p_right;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//可以走

				//记录走过
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//入栈
				stack.push(currentPos);
				//走
				searchPos = currentPos;
			}
			break;
		case p_right:
			currentPos.col++;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//可以走

				//记录走过
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//入栈
				stack.push(currentPos);
				//走
				searchPos = currentPos;
			}
			else{//已经到了死胡同
				//删除栈顶元素
				stack.pop();
				//当前位置变成栈顶
				searchPos = stack.getStackTop();
			}
			break;
		
		}

		if (searchPos.row == endPos.row &&
			searchPos.col == endPos.col){//遇到终点
			printf("找到终点啦!\n");
			break;
		}

		if (stack.isStackEmpty()){//回到原点
			printf("这个迷宫没有出口!\n");
			break;
		}

		drawMap(map, searchPos);



	}

	//打印路径
	while (!stack.isStackEmpty()){//从栈顶到栈底打印
		currentPos = stack.getStackTop();
		printf("(%d,%d) ", currentPos.row, currentPos.col);
		stack.pop();
	}
	printf("\n");

#endif


	while (1);
	return 0;
}

