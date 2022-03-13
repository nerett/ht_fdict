#include "ht_fdict.h"
#include "ht_fdict_config.h"
#include <string.h>


/*--------------------------FUNCTION-----------------------------------------*/
CFDictionary::CFDictionary():
	size_ ( 100 ),
	hashtable_ ( new CList[size_] ) //создание массива списков
{

}


/*--------------------------FUNCTION-----------------------------------------*/
CFDictionary::~CFDictionary()
{
	delete hashtable_;
}


/*--------------------------FUNCTION-----------------------------------------*/
int CFDictionary::addword( const char* word )
{
	/*
		1) вычисление хеша
		2) вычисление положения по хешу (т.е. поиск)
		3) поиск совпадений в списках
		4) добавление слова/увеличение счётчика
	*/

	unsigned long long wordhash = calchash( word );
	CList* arrpos = findbyhash( wordhash ); //вычисляет индекс а по нему уже саму цепочку и возвращает указатель на сам список
	CListElem* listpos = findbyname( word );

	if( listpos ) //переименовать в sequence и т.п.
	{
		listpos->frequency_++;
	}
	else
	{
		listpos = arrpos->insert_back( word );
	}

	return listpos->frequency_;
}


/*--------------------------FUNCTION-----------------------------------------*/
int CFDictionary::rmword()
{
	return 0;
}


/*--------------------------FUNCTION-----------------------------------------*/
int CFDictionary::getfreq()
{
	return 0;
}


/*--------------------------FUNCTION-----------------------------------------*/
unsigned long long CFDictionary::calchash( const char* word )
{
	int size = strlen( word );

	return xor_hash( word, size );
}


/*--------------------------FUNCTION-----------------------------------------*/
CList* CFDictionary::findbyhash( unsigned long long wordhash ) //вычисляет индекс а по нему уже саму цепочку и возвращает указатель на сам список
{
	return &( hashtable_[wordhash % size_] );
}


/*--------------------------FUNCTION-----------------------------------------*/
CListElem* CFDictionary::findbyname( const char* word )
{
	return NULL;
}