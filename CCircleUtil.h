#pragma once
class CCircleUtil
{
public:
	CCircleUtil();
	~CCircleUtil();

	//Բ�ġ�Բ����ƽ��Ͱ뾶��Բ
	static AcDbObjectId add(const AcGePoint3d &Point, const AcGeVector3d &Normal, double radius);

	//Բ�ġ�XOYƽ��Ͱ뾶��Բ
	static AcDbObjectId add(AcGePoint3d &Point, double radius);

	//������XOYƽ������Բ
	static AcDbObjectId add(AcGePoint2d &FirstPoint, AcGePoint2d &SecondPoint);

	//������XOYƽ����Բ
	static AcDbObjectId add(AcGePoint2d &FirstPoint, AcGePoint2d &SecondPoint, AcGePoint2d &ThirdPoint);
};

