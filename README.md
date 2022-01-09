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
    $ git clone https://github.com/millipedes/ns.git
    $ cd ns
    $ mkdir bin/
    $ sudo make install
```

## :star2: Currently Offered Features
As of January 7 2022 this is a very complicated [RPN](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
calculator.

However the entire code base is memory leakless for all of the calculator
operations.  Many more features are coming quickly as the basic infrastructure
of the language is now written.

As it is currently written, this language supports the following context free
grammar (BNF-like notation):
```
    expr    -> + expr expr
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
            | = expr expr
            | integer

    integer -> x such that x is an element of integers (32 bit signed)
```

## :scroll: Immediately on the List to be Implemented
1) Get assignment operator working
2) Fix TOKEN_WORD/add NODE_WORD
3) Print value of valid word
4) Error on invalid word
5) Error on assignment of invalid type
6) Array/matrix support
7) Implement type float
8) Implement type string
9) implement type function
10) Implement if, while, for
11) Implement Stack Frames
12) Implement File support
13) Implment Module support
14) Command Line Arguements/REPL UI improvement
15) MAYBE Infix function notation
16) MAYBE Assembly translation for GAS 
