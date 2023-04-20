#include "stdafx.h"
#include "CGetInputUtil.h"
#include "geassign.h"


CGetInputUtil::CGetInputUtil()
{
}


CGetInputUtil::~CGetInputUtil()
{
}

AcGePoint3d CGetInputUtil::WcsToUcsPoint(const AcGePoint3d & point)
{
	AcGePoint3d pt;
	resbuf rbfrom, rbto;
	rbfrom.restype = RTSHORT;
	rbfrom.resval.rint = 0;//WCS
	rbto.restype = RTSHORT;
	rbto.resval.rint = 1;//UCS

	acedTrans(asDblArray(point), &rbfrom, &rbto, Adesk::kFalse, asDblArray(pt));

	return pt;
}

AcGePoint3d CGetInputUtil::UcsToWcsPoint(const AcGePoint3d & point)
{
	AcGePoint3d pt;
	resbuf rbfrom,rbto;
	rbfrom.restype = RTSHORT;
	rbfrom.resval.rint = 1;//UCS
	rbto.restype = RTSHORT;
	rbto.resval.rint = 0;//WCS

	acedTrans(asDblArray(point), &rbfrom, &rbto, Adesk::kFalse, asDblArray(pt));
	return pt;
}

bool CGetInputUtil::GetPoint(const AcGePoint3d & basePoint, const TCHAR * prompt, AcGePoint3d & point)
{
	//acedGetPoint�����ļ�������ͷ��ص�ʧȥ�����궼��UCS���ִ꣬��ǰ��ת����֮����ת����
	AcGePoint3d ucspoint = WcsToUcsPoint(basePoint);
	int nReturn = acedGetPoint(asDblArray(ucspoint), prompt, asDblArray(point));
	if (nReturn==RTNORM)
	{
		point = UcsToWcsPoint(point);
		return true;

	}
	else
	{
		return false;
	}
}

bool CGetInputUtil::GetPoint(const TCHAR * prompt, AcGePoint3d & point)
{
	int nReturn = acedGetPoint(NULL, prompt, asDblArray(point));
	if (nReturn==RTNORM)
	{
		point = UcsToWcsPoint(point);
		return true;
	}
	else
	{
		return false;
	}
}
