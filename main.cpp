#include "ht_fdict.h"
#include "ht_fdict_io.h"
//#include <string.h>

int main()
{
	/*
	CText essay;
	essay.importfile( "testfile.txt" );
	//printf( "filebuf = %s\n", essay.textbuf_ );
	printf( "max_entity_ = %d\n", essay.max_entity_ );
	for( int i = 0; i < essay.max_entity_; i++ )
	{
		printf( "entity №%d %s\n", i, essay.entities_[i].word_ );
	}

	//strdup( NULL );
	int frequency = 0;
	*/

	CFDictionary test_dictionary;

	test_dictionary.fill( "testfile.txt" );
	printf( "Players freq = %d\n", test_dictionary.getfreq( "Players" ) );

	return 0;

	int frequency = 0;

	printf( "cat hash = %llu\n", CFDictionary::calchash( "cat" ) );
	printf( "mouse hash = %llu\n", CFDictionary::calchash( "mouse" ) );
	printf( "bat hash = %llu\n", CFDictionary::calchash( "bat" ) );
	printf( "zebra hash = %llu\n", CFDictionary::calchash( "zebra" ) );
	printf( "lion hash = %llu\n", CFDictionary::calchash( "lion" ) );
	printf( "tiger hash = %llu\n", CFDictionary::calchash( "tiger" ) );
	printf( "cat hash = %llu\n", CFDictionary::calchash( "cat" ) );
	//printf( "testword hash = %llu\n", test_dictionary.calchash( "kjbh,jasbhvasmhgvmjhvgkfgfg" ) );

	printf( "---------------ADD0----------\n" );
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

	printf( "---------------FREQ1----------\n" );
	frequency = test_dictionary.getfreq( "cat" );
	printf( "cat frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "mouse" );
	printf( "mouse frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "bat" );
	printf( "bat frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "zebra" );
	printf( "zebra frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "lion" );
	printf( "lion frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "tiger" );
	printf( "tiger frequency = %d\n\n", frequency );

	//test_dictionary.rmword( "bat" );

	printf( "---------------ADD1----------\n" );
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

	printf( "---------------ADD2----------\n" );
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

	
	printf( "---------------FREQ2----------\n" );
	frequency = test_dictionary.getfreq( "cat" );
	printf( "cat frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "mouse" );
	printf( "mouse frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "bat" );
	printf( "bat frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "zebra" );
	printf( "zebra frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "lion" );
	printf( "lion frequency = %d\n\n", frequency );
	frequency = test_dictionary.getfreq( "tiger" );
	printf( "tiger frequency = %d\n\n", frequency );

	return 0;
}