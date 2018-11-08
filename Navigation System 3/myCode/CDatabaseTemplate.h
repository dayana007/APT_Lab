/*
 * CDatabaseTemplate.h
 *
 *  Created on: 5 Jan 2017
 *      Author: dayan
 */

#ifndef CDATABASETEMPLATE_H_
#define CDATABASETEMPLATE_H_

#include <iostream>
#include <map>
#include <string.h>
#include <list>
#include "CWaypoint.h"

using namespace std;

/*
T1 - type for Key( can be string or integer supported by the map  )
T2 - type for value( can be any user defined type )
*/


template<class T1, class T2>

class CDatabaseTemplate
{
protected:
	map<T1, T2> mapDataTemplate;
    static int objects_Created;

public:
	CDatabaseTemplate();
    void add( T1 key, T2 val );
    T2* getPointerToObj( T1 key );
    bool clearDatabase();
    //void traverseDatabase( list<T2>& refToListOfObj )const;
    bool traverseDatabase( list<T2>& refToListOfObj )const;
    void print();
    int getAliveObjectCount();
    int getCreatedObjectCount();
    ~CDatabaseTemplate();
};

template<class T1, class T2>
int CDatabaseTemplate<T1,T2>::objects_Created = 0;


template<class T1, class T2>
CDatabaseTemplate<T1,T2>::CDatabaseTemplate()
{
	objects_Created++;

}

template<class T1, class T2>
CDatabaseTemplate<T1,T2>::~CDatabaseTemplate()
{

}

template<class T1, class T2>
void CDatabaseTemplate<T1,T2>::add(T1 key, T2 value)
{
	mapDataTemplate.insert( pair<T1, T2>(key, value));
}

template<class T1, class T2>
void CDatabaseTemplate<T1,T2>::print()
{
	typename map< T1, T2 >::iterator Itr;

	Itr = mapDataTemplate.begin();
	while(Itr != mapDataTemplate.end())
	{
		/* Print added way points */
		cout <<Itr->first<<endl;
		Itr->second.print(MMSS);;
		Itr++;
	}

}

template<class T1, class T2>
T2* CDatabaseTemplate<T1,T2>::getPointerToObj( T1 key )
{
    typename map<T1, T2>::iterator Itr;

    bool flag = 0;
	for(Itr = mapDataTemplate.begin(); Itr != mapDataTemplate.end(); ++Itr)
	{
		if(Itr->first == key )
		{
			flag = 1;
			break;
		}
		else
		{

		}
	}

	if(flag == 0)
	{
		return NULL;
	}
	else
	{
		return &(Itr->second);
	}
}

template<class T1, class T2>
bool CDatabaseTemplate<T1,T2>::clearDatabase()
{
	mapDataTemplate.clear();
	return mapDataTemplate.empty();
}

//template<class T1, class T2>
//void CDatabaseTemplate<T1,T2>::traverseDatabase(list<T2>& refToListOfObj)const
//{
//	typename map< T1, T2 >::const_iterator Itr;
//
//	Itr = mapDataTemplate.begin();
//	while(Itr != mapDataTemplate.end())
//	{
//		refToListOfObj.push_back(Itr->second);
//		Itr++;
//	}
//
//}
template<class T1, class T2>
bool CDatabaseTemplate<T1,T2>::traverseDatabase(list<T2>& refToListOfObj)const
{
	typename map< T1, T2 >::const_iterator Itr;
	if(mapDataTemplate.empty())
	{
		cout<<"Database is empty, writing is not possible"<<endl;
		return false;
	}
	else
	{


		Itr = mapDataTemplate.begin();
		while(Itr != mapDataTemplate.end())
		{
			refToListOfObj.push_back(Itr->second);
			Itr++;
		}
		return true;
	}
}
template<class T1, class T2>
int CDatabaseTemplate<T1,T2>::getCreatedObjectCount()
{
	return objects_Created;
}

#endif /* CDATABASETEMPLATE_H_ */
