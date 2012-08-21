test: test.o libMvtnorm/libMvtnorm.a
	g++ -o test $^
test.o:  test.cpp 
	g++ -c $^  -I./libMvtnorm
libMvtnorm/libMvtnorm.a:
	cd libMvtnorm; make; cd ..
clean:
	rm -f *.o test 
