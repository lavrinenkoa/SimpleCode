Results of build and run:

```
$ make && ./bt
gcc -g -rdynamic  -I/usr/include/ -I.. -c bt.c
gcc -g -rdynamic  -I/usr/include/ -I.. bt.o -o bt -lrt

in:  eeaaaaabbbaccccccdddddddaaaaaddddbbbbaaaa
out: aaaaaaaaaaaaaaabbbbbbbccccccdddddddddddee
```
