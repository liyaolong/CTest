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
