#ifndef HT_FDICT_IO_H_INCLUDED
#define HT_FDICT_IO_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*--------------------------CLASS-----------------------------------------*/
class CWord
{
	public:

		char* word_;
		int length_;

	public:

		explicit CWord();
		~CWord();
};


/*--------------------------CLASS-----------------------------------------*/
class CText
{
	public: //костыль

		char* textbuf_;
		int textbuf_size_;

		CWord* entities_;
		int max_entity_;

	private:

		static int calc_filesize( FILE* const some_file );

	public:

		explicit CText();
		~CText();

		void importfile( const char* filename );
};


#endif //HT_FDICT_IO_H_INCLUDED