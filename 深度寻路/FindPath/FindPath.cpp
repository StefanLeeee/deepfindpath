// FindPath.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyStack.h"

#define MAP_LENGTH 12


enum Path_Dir{
	p_up,		//�� 0
	p_down,		//�� 1
	p_left,		//�� 2
	p_right		//�� 3
};
struct MyPoint{//�����Ľṹ��
	int row;		//��������	y
	int col;		//��������	x
};


struct PathNode{//Ѱ·��ͼ������Ϣ
	int val;		//ֵ �Ƿ��ͨ��  0 ���� 1
	Path_Dir dir;	//����
	bool isFind;	//�Ƿ��߹���
};

int _tmain(int argc, _TCHAR* argv[])
{	/*	int map[MAP_LENGTH][MAP_LENGTH] = {			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },			{ 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },			{ 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 },			{ 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1 },			{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },			{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },			{ 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1 },			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }	};*/
	//������Ϣ�ĵ�ͼ ��¼Ѱ·����	PathNode pathMap[MAP_LENGTH][MAP_LENGTH];	//��ʼ��������Ϣ�ĵ�ͼ	for (size_t i = 0; i < MAP_LENGTH; i++){		for (size_t j = 0; j < MAP_LENGTH; j++)		{			pathMap[i][j].val = map[i][j];//ֵ��map��ֵ��ͬ			pathMap[i][j].isFind = false;//һ��ʼ��û���߹�			pathMap[i][j].dir = p_up;//һ��ʼ���������� Ѱ·�������:��,��,��,��  �ӷ�		}	}
	MyPoint beginPos = { 1, 1 };	//���	MyPoint endPos = { 10, 10 };	//�յ�

	CMyStack<MyPoint> stack;
	stack.push(beginPos);

	MyPoint nextPos = stack.getTop();//������һ��Ҫ�ߵĵ�
	MyPoint tempPos;//��ʱ��
	while (1){//��ѭ��һֱ��
		tempPos = nextPos;//��ʱ����Ҫ��һ��Ҫ�ߵĵ�
		switch (pathMap[nextPos.row][nextPos.col].dir){//��鷽��
		case p_up:
			tempPos.row--;
			if (pathMap[tempPos.row][tempPos.col].val = 0  &&	/*��ǰ�������*/
				! pathMap[nextPos.row][nextPos.col].isFind){    /*��һ��û���߹�*/
				pathMap[nextPos.row][nextPos.col].dir = p_down;//����ı���   ����ı�Ĺ���... �� �� �� ��
				pathMap[nextPos.row][nextPos.col].isFind = true;//��¼�Ѿ��߹���
				stack.push(tempPos);//�浽ջ����ȥ,������Ҫ
				nextPos = tempPos;//�߶�һ��
			}
			else{//��������
				pathMap[nextPos.row][nextPos.col].dir = p_down;//����ı�
			}

			break;
		case p_down:
			tempPos.row++;
			if (pathMap[tempPos.row][tempPos.col].val = 0 &&	/*��ǰ�������*/
				!pathMap[nextPos.row][nextPos.col].isFind){    /*��һ��û���߹�*/
				pathMap[nextPos.row][nextPos.col].dir = p_left;//����ı���   ����ı�Ĺ���... �� �� �� ��
				pathMap[nextPos.row][nextPos.col].isFind = true;//��¼�Ѿ��߹���
				stack.push(tempPos);//�浽ջ����ȥ,������Ҫ
				nextPos = tempPos;//�߶�һ��
			}
			else{//��������
				pathMap[nextPos.row][nextPos.col].dir = p_left;//����ı�
			}

			break;
		case p_left:
			tempPos.col--;
			pathMap[nextPos.row][nextPos.col].dir = p_right;//����ı���   ����ı�Ĺ���... �� �� �� ��

			if (pathMap[tempPos.row][tempPos.col].val = 0 &&	/*��ǰ�������*/
				!pathMap[nextPos.row][nextPos.col].isFind){    /*��һ��û���߹�*/
				pathMap[nextPos.row][nextPos.col].isFind = true;//��¼�Ѿ��߹���
				stack.push(tempPos);//�浽ջ����ȥ,������Ҫ
				nextPos = tempPos;//�߶�һ��
			}
		
			break;
		case p_right:
			tempPos.col++;

			if (pathMap[tempPos.row][tempPos.col].val = 0 &&	/*��ǰ�������*/
				!pathMap[nextPos.row][nextPos.col].isFind){    /*��һ��û���߹�*/
				pathMap[nextPos.row][nextPos.col].isFind = true;//��¼�Ѿ��߹���
				stack.push(tempPos);//�浽ջ����ȥ,������Ҫ
				nextPos = tempPos;//�߶�һ��
			}
			else{//����������,������   �ĸ����򶼲�������
				stack.pop();//��ջ   ����
				if (!stack.isEmpty())//ջ��Ϊ��
					nextPos = stack.getTop();//��һ�����ǻ��˵ĵ���
			}


			break;

		}
		if (nextPos.row == endPos.row && nextPos.col == endPos.col)//�ҵ�·����
			break;
		if (stack.isEmpty())//ջ��Ϊ����,������...
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

