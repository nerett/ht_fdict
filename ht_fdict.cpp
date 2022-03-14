#include "ht_fdict.h"
//#include "ht_fdict_config.h"
#include <string.h>


/*--------------------------FUNCTION-----------------------------------------*/
CFDictionary::CFDictionary():
	size_ ( DEFAULT_HASHTABLE_SIZE ),
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

	/* #call example#

		frequency = func( word, &arrpos, &listpos );

	*/

	CListElem* listpos = NULL;
	CList* arrpos = NULL;

	if( calcpos( word, &listpos, &arrpos ) ) //переименовать в sequence и т.п.
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
int CFDictionary::rmword( const char* word ) //!TODO добавить удаление по ID и т.п.
{
	CListElem* listpos = NULL;
	int frequency_ = 0;

	if( calcpos( word, &listpos ) )
	{
		frequency_ =  listpos->frequency_;
		listpos->pop();
	}

	return frequency_;
}


/*--------------------------FUNCTION-----------------------------------------*/
int CFDictionary::getfreq( const char* word )
{
	CListElem* listpos = NULL;
	int frequency_ = 0;

	if( calcpos( word, &listpos ) )
	{
		frequency_ = listpos->frequency_;
	}

	return frequency_;
}


/*--------------------------FUNCTION-----------------------------------------*/
hash_t CFDictionary::calchash( const char* word )
{
	int size = strlen( word );

	return xor_hash( word, size );
}


/*--------------------------FUNCTION-----------------------------------------*/
CList* CFDictionary::findbyhash( hash_t wordhash ) //вычисляет индекс а по нему уже саму цепочку и возвращает указатель на сам список
{
	return &( hashtable_[wordhash % size_] );
}


/*--------------------------FUNCTION-----------------------------------------*/
CListElem* CFDictionary::findbyname( const CList* wordsequence, const char* word )
{
	CListElem* current_elem = wordsequence->fictional();

	while( current_elem && ( current_elem->next_ != current_elem ) )
	{
		if( !strcmp( word, current_elem->word_ ) )
		{
			return current_elem;
		}
		current_elem = current_elem->next_;
	}

	return NULL;
}


/*--------------------------FUNCTION-----------------------------------------*/
CListElem* CFDictionary::calcpos( const char* word, CListElem** listpos, CList** arrpos )
{
	hash_t wordhash = calchash( word );
	CList* calcd_arrpos = findbyhash( wordhash );
	CListElem* calcd_listpos = findbyname( calcd_arrpos, word );

	*listpos = calcd_listpos;
	if( arrpos )
	{
		*arrpos = calcd_arrpos;
	}

	return calcd_listpos;
}