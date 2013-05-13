CC=g++
CFLAGS=-Wall --std=c++11

all: image_features

image_features: main.o binary_image.o image_loader.o
		$(CC) $(CFLAGS) main.o binary_image.o image_loader.o -o image_features

main.o:	main.cpp
	$(CC) $(CFLAGS) -c main.cpp

algorithms.o:  image_operations/algorithms/image_perimeter.cpp binary_image.o
		$(CC) $(CFLAGS) -c image_operations/algorithms/image_perimeter.cpp binary_image.o

binary_image.o: image_operations/binary_image.cpp
		$(CC) $(CFLAGS) -c image_operations/binary_image.cpp

image_loader.o: image_operations/image_loader.cpp 
		$(CC) $(CFLAGS) -c image_operations/image_loader.cpp

clean:
	 rm -rf *o image_features
