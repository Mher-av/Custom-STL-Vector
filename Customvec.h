#include "MyIterator.h"
template <class T>
class customvec
{
private:
	size_t mycapacity;
	size_t cursize;
	T* arr;
public:
	friend class MyIterator<T>;
	customvec();
	explicit customvec(size_t );
	customvec(size_t , T );
	customvec(const customvec<T> &);
	customvec(customvec<T>&&);
	customvec & operator = (const customvec<T> &);
	customvec & operator = (customvec<T> &&);
	void push_back(T );
	void pop_back();
	MyIterator<T> begin();
	MyIterator<T> end();
	MyIterator<T> erase();
	size_t size() const;
	size_t capacity() const;
	T &operator[](size_t);
	~customvec();
};
template <class T>
customvec<T>::customvec():mycapacity(0),cursize(0),arr(nullptr)
{
}
template <class T>
customvec<T>::customvec(size_t size) : mycapacity(size), cursize(size)
{
	arr = new T[cursize]();
}
template <class T>
customvec<T>::customvec(size_t size, T data) : mycapacity(size), cursize(size)
{
	arr = new T[cursize];
	for (size_t i = 0; i < cursize; ++i)
		arr[i] = data;
}
template <class T>
customvec<T>::customvec(const customvec<T> & other): mycapacity(other.mycapacity),cursize(other.cursize)
{
	arr = new T[mycapacity]();
	for (size_t i = 0; i < cursize; ++i)
		arr[i] = other.arr[i];
}
template <class T>
customvec<T>::customvec(customvec<T> && other) : mycapacity(other.mycapacity), cursize(other.cursize),arr(other.arr)
{
	other.arr = nullptr;
	other.mycapacity = 0;
	other.cursize = 0;
}
template<class T>
customvec<T> & customvec<T>::operator = (const customvec<T> & other)
{
	if (this == &other)
		return *this;
	delete[] arr;
	mycapacity = other.mycapacity;
	cursize = other.cursize;
	arr = new T[mycapacity]();
	for (size_t i = 0; i < cursize; ++i)
		arr[i] = other.arr[i];
	return *this;
}
template<class T>
customvec<T> & customvec<T>::operator=(customvec<T> && other)
{
	if (this != &other)
	{
		delete[] arr;
		mycapacity = other.mycapacity;
		cursize = other.cursize;
		arr = other.arr;
		other.arr = nullptr;
		other.mycapacity = 0;
		other.cursize = 0;
	}
	return *this;
}
template<class T>
customvec<T>::~customvec()
{
	delete[] arr;
}
template <class T>
void customvec<T>::push_back(T data)
{
	if (cursize == mycapacity)
	{
		mycapacity += 5;
		T *temp = new T[mycapacity];
		for (size_t i = 0; i < cursize; ++i)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		temp[cursize] = data;
		arr = temp;
		cursize++;
	}
	else
	{
		arr[cursize] = data;
		cursize++;
	}
}
template<class T>
void customvec<T>::pop_back()
{
	if (cursize > 0)
		cursize--;
}
template <class T>
size_t customvec<T>::size() const
{
	return cursize;
}
template <class T>
size_t customvec<T>::capacity() const
{
	return mycapacity;
}
template <class T>
T& customvec<T>::operator[](size_t place)
{
	return arr[place];
}
template <class T>
MyIterator<T> customvec<T>::begin()
{
	return MyIterator<T>(arr);
}
template <class T>
MyIterator<T> customvec<T>::end()
{
	return MyIterator<T>(arr+cursize-1);
}
