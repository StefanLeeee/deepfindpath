#pragma once

template <class T>
class MyStack{
	T*		pBuff;
	size_t	capacity;
	size_t	len;
public:
	MyStack();//构造
	~MyStack();//析构
	void push(const T& data);//入栈
	void pop();//出栈
	T getStackTop()const;//获得栈顶元素
	bool isStackEmpty()const;//判断栈是否为空
};
template <class T>
MyStack<T>::MyStack(){
	pBuff = NULL;
	capacity = len = 0;
}
template <class T>
MyStack<T>::~MyStack(){
	if (pBuff){
		delete[] pBuff;
		pBuff = NULL;
	}
	capacity = len = 0;
}

template <class T>
void MyStack<T>::push(const T& data){
	if (len >= capacity){//以1.5倍方式递增
		capacity = capacity + (((capacity >> 1) > 1) ? capacity >> 1 : 1);
		T* temp = new T[capacity];
		memcpy(temp, pBuff, sizeof(T)*len);
		if (pBuff){
			delete[] pBuff;
		}
		pBuff = temp;
	}
	pBuff[len++] = data;
}

template <class T>
void MyStack<T>::pop(){
	len--;
}

template <class T>
T MyStack<T>::getStackTop()const{
	return pBuff[len - 1];
}

template <class T>
bool MyStack<T>::isStackEmpty()const{
	return (len == 0);
}
