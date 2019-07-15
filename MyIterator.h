template <class T>
class MyIterator
{
private:
	T * pointer;
public:
	MyIterator() :pointer(nullptr) {};
	MyIterator(T * value) :pointer(value) {};
	MyIterator<T> operator+(int );
	MyIterator<T> operator-(int );
	MyIterator<T> &operator+=(int );
	MyIterator<T> &operator-=(int);
	MyIterator<T> &operator ++();
	MyIterator<T> operator ++(int);
	MyIterator<T> &operator--();
	MyIterator<T> operator--(int);
	bool operator !=(const MyIterator<T> &);
	T & operator[](size_t );
	T & operator* ();
	T * operator ->() { return pointer; }
};
template<class T>
MyIterator<T> MyIterator<T>::operator+(int add)
{
	return MyIterator<T>(pointer + add);
}
template<class T>
MyIterator<T> MyIterator<T>::operator-(int sub)
{
	return MyIterator<T>(pointer - sub);
}
template<class T>
MyIterator<T>& MyIterator<T>::operator+=(int add)
{
	pointer += add;
	return *this;
}
template <class T>
MyIterator<T>& MyIterator<T>::operator-=(int sub)
{
	pointer += sub;
	return *this;
}
template<class T>
MyIterator<T> & MyIterator<T>::operator++()
{
	pointer++;
	return *this;
}
template<class T>
MyIterator<T> MyIterator<T>::operator++(int)
{
	pointer++;
	return *this;
}
template<class T>
MyIterator<T> & MyIterator<T>::operator--()
{
	pointer--;
	return *this;
}
template<class T>
MyIterator<T> MyIterator<T>::operator--(int)
{
	pointer--;
	return *this;
}
template<class T>
bool MyIterator<T>::operator!=(const MyIterator<T>& iter)
{
	return pointer != iter.pointer;
}
template <class T>
T & MyIterator<T>::operator[](size_t pos)
{
	return *(pointer + pos);
}
template <class T>
T & MyIterator<T>::operator*()
{
	return *pointer;
}