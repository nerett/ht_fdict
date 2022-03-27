#ifndef HT_FDICT_CONFIG_H_INCLUDED
#define HT_FDICT_CONFIG_H_INCLUDED


/*--------------------------DEFINE--------------------------------------------*/
#define CYRILLIC_ALPHABET "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"
#define LATIN_ALPHABET "a-zA-Z"


/*--------------------------TYPEDEF-------------------------------------------*/
typedef char xor_data_t;
typedef unsigned long long hash_t;


/*--------------------------CONST---------------------------------------------*/
/*
const char* SKIP_SYMBOLS_FORMAT = "%*[^" LATIN_ALPHABET CYRILLIC_ALPHABET "]";
const char* COUNT_READ_SYMBOLS_FORMAT = "%[" LATIN_ALPHABET CYRILLIC_ALPHABET "]%n";
const char* MEM_READ_SYMBOLS_FORMAT = "%ms[" LATIN_ALPHABET CYRILLIC_ALPHABET "]";
*/

const hash_t HASH_KEY = 0xAB0BAB0BAB0BAB0B;
const int DEFAULT_HASHTABLE_SIZE = 100; //!TODO установить значение в 50 000 - 100 000 или сделать этот параметр динамическим


/*--------------------------PROTOTYPE-------------------------------------------*/
hash_t xor_hash( const xor_data_t* data, int size );


#endif //HT_FDICT_CONFIG_H_INCLUDED