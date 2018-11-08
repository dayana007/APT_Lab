/*
 * CLifoBuffer.cpp
 *
 *  Created on: 24 Nov 2016
 *      Author: dayan
 */

#include "CLifoBuffer.h"


CLifoBuffer::CLifoBuffer(int size)
{
	m_size = size;
	m_tos = TOS;
	m_pBuffer = new CFraction[m_size];
	cout<<" The size of buffer "<<m_size<<endl;
	cout<< "Top of the stack, stack is empty "<<m_tos<<endl;

}

void CLifoBuffer::print()
{
	cout<<" The size of buffer "<<m_size<<endl;
	cout<< "Stack position "<<m_tos<<endl;
	for(m_tos = 0;m_tos<m_size;m_tos++)
	{
		 m_pBuffer[m_tos].print();
	}
	m_tos += TOS;

}

bool CLifoBuffer::push(const CFraction& data)
{
	bool memoryleft;
	if((m_tos == -1) ||(m_tos<m_size))
	{
		memoryleft = 1;
		m_tos++;
		m_pBuffer[m_tos] = data;

	}
	return memoryleft;
}

bool CLifoBuffer::pop(const CFraction& data)
{
    CFraction value;
    bool popvalue;
	if(m_pBuffer[m_tos] == data)
	{
		popvalue = 1;
		value = m_pBuffer[m_tos];
		m_tos--;

	}
	else
	{
		cout<<"value cannot be popped" <<endl;
	}

	return  popvalue;
}


CLifoBuffer::~CLifoBuffer()
{
	delete[]m_pBuffer;
}

