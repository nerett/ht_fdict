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
	//char searchword[100] = "";

	while( true )
	{
		printf( "Введите слово для поиска\n" );
		printf( "> " );
		printf( "read symbols %d\n", scanf( "%ms[a-zA-Z]", &searchword ) );
		//printf( "\n" );
		printf( "searchword ptr = %p\n", searchword );

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