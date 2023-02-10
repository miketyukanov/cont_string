CC=g++
CCFLAGS=-Wall -std=c++14
CLEAN=rm -f
EXEC=snippets
OBJECT_FILES=*.o
SOURCE_FILES=main.cpp cont_string.cpp test_templates.cpp member_calls_ctor.cpp

$(EXEC): $(OBJECT_FILES)
	$(CC) $(CCFLAGS) -o $@ $^

$(OBJECT_FILES): $(SOURCE_FILES)
	$(CC) $(CCFLAGS) -c $^

clean: 
	$(CLEAN)  *.o $(EXEC)


