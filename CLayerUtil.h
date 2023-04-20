#pragma once
class CLayerUtil
{
public:
	CLayerUtil();
	~CLayerUtil();

	//������������ֺ���ɫ���Ŵ����µ�ͼ��
	static void add(TCHAR *LayerName, int colorindex);

	//����ͼ�����ƻ�ȡͼ���ID
	static AcDbObjectId GetLayerID(TCHAR *LayerName);

	//�޸�ָ��ͼ�����ɫ
	static bool SetLayerColor(TCHAR *layerName, int colorindex);

	//��ȡ��ǰͼ�������е�ͼ��ID����
	static void GetAllLayerIDList(AcDbObjectIdArray &layerids);

	//ɾ��ָ����ͼ��
	static void DeleteLayer(TCHAR *LayerName);
};

