#include <cassert>
#include <cstring>
#include <cstdio>
#include "ht_fdict_io.h"
#include "ht_fdict_config.h"


/*--------------------------FUNCTION-----------------------------------------*/
CWord::CWord():
	word_ ( nullptr ),
	length_ ( 0 )
{

}


/*--------------------------FUNCTION-----------------------------------------*/
CWord::~CWord()
{

}


/*--------------------------FUNCTION-----------------------------------------*/
CText::CText():
	textbuf_ ( nullptr ),
	textbuf_size_ ( 0 ),
	entities_ ( nullptr ),
	max_entity_ ( -1 )
{

}


/*--------------------------FUNCTION-----------------------------------------*/
CText::~CText()
{
	delete[] textbuf_;
	delete[] entities_;
}


/*--------------------------FUNCTION-----------------------------------------*/
void CText::importfile( const char* filename ) //!TODO int
{
	assert( filename );


	FILE* input_file = fopen( filename, "r" );
	assert( input_file ); //только дебаг
	if( !input_file )
	{
		fprintf( stderr, "No input file!\n" ); //!TODO нормальная обработка ошибок
		return;
	}


    textbuf_size_ = calc_filesize( input_file ); //повышенный расход памяти
	textbuf_ = new char[textbuf_size_] {};

	entities_ = new CWord[textbuf_size_];


	int readsymbols = 0;
	int buffcursor = 0;

	#ifndef NDEBUG
		fprintf( stderr, "[importfile]default max_entity = %d\n", max_entity_ );
		fprintf( stderr, "[importfile]textbuff_size = %d\n\n", textbuf_size_ );
	#endif

	while( ftell( input_file ) < textbuf_size_ )
	{
		readsymbols = 0;

		fscanf( input_file, "%*[^" LATIN_ALPHABET CYRILLIC_ALPHABET "]" ); //!TODO изменение размера буфера fscanf

		#ifndef NDEBUG
			fprintf( stderr, "[importfile]fscanf = %d\n", fscanf( input_file, "%[" LATIN_ALPHABET CYRILLIC_ALPHABET "]%n", &textbuf_[buffcursor], &readsymbols ) );
		#endif
		#ifdef NDEBUG
			fscanf( input_file, "%[" LATIN_ALPHABET CYRILLIC_ALPHABET "]%n", &textbuf_[buffcursor], &readsymbols );
		#endif

		/*
		if( !readsymbols ) //избавляет от последнего пустого слова, но уменьшает удобство распечатки
		{
			return;
		}
		*/

		readsymbols++;
		max_entity_++;

		#ifndef NDEBUG
			fprintf( stderr, "[importfile]readsymbols = %d\n", readsymbols );
			fprintf( stderr, "[importfile]max_entities_ = %d\n", max_entity_ );
			fprintf( stderr, "[importfile]buffcursor = %d\n", buffcursor );
			fprintf( stderr, "[importfile]readline first symbol = %c\n", textbuf_[buffcursor] );
			fprintf( stderr, "[importfile]readline = %s\n\n", &textbuf_[buffcursor] );
		#endif

		entities_[max_entity_].word_ = &textbuf_[buffcursor];
		entities_[max_entity_].length_ = readsymbols;

		buffcursor += readsymbols;
	}

    fclose( input_file );
	autorealloc();
}


/*--------------------------FUNCTION-----------------------------------------*/
int CText::calc_filesize( FILE* const some_file )
{
	fseek( some_file, 0L, SEEK_END );
    int filesize = ftell( some_file );
	fseek( some_file, 0L, SEEK_SET );

	return filesize;
}


/*--------------------------FUNCTION-----------------------------------------*/
void CText::autorealloc() //!TODO int
{
	realloc_entities();
	//realloc_textbuf(); //нельзя так просто использовать, т.к. сбиваются указатели
}


/*--------------------------FUNCTION-----------------------------------------*/
void CText::realloc_entities() //!TODO int
{
	CWord* realloc_buffer = new CWord[max_entity_ + 1];
	memcpy( ( char* )realloc_buffer, ( char* )entities_, sizeof( CWord ) * ( max_entity_ + 1 ) ); //!TODO создать константу
	delete[] entities_;
	entities_ = realloc_buffer;
}


/*--------------------------FUNCTION-----------------------------------------*/
void CText::realloc_textbuf() //!TODO int
{
	char* realloc_buffer = new char[max_entity_] {};
	memcpy( realloc_buffer, textbuf_, textbuf_size_); //!TODO создать константу
	delete[] textbuf_;
	textbuf_ = realloc_buffer;
}


/*--------------------------FUNCTION-----------------------------------------*/
CWord* const CText::get_entity( int position )
{
	if( position < 0 || position > max_entity_ ) //ускорение с точки зрения предсказания ветвления
	{
		return nullptr;
	}

	return entities_ + position;
}


/*--------------------------FUNCTION-----------------------------------------*/
int CText::get_max_n()
{
	return max_entity_;
}