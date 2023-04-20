#pragma once
class CGetInputUtil
{
public:
	CGetInputUtil();
	~CGetInputUtil();

	//WCSת��ΪUCS
	static AcGePoint3d WcsToUcsPoint(const AcGePoint3d &point);

	//UCSת��ΪWCS
	static AcGePoint3d UcsToWcsPoint(const AcGePoint3d &point);

	//ָ��������������ʾ�û�ѡȡһ����
	static bool GetPoint(const AcGePoint3d &basePoint, const TCHAR* prompt, AcGePoint3d &point);

	//��ָ��������������ʾ�û�ѡȡһ����
	static bool GetPoint(const TCHAR* prompt, AcGePoint3d &point);
};

