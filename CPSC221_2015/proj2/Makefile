# Our project ('all') is just to build the executable file 'huftree'
# This line simply says that 'all' depends on 'huftree'.
all : huftree

# 'huftree' depends on one .o (object) file
# add any new .o files to the list
# build it using g++

# huftree : huftree.o
# 	g++ -o huftree -g huftree.o

huftree :  huftree.cc priorityheap.o codetree.o
	g++ -Wall -g huftree.cc priorityheap.o codetree.o -o huftree

# huftree.o is dependant on one .cc file and no .h files
# IMPORTANT: when you #include a new .h file, be sure to add it here.
# Otherwise, the 'make' command may not re-build your program even
# though you changed that .h file.
# -Wall: make the compiler display all warnings it knows about;
# hopefully it'll catch something for us
# -c: only compile, don't link (we do that above)
# -g: put in debug information, for those of you who are using
# debuggers (like gdb or ddd or xxgdb)

# huftree.o : huftree.cc
# 	g++ -Wall -c -g huftree.cc

priorityheap.o: priorityheap.cc priorityheap.h
	g++ -Wall -c -g priorityheap.cc -o priorityheap.o

# and same idea for other .o files ...
codetree.o: codetree.cc codetree.h
	g++ -Wall -c -g codetree.cc -o codetree.o


# 'clean' removes any files that were created via the Makefile,
# leaving you with only your original source code files
clean :
	rm *.o
	rm huftree