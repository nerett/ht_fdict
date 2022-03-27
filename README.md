# HT_FDict
This frequency dictionary based on hashtable aims at studiyng the frequency of occurrence of certain words in books written by Petrovich and other respectable MIPT professors.

## Usage
Run this program with `./ht_fdict <filename>` (if you haven't done any changes to the Makefile) from the `Release/` or `Debug/` depending on how you've built it (also see *Building from sourse* section for more information). Or type `make run TEXT=<filename>` (also use `MODE=DEBUG` if you built the program in the `DEBUG` mode; programs runs in the `RELEASE` mode by default).
The program will automatically index the file given. Then you'll be asked to enter a word to search in the hashtable. After you enter a word, the program will display this word's frequency. You can search for `q` to exit program.

## Building from source
Download this repository with

```
git clone https://github.com/nerett/ht_fdict.git
```

Install dependencies by running

```
cd ht_fdict/
make install-dependencies
```

Configure with

```
make config
```

Build the project with

```
make MODE=<modename>
```

There are 2 modes available: `DEBUG` and `RELEASE`. The project builds in `RELEASE` mode by default, so you haven't to use `MODE` option if you want to build the project in the `RELEASE` mode (in this case simply type `make`).

You can run `ht_fdict` with

```
make run MODE=<modename> TEXT=<filename>
```

If you choose not to use `TEXT` option, the program will use `Onegin.txt` file from the `Testfiles/` directory.
`MODE` is set to `RELEASE` by default. Therefore, if you want to run the program in the `RELEASE` mode with `Onegin.txt` file, simply type `make run`.
You can also use `make rund` instead to run with `valgrind`. Options are the same.

You can also run this binary with (from project root directory)

```
./Debug/ht_fdict <filename>
```

Without the `<filename>` given the program will crash/display error message depending on the build `MODE`.

To totally rebuild the project run

```
make clean
make MODE=<modename>
```

## Documentation
This section isn't done yet.

## About project
This programm was written during MIPT **Ded's** cource.
