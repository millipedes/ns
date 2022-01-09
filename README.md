# :mountain_snow: ns Programming Language
## :dart: Project Description/Goal
ns is meant to be a fast relatively powerful programming language.  By May 2022
it should have a fully functional stocastic process library natively. Currently
it is interpreted, but soon I will likely write an assembly translation for
GNU assembler.

## :floppy_disk: Installation

## :star2: Currently Offered Features
As of January 7 2022 this is a very complicated [RPN](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
calculator.

However the entire code base is memory leakless for all of the calculator
operations.  Many more features are coming quickly as the basic infrastructure
of the language is now written.

As it is currently written, this language supports the following context free
grammar (BNF-like notation):
```
    expr    \\(\rightarrow \\) + expr expr
            | - expr expr
            | * expr expr
            | / expr expr
            | ^ expr expr
            | (expr)
            | > expr expr
            | < expr expr
            | integer

    integer -> x $\ni \mbox{x} \in \mathbb{I}$
```

## :scroll: Immediately on the List to be Implemented
- Complete parser
    - Implement Type-Checking
    - Implement basic control structures (if, while, etc.)
    - Implement char * operators
    - Generate Matrix type and operators (most of the code will be copied from
    my other repository [here](https://github.com/millipedes/linear_algebra_c_library).
	- Implement in Eval
	- Make Symbol Table Entries
- Integrate matrix math library functionality
- Infix function notation
- Make Symbol Table Stack (i.e. allow language to have stack frames)
- Make some command line flags work
- Make UI nicer (for REPL)
- Assembly translation for GAS 
