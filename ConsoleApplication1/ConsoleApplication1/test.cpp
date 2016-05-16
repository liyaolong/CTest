#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

#include"CTest.h"

int main()
{
	/*SysCheck();
	cout << IsLitte_Endian() << endl;*/
	char* src = "abcdw";
	char dst[20] = "as";
	_strncpy(dst, src, 0);
	//_strcpy(dst, src);
	//strcpy(dst, src);
	//_strcat(dst, src);
	//_strncat(dst, src,0);
	//cout << _strlen_R(src) <<endl;
	return 0;
}