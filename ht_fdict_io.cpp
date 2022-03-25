#include "ht_fdict_io.h"


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
	n_entities_ ( 0 )
{

}


/*--------------------------FUNCTION-----------------------------------------*/
CText::~CText()
{
	delete[] textbuf_;
	delete[] entities_;
}


/*--------------------------FUNCTION-----------------------------------------*/
void CText::importfile( const char* filename )
{
	assert( filename );


	FILE* input_file = fopen( filename, "r" );
	assert( input_file ); //костыль

    textbuf_size_ = calc_filesize( input_file );
	textbuf_ = new char[textbuf_size_];

	n_entities_ = textbuf_size_; //костыль
	entities_ = new CWord[n_entities_];


	int readsymbols = 0;
	int buffcursor = 0;
	int filecursor = 0;
	int entitycounter = 0;
	int i = 0;
	while( ftell( input_file ) < textbuf_size_ )//for( i = 0; i < n_entities_; i++ ) //на всякий случай
	{
		readsymbols = fscanf( input_file, "%*[^a-zA-Z]%[a-zA-Z]", &textbuf_[buffcursor] );
printf( "readsymbols = %d\n", readsymbols  );
//printf( "readline = %s\n", textbuf_[lettpos] );

		/*
		if( !readsymbols )
		{
			break;
		}
		*/

		buffcursor += readsymbols;
		entities_[entitycounter].word_ = &textbuf_[buffcursor];
		entities_[entitycounter].length_ = readsymbols;

		filecursor++;
		entitycounter++;
		i++;
	}

	n_entities_ = i;

	/*
    textbuf_ = new char*[textbuf_size_];
	fread( textbuf_, sizeof( char ), textbuf_size_, input_file );

    count_strings();
	entities_ = new char*[n_entities_]
    //some_text->index_string = ( char** ) calloc( some_text->N_strings, sizeof( char* ) ); //выделение памяти под массив указателей на начало строк

    find_string_beginning();
	*/

    fclose( input_file );
}


/*--------------------------FUNCTION-----------------------------------------*/
int CText::calc_filesize( FILE* const some_file )
{
	fseek( some_file, 0L, SEEK_END ); //определение размера файл
    int filesize = ftell( some_file );
	fseek( some_file, 0L, SEEK_SET );

	return filesize;
}