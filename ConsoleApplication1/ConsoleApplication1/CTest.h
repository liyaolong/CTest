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
