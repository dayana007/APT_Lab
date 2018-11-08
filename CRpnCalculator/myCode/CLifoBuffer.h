/*
 * CLifoBuffer.h
 *
 *  Created on: 24 Nov 2016
 *      Author: dayan
 */

#ifndef CLIFOBUFFER_H_
#define CLIFOBUFFER_H_

#include "CFraction.h"

#define TOS -1

class CLifoBuffer
{
private:
	int m_size;
	int m_tos;
	CFraction* m_pBuffer;
public:
	CLifoBuffer(int size = 10);
	void print();
	bool push(const CFraction& data);
	bool pop(const CFraction& data);
	virtual ~CLifoBuffer();
};

#endif /* CLIFOBUFFER_H_ */
