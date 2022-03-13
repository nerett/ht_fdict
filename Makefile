DEPENDENCIES =

CC = g++
CFLAGS = -c #-fsanitize=address #-Wall -Wextra -g
LDFLAGS = #-fsanitize=address #-Wall -Wextra -g
BUILDDIR = Build/
EXECDIR = Debug/

EXECNAME = ht_fdict


#----------------------------------BUILDING--------------------------------------------------
all: mkdir main
	$(CC) $(LDFLAGS) $(BUILDDIR)main.o $(BUILDDIR)libht_fdict.o $(BUILDDIR)libht_fdict_io.o -o $(EXECDIR)$(EXECNAME)
	
mkdir:
	mkdir -p Build Debug
	
main: libht_fdict libht_fdict_io
	$(CC) $(CFLAGS) main.cpp -o $(BUILDDIR)main.o


#----------------------------------libht_fdict-----------------------------------------------
libht_fdict:
	$(CC) $(CFLAGS) ht_fdict.cpp -o $(BUILDDIR)libht_fdict.o


	
#----------------------------------libht_fdict_io--------------------------------------------
libht_fdict_io:
	$(CC) $(CFLAGS) ht_fdict_io.cpp -o $(BUILDDIR)libht_fdict_io.o

	
	
#----------------------------------INSTALLING DEPENDENCIES-----------------------------------
install-dependencies:
	cd .. && git clone $(DEPENDENCIES)


#----------------------------------CONFIGURATION---------------------------------------------
config:
	cd cpp_list && git checkout string+counter_mode


#----------------------------------RUNNING---------------------------------------------------
run:
	./$(EXECDIR)$(EXECNAME) $(CPUCODEPATH)

rund:
	valgrind ./$(EXECDIR)$(EXECNAME)


#-----------------------------------CLEANING-------------------------------------------------
clean:
	rm -rf $(BUILDDIR) $(EXECDIR)
