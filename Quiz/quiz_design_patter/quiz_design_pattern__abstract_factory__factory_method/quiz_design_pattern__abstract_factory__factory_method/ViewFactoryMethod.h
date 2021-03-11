#pragma once
#include "PlayLib.h"
#include "DrawManager.h"

class ViewFactoryMethod
{
protected:
	DrawManager m_viewDrawManager;
public:
	virtual void DrawView() = 0;
};

