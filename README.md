# HT_FDict
This frequency dictionary based on hashtable aims at studiyng the frequency of occurrence of certain words in books written by Petrovich and other respectable MIPT professors.

## Usage
Run this program with `./ht_fdict <filename>` (if you haven't done any changes to the Makefile) from the `Release/` or `Debug/` depending on how you've built it (also see ***Building from sourse*** section for more information). Or type `make run TEXT=<filename>` (also use `MODE=DEBUG` if you built the program in the `DEBUG` mode; program runs in the `RELEASE` mode by default).

The program will automatically index the file given. Then you'll be asked to enter a word to search in the hashtable. After you enter a word, the program will display this word's frequency. You can search for `q` to exit the program.

## Building from source
#### Downloading
Download this repository with

```bash
git clone https://github.com/nerett/ht_fdict.git
```

#### Installing dependencies
Install dependencies by running (also see ***Dependencies*** section for more information)

```bash
cd ht_fdict/
make install-dependencies
```

#### Configuring
Configure with

```bash
make config
```

#### Building
Build the project with

```bash
make MODE=<modename> HASHFUNC=<hashfuncname>
```

There are 2 modes available: `DEBUG` and `RELEASE`. The project builds in `RELEASE` mode by default, so you haven't to use `MODE` option if you want to build the project in the `RELEASE` mode.
There are 3 hash functions available: `XOR`, `SYMCODESUM` and `SYMCODESUMV2`. `SYMCODESUMV2` is set to default (it is called by default in the `calchash` from the `ht_fdict.cpp`), so you don't need to use `HASHFUNC` option if you want to use `SYMCODESUMV2` (moreover, this function is the most efficient among this 3 fuctions, so do not decide to change it without the need).

For exaple, if you want to build the project in the `RELEASE` mode with `SYMCODESUMV2` function, you can simply run `make`.

#### Running
You can run `ht_fdict` with

```bash
make run MODE=<modename> TEXT=<filename>
```

If you choose not to use `TEXT` option, the program will use `Onegin.txt` file from the `Testfiles/` directory.
`MODE` is set to `RELEASE` by default. 

Therefore, if you want to run the program in the `RELEASE` mode with `Onegin.txt` file, simply type

```bash
make run
```

You can also use this target instead to run with `valgrind` (options are the same)

```bash
make rund
```

...or run this binary with (from project root directory)

```bash
./Debug/ht_fdict <filename>
```

Without the `<filename>` given the program will crash/display error message depending on the build `MODE`.

#### Rebuilding
To totally rebuild the project run

```bash
make clean
make MODE=<modename> HASHFUNC=<hashfuncname>
```

## Dependencies
This project actually depends on `cpp_list` from the `https://nerett/cpp_list.git` and `libc` and building requires `make`, `g++` and `git` (it can also require `valgrind` installed to use `rund` target).

#### Automatic method
If you already have `ht_fdict` repo cloned, for many Unix-like oparating systems you can install all this things by running (it is runned with `sudo`, so it requires `sudo` to be installed)

```bash
cd ht_fdict/
make install-dependencies-all PACKAGEMANAGER=<your-package-manager-name>
```

`apt` is set as default `PACKAGEMANAGER`. So, if you want to install full list of dependencies on Debian/Ubuntu-based OS, simply run

```bash
make install-dependencies-all
```

#### Manual method
...or install dependencies manually.
For Debian/Ubuntu-based OS:

```bash
apt install git build-essential valgrind
git clone https://nerett/cpp_list.git
```

For other operating systems check information about packages names and actual package manager used.
If you have already installed all dependencies required, you can now go to the ***Building from source*** section.


## Documentation
This section isn't done yet.

## About project
This programm was written during MIPT **Ded's** cource.
