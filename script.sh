yacc -Wyacc -y -d -Wno-yacc 1805108.y
echo '1'
g++ -w -c -o y.o y.tab.c
echo '2'
flex 1805108.l		
echo '3'
g++ -w -c -o l.o lex.yy.c
echo '4'
g++ -o a.out y.o l.o -lfl
echo '5'
./a.out input1.txt
