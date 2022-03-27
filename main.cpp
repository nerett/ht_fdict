#include "ht_fdict.h"
#include "ht_fdict_io.h"
//#include <string.h>

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
		printf( "read symbols %d\n", scanf( "%ms[a-zA-Zа-яА-Я]", &searchword ) ); //!TODO константа для формата

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