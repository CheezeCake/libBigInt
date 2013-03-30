#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
	long int li = atol(argv[1]);
	string nombre;
	srand(time(NULL));

	for(long int i = 0; i < li; i++)
	    nombre +=  rand() % 9 + 1 + '0';

	cout << nombre << endl;
    }

    return 0;
}
