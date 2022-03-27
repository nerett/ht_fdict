DEPENDENCIES = https://github.com/nerett/cpp_list.git


ifeq ($(MODE), DEBUG)
	DEBUGFLAGS = -fsanitize=address -Wall -Wextra -g
	EXECDIR = Release/
else
	RELEASEFLAGS = -D NDEBUG
	EXECDIR = Debug/
endif

CC = g++
CFLAGS = -c $(DEBUGFLAGS) $(RELEASEFLAGS)
LDFLAGS = $(DEBUGFLAGS) $(RELEASEFLAGS)
BUILDDIR = Build/
CPPLISTDIR = ../cpp_list/

EXECNAME = ht_fdict


ifndef TEXT
	TEXT = Testfiles/testfile.txt
endif


#----------------------------------BUILDING--------------------------------------------------
all: mkdir main
	$(CC) $(LDFLAGS) $(BUILDDIR)main.o $(BUILDDIR)libht_fdict.o $(BUILDDIR)libht_fdict_config.o $(BUILDDIR)libht_fdict_io.o $(BUILDDIR)libcpp_list.o -o $(EXECDIR)$(EXECNAME)
	
mkdir:
	mkdir -p Debug/ Release/ Build/
	
main: libht_fdict libht_fdict_io
	$(CC) $(CFLAGS) main.cpp -o $(BUILDDIR)main.o


#----------------------------------libht_fdict-----------------------------------------------
libht_fdict: libcpp_list libht_fdict_config
	$(CC) $(CFLAGS) ht_fdict.cpp -o $(BUILDDIR)libht_fdict.o


#----------------------------------libht_fdict_config----------------------------------------
libht_fdict_config:
	$(CC) $(CFLAGS) ht_fdict_config.cpp -o $(BUILDDIR)libht_fdict_config.o


#----------------------------------libht_fdict_io--------------------------------------------
libht_fdict_io:
	$(CC) $(CFLAGS) ht_fdict_io.cpp -o $(BUILDDIR)libht_fdict_io.o


#----------------------------------libcpp_list-----------------------------------------------
libcpp_list:
	$(CC) $(CFLAGS) $(CPPLISTDIR)cpp_list.cpp -o $(BUILDDIR)libcpp_list.o


#----------------------------------INSTALLING DEPENDENCIES-----------------------------------
install-dependencies:
	cd .. && git clone $(DEPENDENCIES)


#----------------------------------CONFIGURATION---------------------------------------------
config:
	cd ../cpp_list && git checkout string+counter_mode


#----------------------------------RUNNING---------------------------------------------------
run:
	./$(EXECDIR)$(EXECNAME) $(TEXT)

rund:
	valgrind --leak-check=full ./$(EXECDIR)$(EXECNAME) $(TEXT)


#-----------------------------------CLEANING-------------------------------------------------
clean:
	rm -rf Debug/ Release/ Build/
