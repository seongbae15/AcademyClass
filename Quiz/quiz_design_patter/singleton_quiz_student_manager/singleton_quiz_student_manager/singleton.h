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
public:
	static tp* GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new tp;
		return m_pThis;
	}
	static void ReleaseInstance()
	{
		if (m_pThis)
		{
			delete m_pThis;
			m_pThis = NULL;
		}
	}
};