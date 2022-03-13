#ifndef HT_DICT_CONFIG_H_INCLUDED
#define HT_DICT_CONFIG_H_INCLUDED


const unsigned long long HASH_KEY = 0xAB0BAB0BAB0BAB0B;
typedef char xor_data_t;


unsigned long long xor_hash( const xor_data_t* data, int size );


#endif //HT_DICT_CONFIG_H_INCLUDED