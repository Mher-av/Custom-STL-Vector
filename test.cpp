#include <iostream>
#include <vector>
#include <algorithm>
#include "customvec.h"
using namespace std;
class A
{
private: 
	int x;
public:
	A() = default;
	A(int x) { this->x = x; }
	void get() { cout << x << endl; }
};
int main()
{
	customvec<A> veco;
	veco.push_back(A(12));
	veco.push_back(A(13));
	veco.push_back(A(14));
	veco.push_back(A(15));
	veco[1].get();
	
	auto it = veco.begin();
	it->get();
	
	system("pause");
	
}