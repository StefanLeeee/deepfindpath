// ���Ѱ·.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyStack.h"
#include <stdlib.h>
//��ͼ���� Y
#define ROW  10
//��ͼ���� X
#define COL  10
//�ٶ�
#define SPEED 100

struct MyPoint{
	int row;
	int col;
};

//��ʾ�����ö��
enum MyDir{p_up,p_down,p_left,p_right};

struct MyPath{
	int		val;	//�ϰ�or·
	MyDir	dir;	//����
	bool	isFind;	//true:�߹� false:û���߹�
};


void drawMap(int map[ROW][COL], MyPoint point){
	system("cls");//����

	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (map[i][j] == 1){//ǽ
				printf("ǽ");
			}
			else if (point.row == i && point.col == j){//��
				printf("��");
			}
			else{//·
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

	//��ͼ 0:· 1:�ϰ�
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
	//������ͼ
	MyPath pathMap[ROW][COL] = { 0 };//������p_up isFind����false
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
			//����ı�
			pathMap[searchPos.row][searchPos.col].dir = p_down;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//������
				
				//��¼�߹�
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//��ջ
				stack.push(currentPos);
				//��
				searchPos = currentPos;
			}
			break;
		case p_down:
			currentPos.row++;
			//����ı�
			pathMap[searchPos.row][searchPos.col].dir = p_left;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//������

				//��¼�߹�
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//��ջ
				stack.push(currentPos);
				//��
				searchPos = currentPos;
			}
			break;
		case p_left:
			currentPos.col--;
			//����ı�
			pathMap[searchPos.row][searchPos.col].dir = p_right;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//������

				//��¼�߹�
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//��ջ
				stack.push(currentPos);
				//��
				searchPos = currentPos;
			}
			break;
		case p_right:
			currentPos.col++;
			if (pathMap[currentPos.row][currentPos.col].val == 0 &&
				pathMap[currentPos.row][currentPos.col].isFind == false){
				//������

				//��¼�߹�
				pathMap[currentPos.row][currentPos.col].isFind = true;
				//��ջ
				stack.push(currentPos);
				//��
				searchPos = currentPos;
			}
			else{//�Ѿ���������ͬ
				//ɾ��ջ��Ԫ��
				stack.pop();
				//��ǰλ�ñ��ջ��
				searchPos = stack.getStackTop();
			}
			break;
		
		}

		if (searchPos.row == endPos.row &&
			searchPos.col == endPos.col){//�����յ�
			printf("�ҵ��յ���!\n");
			break;
		}

		if (stack.isStackEmpty()){//�ص�ԭ��
			printf("����Թ�û�г���!\n");
			break;
		}

		drawMap(map, searchPos);



	}

	//��ӡ·��
	while (!stack.isStackEmpty()){//��ջ����ջ�״�ӡ
		currentPos = stack.getStackTop();
		printf("(%d,%d) ", currentPos.row, currentPos.col);
		stack.pop();
	}
	printf("\n");

#endif


	while (1);
	return 0;
}

