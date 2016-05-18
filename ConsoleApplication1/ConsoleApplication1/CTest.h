#pragma once


//大小端模式的判断
//方法一：利用联合体所有成员的起始位置一致，
//对联合体中的int类型赋值，然后判断联合体中char类型的值的大小

void SysCheck()
{
	union IsLitte_Endian
	{
		int i;
		char c;
	};
	IsLitte_Endian Check;
	Check.i = 1;
	bool Flag=Check.c == 1;	//Flag为true表示是小端模式，Flag为false表示为大端模式，此时Flag为true。
	return;
}
//方法二：利用强制类型转换判断
//与共用体判断类似
bool IsLitte_Endian()

{

	int Wvar = 0x12345678;

	short *Pvar = (short*)&Wvar;

	return !(0x1234 == Pvar[0]);

}

//对字符串函数的实现
//1.strcpy
char* _strcpy(char* dest, const char* src)
{
	assert(dest != nullptr&&src != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	char* tmp = dest;
	while (*tmp++ = *src++)
		;
	return dest;
}
//2.strncpy
char* _strncpy(char* dest, const char* src, int n)
{
	assert(dest != nullptr&&src != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	int i = 0;
	char* tmp = dest;
	while (i++ < n && (*tmp++ = *src++))
		;
	while (i++ < n)
		*tmp++ = '\0';
	return dest;
}
//3.strcat
char* _strcat(char* dest, const char* src)
{
	assert(dest != nullptr&&src != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	char* tmp = dest;
	while (*tmp)//若为while(*dest++)则会跳过dest中的'\0'导致无法连接
		tmp++;
	while (*tmp++ = *src++)
		;
	return dest;
}
//4.strncat
char* _strncat(char* dest, const char* src, size_t n)
{
	assert(dest != nullptr&&src != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	char* tmp = dest;
	while (*tmp)//若为while(*dest++)则会跳过dest中的'\0'导致无法连接
		tmp++;

	while (n--)
	{
		if (!(*tmp++ = *src++))//保证当src的长度小于n时，此时tmp已有'\0'
			return dest;
	}

	*tmp = '\0';//对于src长度大于n时，加上字符串结尾
	return (char*)dest;
}
//strlen
//常规写法
size_t _strlen(const char* str)
{
	assert(str);
	const char* eofStr = str;
	while (*eofStr++)
		;
	return (eofStr - str - 1);
}
//递归写法，不借助变量(面试题要求)
size_t _strlen_R(const char* str)
{
	/*if ('\0' == str)
		return 0;

	return _strlen_R(str + 1) + 1;*/

	return *str ? _strlen_R(str + 1) + 1 : 0;//更为简洁
}
//strcmp
int _strcmp(const char* dest, const char* src)
{
	assert(dest != nullptr&&src != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	while (*dest&&*src && (*dest == *src))
	{
		dest++;
		src++;
	}
	return (*dest - *src);
}
//strncmp
int _strncmp(const char* dest, const char* src, size_t n)
{
	assert(dest != nullptr&&src != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	if (!n)//若n为0，则返回0；
		return 0;
	while (n--&&*dest&&*src && (*dest == *src))
	{
		dest++;
		src++;
	}

	return (*dest - *src);
}
//strstr
char* _strstr(const char* dest, const char* src)
{
	assert(dest != nullptr);
	//判断dest指针是否为空，若为空抛出异常
	if (!src)
		return (char*)dest;

	while (*dest)
	{
		const char* destTmp = dest;
		const char* srcTmp = src;
		while (*srcTmp == *destTmp && (*srcTmp))//限时*srcTmp与*destTmp比较后相等至'\0'时继续访问出现越界
		{
			srcTmp++;
			destTmp++;
		}
		if (!(*srcTmp))
			return (char*)destTmp;

		dest++;
	}
	return nullptr;
}
//memcpy
void* _memcpy(void* dest, const void* src, size_t count)
{
	assert(src != nullptr&&dest != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	char* tmp_dest = (char*)dest;
	const char* tmp_src = (const char*)src;
	//将指针dest和指针src由void强转为char，
	//使得每次均是对内存中的一个字节进行拷贝
	while (count--)
		*tmp_dest++ = *tmp_src++;
	return dest;
}
//memmpve
void* _memmove(void* dest, const void* src, size_t count)
{
	assert(src != nullptr&&dest != nullptr);
	//判断dest指针和src指针是否为空，若为空抛出异常
	char* tmp_dest = (char*)dest;
	const char* tmp_src = (const char*)src;

	if (tmp_src < tmp_dest)//当src地址小于dest地址时，从头进行拷贝
		while (count--)
			*tmp_dest++ = *tmp_src++;
	else if (tmp_src > tmp_dest)//当src地址大于dest地址时，从后进行拷贝
	{
		tmp_src += count - 1;
		tmp_dest += count - 1;
		while (count--)
			*tmp_dest-- = *tmp_src;
	}
	//else(tmp_src==tmp_dest) 此时不进行任何操作
	return dest;
}