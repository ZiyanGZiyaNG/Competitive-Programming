#include "interactive.h"
using namespace std;
int main()
{
	Init();
	int a = get_num_of_boy();	
	int b = get_num_of_girl();
	Answer(a * b);
}

