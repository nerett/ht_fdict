#ifndef HT_FDICT_CONFIG_H_INCLUDED
#define HT_FDICT_CONFIG_H_INCLUDED


/*--------------------------TYPEDEF-------------------------------------------*/
typedef char xor_data_t;
typedef unsigned long long hash_t;


/*--------------------------CONST---------------------------------------------*/
const hash_t HASH_KEY = 0xAB0BAB0BAB0BAB0B;
const int DEFAULT_HASHTABLE_SIZE = 100; //!TODO установить значение в 50 000 - 100 000


/*--------------------------PROTOTYPE-------------------------------------------*/
hash_t xor_hash( const xor_data_t* data, int size );


#endif //HT_FDICT_CONFIG_H_INCLUDED