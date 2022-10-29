four.elf : one.o libfive.a
	gcc one.o -l five -L. -o four.elf

one.o :
	#gcc --static -c -o one.o one.c	
	gcc --static -c  one.c	
	
libfive.a :two.o
	#gcc --static -c -o two.o two.c
	gcc --static -c two.c
	ar rc libfive.a two.o

#two.o : 
#	gcc --static -c -o two.c two.o

//dasdasd

clean:
	rm four.elf one.o two.o libfive.a
	
