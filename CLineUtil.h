#pragma once
class CLineUtil
{
public:
	CLineUtil();
	~CLineUtil();
	//ͨ�������յ㹹��һ��ֱ��
	static AcDbObjectId add(const AcGePoint3d &pStartPoint,const AcGePoint3d &pEndPoint);
};

