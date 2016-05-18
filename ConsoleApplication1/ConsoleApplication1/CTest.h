#pragma once


//��С��ģʽ���ж�
//����һ���������������г�Ա����ʼλ��һ�£�
//���������е�int���͸�ֵ��Ȼ���ж���������char���͵�ֵ�Ĵ�С

void SysCheck()
{
	union IsLitte_Endian
	{
		int i;
		char c;
	};
	IsLitte_Endian Check;
	Check.i = 1;
	bool Flag=Check.c == 1;	//FlagΪtrue��ʾ��С��ģʽ��FlagΪfalse��ʾΪ���ģʽ����ʱFlagΪtrue��
	return;
}
//������������ǿ������ת���ж�
//�빲�����ж�����
bool IsLitte_Endian()

{

	int Wvar = 0x12345678;

	short *Pvar = (short*)&Wvar;

	return !(0x1234 == Pvar[0]);

}

//���ַ���������ʵ��
//1.strcpy
char* _strcpy(char* dest, const char* src)
{
	assert(dest != nullptr&&src != nullptr);
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
	char* tmp = dest;
	while (*tmp++ = *src++)
		;
	return dest;
}
//2.strncpy
char* _strncpy(char* dest, const char* src, int n)
{
	assert(dest != nullptr&&src != nullptr);
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
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
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
	char* tmp = dest;
	while (*tmp)//��Ϊwhile(*dest++)�������dest�е�'\0'�����޷�����
		tmp++;
	while (*tmp++ = *src++)
		;
	return dest;
}
//4.strncat
char* _strncat(char* dest, const char* src, size_t n)
{
	assert(dest != nullptr&&src != nullptr);
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
	char* tmp = dest;
	while (*tmp)//��Ϊwhile(*dest++)�������dest�е�'\0'�����޷�����
		tmp++;

	while (n--)
	{
		if (!(*tmp++ = *src++))//��֤��src�ĳ���С��nʱ����ʱtmp����'\0'
			return dest;
	}

	*tmp = '\0';//����src���ȴ���nʱ�������ַ�����β
	return (char*)dest;
}
//strlen
//����д��
size_t _strlen(const char* str)
{
	assert(str);
	const char* eofStr = str;
	while (*eofStr++)
		;
	return (eofStr - str - 1);
}
//�ݹ�д��������������(������Ҫ��)
size_t _strlen_R(const char* str)
{
	/*if ('\0' == str)
		return 0;

	return _strlen_R(str + 1) + 1;*/

	return *str ? _strlen_R(str + 1) + 1 : 0;//��Ϊ���
}
//strcmp
int _strcmp(const char* dest, const char* src)
{
	assert(dest != nullptr&&src != nullptr);
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
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
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
	if (!n)//��nΪ0���򷵻�0��
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
	//�ж�destָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
	if (!src)
		return (char*)dest;

	while (*dest)
	{
		const char* destTmp = dest;
		const char* srcTmp = src;
		while (*srcTmp == *destTmp && (*srcTmp))//��ʱ*srcTmp��*destTmp�ȽϺ������'\0'ʱ�������ʳ���Խ��
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
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
	char* tmp_dest = (char*)dest;
	const char* tmp_src = (const char*)src;
	//��ָ��dest��ָ��src��voidǿתΪchar��
	//ʹ��ÿ�ξ��Ƕ��ڴ��е�һ���ֽڽ��п���
	while (count--)
		*tmp_dest++ = *tmp_src++;
	return dest;
}
//memmpve
void* _memmove(void* dest, const void* src, size_t count)
{
	assert(src != nullptr&&dest != nullptr);
	//�ж�destָ���srcָ���Ƿ�Ϊ�գ���Ϊ���׳��쳣
	char* tmp_dest = (char*)dest;
	const char* tmp_src = (const char*)src;

	if (tmp_src < tmp_dest)//��src��ַС��dest��ַʱ����ͷ���п���
		while (count--)
			*tmp_dest++ = *tmp_src++;
	else if (tmp_src > tmp_dest)//��src��ַ����dest��ַʱ���Ӻ���п���
	{
		tmp_src += count - 1;
		tmp_dest += count - 1;
		while (count--)
			*tmp_dest-- = *tmp_src;
	}
	//else(tmp_src==tmp_dest) ��ʱ�������κβ���
	return dest;
}