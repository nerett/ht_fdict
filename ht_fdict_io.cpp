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

    textbuf_size_ = calc_filesize( input_file );
	textbuf_ = new char[textbuf_size_];

	//n_entities_ = textbuf_size_; //костыль
	entities_ = new CWord[textbuf_size_]; //костыль


	int readsymbols = 0;
	int buffcursor = 0;
	int filecursor = 0;
	int entitycounter = 0;
	int i = 0;
printf( "default max_entity = %d\n", max_entity_ );
	while( ftell( input_file ) < textbuf_size_ )//for( i = 0; i < n_entities_; i++ ) //на всякий случай
	{
		//readsymbols = 
		fscanf( input_file, "%*[^a-zA-Z]%[a-zA-Z]%n", &textbuf_[buffcursor], &readsymbols );
printf( "readsymbols = %d\n", readsymbols );
		max_entity_++;
//printf( "readline = %s\n", textbuf_[lettpos] );

		buffcursor += readsymbols;
		entities_[max_entity_].word_ = &textbuf_[buffcursor];
		entities_[max_entity_].length_ = readsymbols;

		//filecursor++;
		//entitycounter++;
		//i++;
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