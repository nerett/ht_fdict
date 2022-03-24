#include "ht_fdict.h"
//#include <string.h>

int main()
{
	//strdup( NULL );
	CFDictionary test_dictionary;
	test_dictionary.addword( "cat" );
	printf( "added cat\n\n" );
	test_dictionary.addword( "mouse" );
	printf( "added mouse\n\n" );
	test_dictionary.addword( "bat" );
	printf( "added bat\n\n" );
	test_dictionary.addword( "zebra" );
	printf( "added zebra\n\n" );
	test_dictionary.addword( "lion" );
	printf( "added lion\n\n" );
	test_dictionary.addword( "tiger" );
	printf( "added tiger\n\n" );


	return 0;
}