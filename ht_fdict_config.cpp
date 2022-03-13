#include "ht_fdict_config.h"


/*--------------------------FUNCTION-----------------------------------------*/
unsigned long long xor_hash( const xor_data_t* data, int size )
{
	unsigned long long hash = HASH_KEY;

	for( int i = 0; i < size; size++ )
	{
		hash = hash ^ ( unsigned long long )data[i];
	}


	return hash;
}