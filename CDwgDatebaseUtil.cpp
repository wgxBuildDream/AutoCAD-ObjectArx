#include "stdafx.h"
#include "CDwgDatebaseUtil.h"

CDwgDatebaseUtil::CDwgDatebaseUtil()
{
}


CDwgDatebaseUtil::~CDwgDatebaseUtil()
{
}

AcDbObjectId CDwgDatebaseUtil::PostToModelSpace(AcDbEntity * pEntity)
{
	Acad::ErrorStatus es;
	//������������Ч��
	assert(pEntity != NULL);

	//��ȡ��ǰͼ�����ݿ�Ŀ��
	AcDbBlockTable *pBlockTable;
	es=acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead);

	//��ȡģ�Ϳռ��Ӧ�Ŀ���¼
	AcDbBlockTableRecord *pBlockTableRecord;
	es=pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);


	//��ʵ����ӵ��ռ��Ӧ�Ŀ���¼��
	AcDbObjectId ObjectID;
	es=pBlockTableRecord->appendAcDbEntity(ObjectID, pEntity);
	if (es!=Acad::eOk)
	{
		pBlockTable->close();
		pBlockTableRecord->close();
		//���ʧ��ʱ��Ҫdelete���ɹ�����appendAcdbEntity֮�������ݿ��������ö���
		delete pEntity;
		pEntity = NULL;
		return AcDbObjectId::kNull;
	}

	//�ر�ģ�Ϳռ��ʵ��
	pBlockTable->close();
	pBlockTableRecord->close();
	pEntity->close();

	return ObjectID;
}

AcDbObjectIdArray CDwgDatebaseUtil::GetAllEntityIDs(const TCHAR * layerName)
{
	AcDbObjectIdArray EntityIDs;
	bool bifFilterlayer = false;
	AcDbObjectId layerid;
	if (layerName != NULL)
	{
		AcDbLayerTable *layertable=NULL;
		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(layertable, AcDb::kForRead);
		if (!layertable->has(layerName))
		{
			layertable->close();
			acutPrintf(_T("�ڵ�ǰģ�Ϳռ�δ�ҵ�����Ϊ: %s ��ͼ��"), layerName);
			return EntityIDs;
		}
		layertable->getAt(layerName, layerid);
		layertable->close();
		bifFilterlayer = true;
	}

	AcDbBlockTable *pBlockTable;
	acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead);
	AcDbBlockTableRecord *PBlockTableRecoard;
	pBlockTable->getAt(ACDB_MODEL_SPACE, PBlockTableRecoard, AcDb::kForRead);
	pBlockTable->close();

	AcDbBlockTableRecordIterator *it=NULL;
	PBlockTableRecoard->newIterator(it);
	for (it->start();!it->done();it->step())
	{
		AcDbEntity *pEntity = NULL;
		Acad::ErrorStatus es = it->getEntity(pEntity, AcDb::kForRead);
		if (Acad::eOk==es)
		{
			if (bifFilterlayer)					//���ͼ������Ϊ�գ����˳�����ͼ�����Ƶ�ʵ��
			{
				if (pEntity->layerId() == layerid)
				{
					EntityIDs.append(pEntity->objectId());
				}
			}
			else								//��������еĶ�����id��
			{
				EntityIDs.append(pEntity->objectId());
			}
			pEntity->close();
		}
		else
		{
			acutPrintf(TEXT("\nCDwgDatebaseUtil::GetAllEntityIDs�д�ʵ��ʧ�ܣ����������:%d��"), (int)es);
		}
	}
	delete it;
	PBlockTableRecoard->close();
	return EntityIDs;
}
