#include <iostream>
#include "../libBigInt/include/entier.hpp"

using namespace std;

int main()
{
    Entier a(0xffffffff);
	cout<<a<<endl;
	a+=4;
	cout<<a<<endl;
	a-=10;
	cout<<a<<endl;
    return 0;
}
