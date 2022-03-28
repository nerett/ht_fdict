ifeq ($(MODE), DEBUG)
	DEBUGFLAGS = -fsanitize=address -Wall -Wextra -g
	EXECDIR = Release/
else
	RELEASEFLAGS = -D NDEBUG
	EXECDIR = Debug/
endif

ifeq ($(HASHFUNC), XOR)
	HASHFUNCFLAG = -D XOR_HASH
endif
ifeq ($(HASHFUNC), SYMCODESUM)
	HASHFUNCFLAG = -D SYMCODESUM_HASH
endif
ifeq ($(HASHFUNC), SYMCODESUMV2)
	HASHFUNCFLAG = -D SYMCODESUMV2_HASH
endif

ifndef TEXT
	TEXT = Testfiles/Онегин.txt
endif

ifndef PACKAGEMANAGER
	PACKAGEMANAGER = apt
endif


DEPENDENCIES = https://github.com/nerett/cpp_list.git
PACKAGEDEPENDENCIES = build-essential g++ make valgrind

CC = g++
CFLAGS = -c $(DEBUGFLAGS) $(RELEASEFLAGS) $(HASHFUNCFLAG)
LDFLAGS = $(DEBUGFLAGS) $(RELEASEFLAGS) $(HASHFUNCFLAG)
BUILDDIR = Build/
CPPLISTDIR = ../cpp_list/

EXECNAME = ht_fdict


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

install-dependencies-all: install-dependencies
	sudo $(PACKAGEMANAGER) install $(PACKAGEDEPENDENCIES)


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
