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
void CText::importfile( const char* filename )
{
	assert( filename );


	FILE* input_file = fopen( filename, "r" );
	assert( input_file ); //костыль

    textbuf_size_ = calc_filesize( input_file ); //костыль
	textbuf_ = new char[textbuf_size_] {}; //{0}; //*10

	//n_entities_ = textbuf_size_; //костыль
	entities_ = new CWord[textbuf_size_]; //костыль


	int readsymbols = 0;
	int buffcursor = 0;


printf( "default max_entity = %d\n", max_entity_ );
printf( "textbuff_size = %d\n", textbuf_size_ );
printf( "\n" );


	while( ftell( input_file ) < textbuf_size_ )
	{
		readsymbols = 0;

		fscanf( input_file, "%*[^a-zA-Z]" );
		fprintf( stderr, "fscanf = %d\n", fscanf( input_file, "%[a-zA-Z]%n", &textbuf_[buffcursor], &readsymbols ) );

		if( !readsymbols )
		{
			//return;
		}

		readsymbols++;
		max_entity_++;

fprintf( stderr, "readsymbols = %d\n", readsymbols );
fprintf( stderr, "max_entities_ = %d\n", max_entity_ );
fprintf( stderr, "buffcursor = %d\n", buffcursor );
fprintf( stderr, "readline first symbol = %c\n", textbuf_[buffcursor] );
fprintf( stderr, "readline = %s\n", &textbuf_[buffcursor] );
fprintf( stderr, "\n" );
/*
printf( "readsymbols = %d\n", readsymbols );
printf( "max_entities_ = %d\n", max_entity_ );
printf( "readline = %s\n", &textbuf_[buffcursor] );
printf( "buffcursor = %d\n", buffcursor );
printf( "\n" );
*/

		//fflush( stdout );
		//readsymbols++;

		entities_[max_entity_].word_ = &textbuf_[buffcursor];
		entities_[max_entity_].length_ = readsymbols;

		buffcursor += readsymbols;
	}

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