#pragma once
#include <vector>
class CStringUtil
{
public:
	CStringUtil();
	~CStringUtil();
	//���ݸ����ַ��ָ��ַ��������ѷָ���ַ���д�뼯��
	static void Spil(const CString &text, const TCHAR *separater, std::vector<CString>&result);

	//��һ�������е��ַ������ݸ������ַ����ӳ�һ���ַ���
	static void join(std::vector<CString>& result,const TCHAR *separater, CString &text);
};

