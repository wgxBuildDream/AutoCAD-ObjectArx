#include "stdafx.h"
#include "CJig.h"
#include "CDwgDatebaseUtil.h"
#include "dbjig.h"
#define PI 3.141592654
CJig::CJig()
{
	m_pPoly = NULL;
}


CJig::~CJig()
{
}

bool CJig::doit(const AcGePoint3d & centerPoint, AcDbObjectId & polyid)
{
	m_centerPoint = centerPoint;
	//�϶���ʼǰ�������߶δ�������
	m_pPoly = new AcDbPolyline();
	for (int i = 0; i < 4; i++)
	{
		m_pPoly->addVertexAt(i, AcGePoint2d(m_centerPoint.x, m_centerPoint.y));
	}
	m_pPoly->setClosed(true);
	//�����ϵ�����
	CString prompt = _T("\nָ����ע�����: ");
	setDispPrompt(prompt);
	AcEdJig::DragStatus status = drag();

	//�϶��������������ز���
	if (status==kNormal)
	{
		polyid = CDwgDatebaseUtil::PostToModelSpace(m_pPoly);
		return true;
	}
	else
	{
		delete m_pPoly;
		return false;
	}
}

AcEdJig::DragStatus CJig::sampler()
{
	setUserInputControls((UserInputControls)(AcEdJig::kAccept3dCoordinates | AcEdJig::kNoNegativeResponseAccepted | AcEdJig::kNullResponseAccepted));

	//�жϵ��Ƿ����˱仯
	static AcGePoint3d pointtem;
	DragStatus sta = acquirePoint(m_curPoint);
	if (pointtem!=m_curPoint)
	{
		pointtem = m_curPoint;

	}
	else if (sta==kNormal)
	{
		return DragStatus::kNoChange;
	}
	return sta;
}

Adesk::Boolean CJig::update()
{
	//���²���
	AcGePoint2d center(m_centerPoint.x, m_centerPoint.y);
	AcGePoint2d curpoint(m_curPoint.x, m_curPoint.y);
	double dist = center.distanceTo(curpoint);
	for (int i = 0; i < 4; i++)
	{
		double angle = i * PI*0.5 + PI * 0.25;
		AcGePoint2d pt(center.x + dist * cos(angle), center.y + dist * sin(angle));
		m_pPoly->setPointAt(i, pt);
	}
	return Adesk::kTrue;
}

AcDbEntity * CJig::entity() const
{
	return m_pPoly;
	return nullptr;
}
