#pragma once
template<class T>
class CMyStack{
	T* pBuff;
	size_t maxSize;//capacity
	size_t len;
public:
	CMyStack();
	~CMyStack();
	bool isEmpty()const;
	//得到栈顶元素
	T getTop()const;
	//存一个数据到栈里面去
	void push(T const& date);
	void pop();
};


template<class T>
void CMyStack<T>::pop(){
	len--;
}

template<class T>
void CMyStack<T>::push(T const& date){
	if (len >= maxSize){
		maxSize = maxSize + ( (maxSize >> 1) > 1 ? (maxSize >> 1) : 1 );
		T* temp = new T[maxSize];
		memcpy(temp, pBuff, sizeof(T)*len);
		delete[] pBuff;
		pBuff = temp;
	}
	pBuff[len++] = date;
}

template<class T>
T CMyStack<T>::getTop()const{
	return pBuff[len - 1];
}
template<class T>
bool CMyStack<T>::isEmpty()const{
	return len==0;
}

template<class T>
CMyStack<T>::~CMyStack(){
	if (pBuff)
		delete[] pBuff;
	maxSize = 0;
	len = 0;
}

template<class T>
CMyStack<T>::CMyStack(){
	pBuff = NULL;
	maxSize = 0;
	len = 0;
}



