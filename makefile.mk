a: main_playfair.o encryption.o decryption.o
	gcc main_playfair.o encryption.o decryption.o
main_playfair.o: main_playfair.c header.h
	gcc -c main_playfair.c
encryption.o: encryption.c header.h
	gcc -c encryption.c
decryption.o: decryption.c header.h
	gcc -c decryption.c