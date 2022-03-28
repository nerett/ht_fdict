#ifndef HT_FDICT_CONFIG_H_INCLUDED
#define HT_FDICT_CONFIG_H_INCLUDED


/*--------------------------DEFINE--------------------------------------------*/
#define CYRILLIC_ALPHABET "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
#define LATIN_ALPHABET "a-zA-Z"


/*--------------------------TYPEDEF-------------------------------------------*/
typedef char hash_data_t;
typedef unsigned long long hash_t;


/*--------------------------CONST---------------------------------------------*/
const int NO_LENGTH = 0;

const hash_t HASH_KEY = 0xAB0BAB0BAB0BAB0B;
const int DEFAULT_HASHTABLE_SIZE = 50000;


/*--------------------------PROTOTYPE-------------------------------------------*/
hash_t xor_hash( const hash_data_t* data, int size );
hash_t symcodesum_hash( const hash_data_t* data, int  size );
hash_t symcodesumv2_hash( const hash_data_t* data, int  size );


#endif //HT_FDICT_CONFIG_H_INCLUDED