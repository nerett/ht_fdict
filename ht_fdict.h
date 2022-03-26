#ifndef HT_FDICT_H_INCLUDED
#define HT_FDICT_H_INCLUDED


#include "../cpp_list/cpp_list.h"
#include "ht_fdict_config.h"
//#include <stdlib.h>
#include <cstdio>


/*--------------------------CLASS-----------------------------------------*/
class CFDictionary
{
	private:

		int size_;
		CList* hashtable_; //указатель на массив указателей на списки

	public:

		static hash_t calchash( const char* word );

	private:

		CList* findbyhash( hash_t wordhash ); //вычисляет индекс а по нему уже саму цепочку и возвращает указатель на сам список
		CListElem* findbyname( const CList* wordsequence, const char* word );
		CListElem* calcpos( const char* word, CListElem** listpos, CList** arrpos = nullptr );

	public:

		explicit CFDictionary();
		~CFDictionary();

		int addword( const char* word );
		int rmword( const char* word );

		void fill( const char* filename );
		
		int getfreq( const char* word );

};


#endif //HT_FDICT_H_INCLUDED