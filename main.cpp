#include "ht_fdict.h"
//#include <cstring>
#include <string>
#include <iostream>

int main( int argc, char** argv )
{
	CFDictionary dictionary;
	char* filename = argv[1];

	dictionary.fill( filename );

	std::string searchword; //выглядит костыльно на фоне C-кода, зато работает везде
	//char* searchword = nullptr;
	while( true )
	{
		printf( "Введите слово для поиска (q - выход)\n" );
		printf( "> " );
		std::cin >> searchword;
		//scanf( "%ms[" LATIN_ALPHABET CYRILLIC_ALPHABET "]", &searchword );

		if( searchword == "q" ) //searchword && !strcmp( searchword, "q" )
		{
			//free( searchword );
			break;
		}

		printf( "Это слово встретилось в тексте %d раз\n", dictionary.getfreq( searchword.c_str() ) );

		//free( searchword );
	}
	
	return 0;
}