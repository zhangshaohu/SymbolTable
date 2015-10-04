# SymbolTable
v 1
SYMBOLS.DAT    
6 AAAAA True
7 ABCDEFG False
9 ABCDEFGM True
-33 AAAA True
4 7AB21 True
5 ABC123 False
454 ABddfFGddgegdggddgdgdg 1


TEST.DAT:
AAAAAAA
AAAAA
ABC12364
7AD21
ABCDEFABCD
AAAA

To run this program in Linux system, you can type command:
g++ BinaryTree.cpp main.cpp -o test
./test
OUTPUT:

-----Step one: Insert valid table-------
-----Open symbols.dat......-------------

7AB21  Invalid symbol(label): Label should start with letter!!
ABddfFGddgegdggddgdgdg  Invalid symbol(label): Label should be less than 22 characters long!!
-----Step two: Lookup------

AAAAAAA Not Found
AAAAA found in the table: 6 AAAAA True

ABC12364 found in the table: 5 ABC123 False

7AD21 Not Found
ABCDEFABCD found in the table: 7 ABCDEFG False

AAAA found in the table: -33 AAAA True

----Step Three: Inorder traversal of the symbol table with associated fields----
Value  Label   Rflag mflag
-33 AAAA True 0
6 AAAAA True 0
5 ABC123 False 0
7 ABCDEFG False 0
9 ABCDEFGM True 0
-----Program ended-----



