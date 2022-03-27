DEPENDENCIES = https://github.com/nerett/cpp_list.git

CC = g++
CFLAGS = -c -fsanitize=address -Wall -Wextra -g #-D NDEBUG
LDFLAGS = -fsanitize=address -Wall -Wextra -g #-D NDEBUG
BUILDDIR = Build/
EXECDIR = Debug/
CPPLISTDIR = ../cpp_list/

EXECNAME = ht_fdict


#----------------------------------BUILDING--------------------------------------------------
all: mkdir main
	$(CC) $(LDFLAGS) $(BUILDDIR)main.o $(BUILDDIR)libht_fdict.o $(BUILDDIR)libht_fdict_config.o $(BUILDDIR)libht_fdict_io.o $(BUILDDIR)libcpp_list.o -o $(EXECDIR)$(EXECNAME)
	
mkdir:
	mkdir -p Build Debug
	
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
	./$(EXECDIR)$(EXECNAME) $(CPUCODEPATH)

rund:
	valgrind --leak-check=full ./$(EXECDIR)$(EXECNAME)


#-----------------------------------CLEANING-------------------------------------------------
clean:
	rm -rf $(BUILDDIR) $(EXECDIR)
