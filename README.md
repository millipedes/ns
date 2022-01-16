# :strawberry: rasberry Programming Language
## :dart: Project Description/Goal
rasberry is meant to be a fast relatively powerful programming language.  By
May 2022 it should have a fully functional stocastic process library natively.
Currently it is interpreted, but soon I will likely write an assembly
translation for GNU assembler.

## :floppy_disk: Installation
The program depends on the following:
- gcc
- gnu make (fyi just `make` for people on 99% of distros)
- sudo

The current installation process will put a binary called `millipedes-rbi`
(millipedes rasberry interpreter) in your /usr/bin/ directory (where bash looks
for binaries, i.e. can be called from command line with millipedes-nsi).  This
can be achieved via:
```
    $ git clone https://github.com/millipedes/rasberry.git
    $ cd rasberry
    $ mkdir bin/
    $ sudo make install
```

## :star2: Currently Offered Features
This language uses [RPN](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
notation.

This language now has variable support for integers and the type known as a data
frame.  I am writing a manual for the programming language, and when it is ready,
I will link it here for a better description of language features such as the data
frame.

The entire code base is memory leakless and error free for the grammar defined
below.  Many more features are coming quickly as the basic infrastructure of 
the language is now written.

The programming language has a working symbol table (i.e. complete stack frame
functionality for integers, and data frames but no entry point to making new
stack frames yet).

As it currently stands, the language will very likely have lazy evaluation.

As it is currently written, this language supports the following context free
grammar (BNF-like notation) for which all operators only perform on like expr's:
```
expr        -> + expr expr
             | - expr expr
             | * expr expr
             | / expr expr
             | ^ expr expr
             | (expr)
             | > expr expr
             | < expr expr
             | >= expr expr
             | <= expr expr
             | == expr expr
             | != expr expr
             | = var expr
             | var
             | integer
             | data_frame
             | string
             | float

var         -> integer
             | float
             | string
             | data frame

string      -> "(a-z || A-Z || 0-9 || symbol)*"

data frame  -> [(var)*]

float       -> x such that x is a signed 32 bit double precision floating point number

integer     -> x such that x is an element of integers (32 bit signed)
```

## :scroll: Immediately on the List to be Implemented
1) Write integer data frame operators
2) Reserve `exit`/remove console.c nonsense
3) float type support
4) float_matrix type support
5) string type support
6) string_matrix support
7) matrx_matrix support
8) Implement if, while, for
8) Implement stack frames
9) Implement functions
10) Implement function entry point (i.e. make main reserved)
11) Implment Module support
12) Implement File I/O support
13) Command Line Arguements/REPL UI improvement
14) MAYBE Infix function notation
15) MAYBE Assembly translation for GAS 
