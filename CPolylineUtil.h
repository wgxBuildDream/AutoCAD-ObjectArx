#pragma once
class CPolylineUtil
{
public:
	CPolylineUtil();
	~CPolylineUtil();

	//���ݶ������鴴���������߶�
	static AcDbObjectId add(const AcGePoint2dArray &Points, double width = 0);

	//���ݶ��㴴����ά���߶�
	static AcDbObjectId add(const AcGePoint3dArray &Points);

	//�������ĵ㡢���������Բ�뾶����ת�Ƕȣ����ȣ����߿����������
	static AcDbObjectId addPolygon(AcGePoint2d &pCenterPoint, int number, double radius, double ratation, double width = 0);

	//���������ǵ㴴������
	static AcDbObjectId addRect(const AcGePoint2d &Point1, const AcGePoint2d &Point2, double width=0);
};

