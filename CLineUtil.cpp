#include "stdafx.h"
#include "CLineUtil.h"
#include "CDwgDatebaseUtil.h"

CLineUtil::CLineUtil()
{
}


CLineUtil::~CLineUtil()
{
}

AcDbObjectId CLineUtil::add(const AcGePoint3d & pStartPoint, const AcGePoint3d & pEndPoint)
{
	//����ֱ��ʵ��
	AcDbLine *pLine = new AcDbLine(pStartPoint, pEndPoint);
	//��ֱ��ʵ����ӵ�ģ�Ϳռ�
	return CDwgDatebaseUtil::PostToModelSpace(pLine);
}

