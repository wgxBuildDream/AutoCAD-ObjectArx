#pragma once
class CViewUtil
{
public:
	CViewUtil();
	~CViewUtil();

	//��ȡ��ǰ����ͼ��Ϣ
	static void GetCurrentView(AcDbViewTableRecord &view);
	
	//����4���ȴ���ӿ�
	static void Create4ViewPort();

	//�ڡ����֡�������µ��ӿ�
	static void CreateViewPortInSpace();

	//����һ���µ�UCS����ϵ
	static void NewUCS();

	//��UCS�����Ѿ����ڵ�һ��UCS����Ϊ��ǰUCS
	static void SetCurrentUCS();
};

