#ifndef HT_DICT_CONFIG_H_INCLUDED
#define HT_DICT_CONFIG_H_INCLUDED


/*--------------------------CONST---------------------------------------------*/
const unsigned long long HASH_KEY = 0xAB0BAB0BAB0BAB0B;
const int DEFAULT_HASHTABLE_SIZE = 100; //!TODO установить значение в 50 000 - 100 000


/*--------------------------TYPEDEF-------------------------------------------*/
typedef char xor_data_t;


/*--------------------------PROTOTYPE-------------------------------------------*/
unsigned long long xor_hash( const xor_data_t* data, int size );


#endif //HT_DICT_CONFIG_H_INCLUDED