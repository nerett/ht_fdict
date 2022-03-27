#include <cstring>
#include <cstdio>
#include "ht_fdict.h"
//#include "ht_fdict_config.h"
#include "ht_fdict_io.h"


/*--------------------------FUNCTION-----------------------------------------*/
CFDictionary::CFDictionary():
	size_ ( DEFAULT_HASHTABLE_SIZE ),
	hashtable_ ( new CList[size_] ) //создание массива списков
{

}


/*--------------------------FUNCTION-----------------------------------------*/
CFDictionary::~CFDictionary()
{
	delete[] hashtable_;
}


/*--------------------------FUNCTION-----------------------------------------*/
int CFDictionary::addword( const char* word, int size )
{
	assert( word );
	/*
		1) вычисление хеша
		2) вычисление положения по хешу (т.е. поиск)
		3) поиск совпадений в списках
		4) добавление слова/увеличение счётчика
	*/

	/* #call example#

		frequency = func( word, &arrpos, &listpos );

	*/

	CListElem* listpos = nullptr;
	CList* arrpos = nullptr;

	if( calcpos( word, size, &listpos, &arrpos ) ) //переименовать в sequence и т.п.
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
	assert( word );


	CListElem* listpos = nullptr;
	int frequency_ = 0;

	if( calcpos( word, NO_LENGTH, &listpos ) )
	{
		frequency_ =  listpos->frequency_;
		listpos->pop();
	}

	return frequency_;
}


/*--------------------------FUNCTION-----------------------------------------*/
void CFDictionary::fill( const char* filename )
{
	assert( filename );

	
	CText text;
	text.importfile( filename );

	//int strlength = 0;
	CWord* current_entity = nullptr;
	int max_entity = text.get_max_n();
	for( int i = 0; i < max_entity; i++ )
	{
		current_entity = text.get_entity(i);
		addword( current_entity->word_, current_entity->length_ );
	}
}


/*--------------------------FUNCTION-----------------------------------------*/
int CFDictionary::getfreq( const char* word )
{
	assert( word );


	CListElem* listpos = nullptr;
	int frequency_ = 0;

	if( calcpos( word, NO_LENGTH, &listpos ) )
	{
		frequency_ = listpos->frequency_;
	}

	return frequency_;
}


/*--------------------------FUNCTION-----------------------------------------*/
hash_t CFDictionary::calchash( const char* word, int size )
{
	assert( word );

	if( !size )
	{
		size = strlen( word );
	}
	//int size = strlen( word ); //!TODO передача длины

	#ifndef NDEBUG
		fprintf( stderr, "[calchash]calculating hash with wordlength = %d\n", size );
	#endif

	#ifdef XOR_HASH
		return xor_hash( word, size );
	#endif
	#ifdef SYMCODESUM_HASH
		return symcodesum_hash( word, size );
	#endif
	
	return symcodesumv2_hash( word, size );
}


/*--------------------------FUNCTION-----------------------------------------*/
CList* CFDictionary::findbyhash( hash_t wordhash ) //вычисляет индекс а по нему уже саму цепочку и возвращает указатель на сам список
{
	return &( hashtable_[wordhash % size_] );
}


/*--------------------------FUNCTION-----------------------------------------*/
CListElem* CFDictionary::findbyname( const CList* wordsequence, const char* word )
{
	assert( wordsequence );
	assert( word );

	#ifndef NDEBUG
		fprintf( stderr, "[findbyname]started findbyname search\n" );
	#endif

	CListElem* current_elem = wordsequence->head();
	//CListElem* tail = wordsequence->tail();
	CListElem* fictional = wordsequence->fictional();

	while( current_elem != fictional )
	{
		#ifndef NDEBUG
			fprintf( stderr, "[findbyname]while iteration\n" );
			fprintf( stderr, "[findbyname]current word = %s\n", current_elem->word_ );
		#endif

		if( !strcmp( word, current_elem->word_ ) )
		{
			return current_elem;
		}
		current_elem = current_elem->next_;
	}
	

	return nullptr;
}


/*--------------------------FUNCTION-----------------------------------------*/
CListElem* CFDictionary::calcpos( const char* word, int size, CListElem** listpos, CList** arrpos )
{
	assert( word );
	assert( listpos );

	#ifndef NDEBUG
		fprintf( stderr, "[calcpos]started pos calculation\n" );
	#endif

	hash_t wordhash = calchash( word, size );

	#ifndef NDEBUG
		fprintf( stderr, "[calcpos]calculated hash = %llu\n", wordhash );
	#endif

	CList* calcd_arrpos = findbyhash( wordhash );
	CListElem* calcd_listpos = findbyname( calcd_arrpos, word );

	*listpos = calcd_listpos;
	if( arrpos )
	{
		*arrpos = calcd_arrpos;
	}

	#ifndef NDEBUG
		fprintf( stderr, "[calcpos]ended pos calculation\n" );
	#endif

	return calcd_listpos;
}