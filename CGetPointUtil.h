#pragma once



class CGetPointUtil
{
public:
	CGetPointUtil();
	~CGetPointUtil();

	//������3d�����ߵ��е�
	static AcGePoint3d GetMiddlePoint(const AcGePoint3d &FirstPoint, const AcGePoint3d &SecondPoint);

	//������2d�����ߵ��е�
	static AcGePoint2d GetMiddlePoint(const AcGePoint2d &FirstPoint, const AcGePoint2d &SecondPoint);
	
};

