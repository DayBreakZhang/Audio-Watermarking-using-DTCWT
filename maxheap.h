#pragma once

//C++���״󶥶�
//Author:Qichao Ying


#ifndef maxheap_h
#define maxheap_h
template<class T>
class Maxheap
{
public:
	Maxheap(int size);
	~Maxheap();
	bool Isempty();
	void push(T item);  //�������
	void pop();  //ɾ������
	void clear();  //ɾ������
	T top();
	T *heap;
	int currentSize;
	int capacity;
};
//-------���캯����ʼ��-------
template<class T>
Maxheap<T>::Maxheap(int size)
{
	if (size < 1)
	{
		throw"capacity must be >=1";
	}
	else
	{
		currentSize = 0;
		capacity = size;
		heap = new T[capacity + 1]; //heap[0]��ʹ��
	}
}
//-------���������ͷſռ�-------
template<class T>
Maxheap<T>::~Maxheap()
{
	delete[]heap;
}
//--------�ж϶��Ƿ�Ϊ��-------
template<class T>
bool Maxheap<T>::Isempty()
{
	return currentSize == 0;
}
//---------��ȡ���Ԫ��----------
template<class T>
T Maxheap<T>::top()
{
	return heap[1];
}
//-------�������-----
template<class T>
void Maxheap<T>::push(T item)
{
	if (currentSize == capacity)
		throw "Maxheap is full";
	else
	{
		currentSize++;
		int currentNode = currentSize;// Ԫ�صĲ���λ�ó�ʼ��Ϊ���
		while (currentNode > 1 && heap[currentNode / 2] < item)  //(��������)���е���
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode = currentNode / 2;
		}
		heap[currentNode] = item; //����Ԫ��
	}
}

template<class T>
void Maxheap<T>::clear()
{
	heap = new T[capacity + 1];
	currentSize=0;
}

//-----ɾ������-------
template<class T>
void Maxheap<T>::pop()
{
	if (Isempty())
		throw"heap is empty ,cannot delete";
	else
	{
		T last = heap[currentSize];  //�����һ��Ԫ�س�ʼ��Ϊ��
		currentSize--;
		int currentNode = 1;
		int child = 2;
		while (child < currentSize)  //���������£����е���
		{
			if (child < currentSize&&heap[child] < heap[child + 1])
				child++;
			if (last > heap[child])
				break;
			else
			{
				heap[currentNode] = heap[child];
				currentNode = child;
				child = child * 2;
			}
		}
		heap[currentNode] = last;
	}
}
#endif

//Example:
//Maxheap<entity> H1(3);
//for (int i = 0; i < 3; i++) {
//	entity e(i, -i);
//	H1.push(e);
//}
//
//cout << endl << H1.top().value << endl;

