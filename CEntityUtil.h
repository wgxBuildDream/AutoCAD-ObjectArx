#pragma once
class CEntityUtil
{
public:
	CEntityUtil();
	~CEntityUtil();
	//�޸�ʵ����ɫ
	static void setColor(AcDbObjectId objectID, int ColorIndex);

	//�޸�ʵ���ͼ��
	static void setLayer(AcDbObjectId objectID, const TCHAR* LayerName);

	//�޸�ʵ�������
	static void setLineType(AcDbObjectId objectID, const TCHAR* LineType);

	//����ָ���Ƕ���һ����תָ����ʵ��
	static Acad::ErrorStatus Rotate(AcDbObjectId objectID, const AcGePoint2d &pBasePoint, double rotationAngle);

	//��ʵ���һ���ƶ�������һ��
	static Acad::ErrorStatus Move(AcDbObjectId objectID, AcGePoint3d &pBasePoint, AcGePoint3d &pDest);

	//��һ�㰴��������ָ����ʵ��
	static Acad::ErrorStatus Scale(AcDbObjectId objectID, const AcGePoint3d &pBasePoint, double scaleSize);
};

