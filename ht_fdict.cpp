#include "ht_fdict.h"


/*--------------------------FUNCTION-----------------------------------------*/
CFDictionary::CFDictionary():
	size_ ( 0 )
	hashtable_ ( new CList[size_] ) //создание массива списков
{

}


/*--------------------------FUNCTION-----------------------------------------*/
CFDictionary::~CFDictionary()
{
	delete hashtable_;
}


/*--------------------------FUNCTION-----------------------------------------*/
int addword( const char* word )
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
		listpos->counter++;
	}
	else
	{
		arrpos->insert_back( word );
	}


}


/*--------------------------FUNCTION-----------------------------------------*/
int rmword()
{

}


/*--------------------------FUNCTION-----------------------------------------*/
int getfreq()
{

}