
package com.walkerbros.common.widget;

public class EBolt
{


	public static final short E_BOLT_STATE_SCREWED_OFF			= 0;
	public static final short E_BOLT_STATE_SCREWED_ON			= 1;
	public static final short E_BOLT_STATE_TOTALLY_SCREWED_UP		= -1;

	public short m_currState = E_BOLT_STATE_SCREWED_OFF;

	public EBolt() 
	{
	}

	public EBolt(int p_state) 
	{
		m_currState = p_state;

	}
}