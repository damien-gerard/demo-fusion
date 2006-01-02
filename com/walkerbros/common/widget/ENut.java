// ENut.java

package com.walkerbros.common.widget;

public class ENut
{


	public static final short E_NUT_STATE_SCREWED_OFF			= 0;
	public static final short E_NUT_STATE_SCREWED_ON			= 1;
	public static final short E_NUT_STATE_TOTALLY_SCREWED_UP		= -1;

	public short m_currState = E_NUT_STATE_SCREWED_OFF;

	public ENut() 
	{
	}

	public ENut(int p_state) 
	{
		m_currState = p_state;

	}
}