Xorenc
======

Don't forget to compile it first, with "gcc -o xorenc xorenc.c" or "g++ -x c -o xorenc xorenc.c".
To run xorenc, you need to give two options: the input file, and the output filename.

USAGE
=====

xorenc [input] [output]

EXAMPLE
=======

Let's assume I have xorenc in the current directory and a file called example, and I want to encode it as example.xor.
All I have to do is:
./xorenc example example.xor
and it's done. I have no idea exactly how fast it does this encoding process, as I have not timed it myself, but it encoded over 270,000 lines in about 4 seconds (it was a dictionary, found at this link http://svn.pietdepsi.com/repos/projects/zyzzyva/trunk/data/words/British/CSW12.txt)
so you can encode it and see how long that takes you on your machine.
