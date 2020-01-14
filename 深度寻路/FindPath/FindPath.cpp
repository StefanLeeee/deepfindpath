// FindPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyStack.h"

#define MAP_LENGTH 12


enum Path_Dir{
	p_up,		//上 0
	p_down,		//下 1
	p_left,		//左 2
	p_right		//右 3
};
struct MyPoint{//坐标点的结构体
	int row;		//纵向坐标	y
	int col;		//横向坐标	x
};


struct PathNode{//寻路地图辅助信息
	int val;		//值 是否可通行  0 还是 1
	Path_Dir dir;	//方向
	bool isFind;	//是否走过了
};

int _tmain(int argc, _TCHAR* argv[])
{	/*	int map[MAP_LENGTH][MAP_LENGTH] = {			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },			{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },			{ 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 },			{ 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },			{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },			{ 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1 },			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }	};*/
	//辅助信息的地图 记录寻路过程	PathNode pathMap[MAP_LENGTH][MAP_LENGTH];	//初始化辅助信息的地图	for (size_t i = 0; i < MAP_LENGTH; i++){		for (size_t j = 0; j < MAP_LENGTH; j++)		{			pathMap[i][j].val = map[i][j];//值和map的值相同			pathMap[i][j].isFind = false;//一开始都没有走过			pathMap[i][j].dir = p_up;//一开始都是往上走 寻路方向规则:上,下,左,右  加法		}	}
	MyPoint beginPos = { 1, 1 };	//起点	MyPoint endPos = { 10, 10 };	//终点

	CMyStack<MyPoint> stack;
	stack.push(beginPos);

	MyPoint nextPos = stack.getTop();//保存下一个要走的点
	MyPoint tempPos;//临时点
	while (1){//死循环一直找
		tempPos = nextPos;//临时点是要下一步要走的点
		switch (pathMap[nextPos.row][nextPos.col].dir){//检查方向
		case p_up:
			tempPos.row--;
			if (pathMap[tempPos.row][tempPos.col].val = 0  &&	/*当前格可以走*/
				! pathMap[nextPos.row][nextPos.col].isFind){    /*下一格没有走过*/
				pathMap[nextPos.row][nextPos.col].dir = p_down;//方向改变了   方向改变的规则... 上 下 左 右
				pathMap[nextPos.row][nextPos.col].isFind = true;//记录已经走过了
				stack.push(tempPos);//存到栈里面去,回退需要
				nextPos = tempPos;//走动一步
			}
			else{//不可以走
				pathMap[nextPos.row][nextPos.col].dir = p_down;//方向改变
			}

			break;
		case p_down:
			tempPos.row++;
			if (pathMap[tempPos.row][tempPos.col].val = 0 &&	/*当前格可以走*/
				!pathMap[nextPos.row][nextPos.col].isFind){    /*下一格没有走过*/
				pathMap[nextPos.row][nextPos.col].dir = p_left;//方向改变了   方向改变的规则... 上 下 左 右
				pathMap[nextPos.row][nextPos.col].isFind = true;//记录已经走过了
				stack.push(tempPos);//存到栈里面去,回退需要
				nextPos = tempPos;//走动一步
			}
			else{//不可以走
				pathMap[nextPos.row][nextPos.col].dir = p_left;//方向改变
			}

			break;
		case p_left:
			tempPos.col--;
			pathMap[nextPos.row][nextPos.col].dir = p_right;//方向改变了   方向改变的规则... 上 下 左 右

			if (pathMap[tempPos.row][tempPos.col].val = 0 &&	/*当前格可以走*/
				!pathMap[nextPos.row][nextPos.col].isFind){    /*下一格没有走过*/
				pathMap[nextPos.row][nextPos.col].isFind = true;//记录已经走过了
				stack.push(tempPos);//存到栈里面去,回退需要
				nextPos = tempPos;//走动一步
			}
		
			break;
		case p_right:
			tempPos.col++;

			if (pathMap[tempPos.row][tempPos.col].val = 0 &&	/*当前格可以走*/
				!pathMap[nextPos.row][nextPos.col].isFind){    /*下一格没有走过*/
				pathMap[nextPos.row][nextPos.col].isFind = true;//记录已经走过了
				stack.push(tempPos);//存到栈里面去,回退需要
				nextPos = tempPos;//走动一步
			}
			else{//不往上走了,不走了   四个方向都不能走了
				stack.pop();//出栈   回退
				if (!stack.isEmpty())//栈不为空
					nextPos = stack.getTop();//下一个点是回退的点了
			}


			break;

		}
		if (nextPos.row == endPos.row && nextPos.col == endPos.col)//找到路径了
			break;
		if (stack.isEmpty())//栈都为空了,不走了...
			break;
	}

	while (!stack.isEmpty()){
		tempPos = stack.getTop();
		printf("row = %d\tcol = %d\n", tempPos.row, tempPos.col);
		stack.pop();
	}


	while (1);
	return 0;
}

