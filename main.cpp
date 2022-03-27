#include "ht_fdict.h"
//#include "ht_fdict_io.h"
#include <cstring>

int main( int argc, char** argv )
{
	CFDictionary dictionary;
	char* filename = "testfile.txt";

	if( argc > 1 && argv[1] )
	{
		filename = argv[1];
	}

	dictionary.fill( filename );

	char* searchword = nullptr;
	while( true )
	{
		printf( "Введите слово для поиска (q - выход)\n" );
		printf( "> " );
		scanf( "%ms[" LATIN_ALPHABET CYRILLIC_ALPHABET "]", &searchword );

		if( searchword && !strcmp( searchword, "q" ) )
		{
			free( searchword );
			break;
		}

		printf( "Это слово встретилось в тексте %d раз\n", dictionary.getfreq( searchword ) );

		free( searchword );
	}
	
	return 0;
}