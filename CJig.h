#pragma once
class CJig:public AcEdJig
{
public:
	CJig();
	virtual ~CJig();
	//�ⲿ���õĺ�����һ�����ڳ�ʼ��
	bool doit(const AcGePoint3d &centerPoint, AcDbObjectId &polyid);

	//�˺�����drag���������Ի���û�����
	virtual AcEdJig::DragStatus sampler();

	//����Ҫ���ϵ������з����仯��ʵ������޸�
	virtual Adesk::Boolean update();

	//ָ��Jig�����Ķ���
	virtual AcDbEntity *entity() const;

private:
	AcDbPolyline * m_pPoly;
	AcGePoint3d m_centerPoint;
	AcGePoint3d m_curPoint;

};

