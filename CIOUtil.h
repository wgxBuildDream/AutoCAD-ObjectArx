#pragma once
class CIOUtil
{
public:
	CIOUtil();
	~CIOUtil();

	//����ǰͼ���д��ڵ�����ͼ�㼰������(ͼ�����ơ���ɫ��ͼ�����͡�ͼ���߿�)������ָ�����ı��ļ���
	static void ExportLayer(const TCHAR* FileName);

	//����ָ���ı��ļ��е�ͼ���б�����(ͼ�����ơ���ɫ��ͼ�����͡�ͼ���߿�)�ڵ�ǰͼ���д���ͼ��
	static void ImportLayer(const TCHAR* FileName);
};

