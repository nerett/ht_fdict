#include "ht_fdict_config.h"


/*--------------------------FUNCTION-----------------------------------------*/
hash_t xor_hash( const xor_data_t* data, int size )
{
	hash_t hash = HASH_KEY;

	for( int i = 0; i < size; i++ )
	{
		hash = hash ^ ( hash_t )data[i];
	}


	return hash;
}