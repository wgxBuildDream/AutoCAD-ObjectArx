#include "stdafx.h"
#include "CBlockUtil.h"
#include "CDwgDatebaseUtil.h"
#include <geassign.h>
#include <acutmem.h>




CBlockUtil::CBlockUtil()
{
}
CBlockUtil::~CBlockUtil()
{
}

void CBlockUtil::addMyBlockDefine()
{
	AcDbBlockTable *pBlockTable=NULL;
	acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable,AcDb::kForWrite);

	AcDbBlockTableRecord *pBlockTableRecord = new AcDbBlockTableRecord();
	TCHAR BlockName[40];
	if (acedGetString(Adesk::kFalse,_T("\n����ͼ�������:"),BlockName)!=RTNORM)
	{
		pBlockTable->close();
		delete pBlockTableRecord;
		return;
	}
	pBlockTableRecord->setName(BlockName);
	AcDbObjectId BlockDefineid;
	pBlockTable->add(BlockDefineid, pBlockTableRecord);
	pBlockTable->close();

	AcGePoint3d p1(-10, 0, 0);
	AcGePoint3d p2(10, 0, 0);
	AcDbLine *pLine1 = new AcDbLine(p1, p2);
	p1.set(0, 10, 0);
	p2.set(0, -10, 0);
	AcDbLine *pLine2 = new AcDbLine(p1, p2);

	AcGeVector3d ver(0, 0, 1);
	AcDbCircle *pCircle = new AcDbCircle(AcGePoint3d::kOrigin, ver, 6);

	AcDbAttributeDefinition *pAttributeName = new AcDbAttributeDefinition(p1, _T("׼��"), _T("���ƣ�"), _T("��������"));
	AcDbAttributeDefinition *pAttributeDiametion = new AcDbAttributeDefinition(p2, _T("12"), _T("Բ��ֱ��"), _T("׼��Բ��ֱ��"));

	pBlockTableRecord->appendAcDbEntity(pLine1);
	pBlockTableRecord->appendAcDbEntity(pLine2);
	pBlockTableRecord->appendAcDbEntity(pCircle);
	pBlockTableRecord->appendAcDbEntity(pAttributeDiametion);
	pBlockTableRecord->appendAcDbEntity(pAttributeName);

	pBlockTableRecord->close();
	pLine1->close();
	pLine2->close();
	pCircle->close();
	pAttributeDiametion->close();
	pAttributeName->close();

	return;
}

void CBlockUtil::InsertBlock()
{
	TCHAR BlockName[40];
	if (acedGetString(Adesk::kFalse,_T("����Ҫ�����ͼ������"),BlockName)!=RTNORM)
	{
		return;
	}
	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForWrite);
	CString strBlkName;
	strBlkName.Format(TEXT("%S"), BlockName);
	if (!pBlockTable->has(strBlkName))
	{
		acutPrintf(_T("\n��ǰͼ����δ����ָ�����Ƶ�ͼ��"));
		pBlockTable->close();
		return;
	}

	ads_point pt;
	if (acedGetPoint(NULL,_T("\n�������յĲ����"),pt)!=RTNORM)
	{
		pBlockTable->close();
		return;
	}
	AcDbObjectId pBlockDefId;
	pBlockTable->getAt(strBlkName,pBlockDefId);

	AcGePoint3d InsertPoint = asPnt3d(pt);

	AcDbBlockReference *pBlockRef = new AcDbBlockReference(InsertPoint, pBlockDefId);

	CDwgDatebaseUtil::PostToModelSpace(pBlockRef);
}

bool CBlockUtil::GetAttributeValue(AcDbBlockReference *pBlockRef, TCHAR *Tag, AcString &Value)
{
	bool bifFind = false;
	AcDbObjectIterator *it = pBlockRef->attributeIterator();
	if (it)
	{
		for (it->start(); !it->done(); it->step())
		{
			AcDbAttribute *pAttribute=NULL;
			AcDbObjectId objectid = it->objectId();
			if (pBlockRef->openAttribute(pAttribute,objectid,AcDb::kForRead)==Acad::eOk)
			{
				TCHAR *szTag = pAttribute->tag();
				CString TagName = Tag;
				TagName.MakeUpper();				//�����������Tag��Զ�����Ǵ�д��ĸ����˴���Ĳ�����Ҫ����ת��
				if (TagName.Compare(szTag)==0)
				{
					TCHAR *szValue = pAttribute->textString();
					Value = szValue;
					bifFind = true;
					acutDelString(szValue);
					acutDelString(szTag);
					pAttribute->close();
					break;
				}
				acutDelString(szTag);
				pAttribute->close();
			}
		}
		delete it;
		return bifFind;
	}
	else
	{
		return false;
	}
}
