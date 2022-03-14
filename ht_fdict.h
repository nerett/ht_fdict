#ifndef HT_FDICT_H_INCLUDED
#define HT_FDICT_H_INCLUDED


#include "../cpp_list/cpp_list.h"
#include "ht_fdict_config.h"
#include <stdlib.h>
#include <stdio.h>


/*--------------------------CLASS-----------------------------------------*/
class CFDictionary
{
	private:

		int size_;
		CList* hashtable_; //указатель на массив указателей на списки

	private:

		unsigned long long calchash( const char* word );
		CList* findbyhash( hash_t wordhash ); //вычисляет индекс а по нему уже саму цепочку и возвращает указатель на сам список
		CListElem* findbyname( const CList* wordsequence, const char* word );
		CListElem* calcpos( const char* word, CListElem** listpos, CList** arrpos = NULL );

	public:

		explicit CFDictionary();
		~CFDictionary();

		int addword( const char* word );
		int rmword( const char* word );

		int getfreq( const char* word );

};


#endif //HT_FDICT_H_INCLUDED