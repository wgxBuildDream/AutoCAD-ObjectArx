#pragma once
#include <vector>
class CTextFileUtil
{
public:
	CTextFileUtil();
	~CTextFileUtil();

	//�Ѽ����е��ַ�������д��ָ���ļ�
	static void Save(const TCHAR *FileName, std::vector<CString>& text);

	//���ļ��е��ַ�������ΪԪ�ض��뼯��
	static void Load(const TCHAR *FileName, std::vector<CString>& text);

};

