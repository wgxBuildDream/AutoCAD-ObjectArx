#pragma once
class CBlockUtil
{
public:
	CBlockUtil();
	~CBlockUtil();

	//����һ�������ԵĿ鶨�壬���ؿ�����
	static void addMyBlockDefine();

	//�����û�����Ŀ�����λ�õ��������
	static void InsertBlock();

	//��ͼ������ȡ�ض����Ե�ֵ
	static bool GetAttributeValue(AcDbBlockReference *pBlockRef, TCHAR *Tag, AcString &Value);
};

 