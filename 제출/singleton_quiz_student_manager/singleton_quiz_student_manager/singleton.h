#pragma once
template <typename tp>
class singleton
{
private:
	static tp* m_pThis;
protected:
	singleton()
	{

	};
	virtual ~singleton()
	{
	};
}