#include "Door.h"


void Door::SetObj(int stage)
{
	m_iStage = stage;
	m_strObject = "¢Ä";
	m_stObjPos.iX = MAP_WIDTH / 2;
	if (stage == 1)
		m_stObjPos.iY = 1;
	else if (stage == 2)
		m_stObjPos.iY = MAP_HEIGHT-2;
}

void Door::DrawObject(int stage)
{
	BLUE
	if (m_iStage == 1)
		m_objDrawManager.DrawObject(m_strObject, m_stObjPos.iX, m_stObjPos.iY + (MAP_HEIGHT + 5));
	else if (m_iStage == 2)
		m_objDrawManager.DrawObject(m_strObject, m_stObjPos.iX, m_stObjPos.iY);
	ORIGINAL
}