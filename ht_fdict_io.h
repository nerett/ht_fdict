#ifndef HT_FDICT_IO_H_INCLUDED
#define HT_FDICT_IO_H_INCLUDED


#include "ht_fdict_config.h"


/*--------------------------CLASS-----------------------------------------*/
class CWord
{
	public: //!TODO protected

		char* word_;
		int length_;

	public:

		explicit CWord();
		~CWord();
};


/*--------------------------CLASS-----------------------------------------*/
class CText
{
	private:

		char* textbuf_;
		int textbuf_size_;

		CWord* entities_;
		int max_entity_;

	private:

		static int calc_filesize( FILE* const some_file );

		void autorealloc();
		void realloc_entities();
		void realloc_textbuf();

	public:

		explicit CText();
		~CText();

		void importfile( const char* filename );
		CWord* const get_entity( int position );
		int get_max_n();

};


#endif //HT_FDICT_IO_H_INCLUDED