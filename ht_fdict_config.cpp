#include "ht_fdict_config.h"


/*--------------------------FUNCTION-----------------------------------------*/
hash_t xor_hash( const hash_data_t* data, int size )
{
	hash_t hash = HASH_KEY;

	for( int i = 0; i < size; i++ )
	{
		hash = hash ^ ( hash_t )data[i];
	}


	return hash;
}


/*--------------------------FUNCTION-----------------------------------------*/
hash_t symcodesum_hash( const hash_data_t* data, int  size )
{
	hash_t hash = HASH_KEY;

	for( int i = 0; i < size; i++ )
	{
		hash += ( hash_t )data[i];
	}

	return hash;
}


/*--------------------------FUNCTION-----------------------------------------*/
hash_t symcodesumv2_hash( const hash_data_t* data, int  size )
{
	hash_t hash = HASH_KEY;

	for( int i = 0; i < size; i++ )
	{
		hash += ( hash_t )data[i] * ( hash_t )i;
	}

	return hash;
}