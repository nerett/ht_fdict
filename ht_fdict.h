#ifndef HT_FDICT_H_INCLUDED
#define HT_FDICT_H_INCLUDED


#include "../cpp_list/cpp_list.h"
#include <stdlib.h>
#include <stdio.h>


/*--------------------------CLASS-----------------------------------------*/
class CFDictionary
{
	private:

		int size_;
		CList* hashtable_; //указатель на массив указателей на списки

	private:

		unsigned long long calchash();

	public:

		explicit CFDictionary();
		~CFDictionary();

		int addword( const char* word );
		int rmword();

		int getfreq();

};


#endif //HT_FDICT_H_INCLUDED