#pragma once
class CDwgDatebaseUtil
{
public:
	CDwgDatebaseUtil();
	~CDwgDatebaseUtil();
	//��ģ�Ͷ�����ӵ�ͼ�����ݿ�
	static AcDbObjectId PostToModelSpace(AcDbEntity *pEntity);

	//������ǰͼ�ε�ģ�Ϳռ䣬��ȡλ��ĳ��ͼ���ϵ�����ʵ�壬��ͼ����Ϊ�գ��������ǰģ�Ϳռ������ʵ�壬����ID��
	static AcDbObjectIdArray GetAllEntityIDs(const TCHAR *layerName=NULL);
};

