


##############################################
O_FILES =\
example/example.o

CPP_FILES =\
example/example.cpp

O_DIRS =\
example/

INLUDE_FOLDERS =\
-I ./ 

FLAGS = -ggdb

HEADERS = linked_list.hh\
llist_funct.hh

OUTPUT = example/example.exe
################################################





clean : 
	echo "--------------------------"
	echo "STEP[]: CLEAN"
	echo "--------------------------"
	echo "Cleaning" $(OUTPUT)
	rm -f $(OUTPUT)
	for element in $(O_FILES); \
	do\
		echo "Cleaning" $$element;\
		rm -f $$element;\
	done

all: $(O_FILES) 
	g++ $(O_FILES) $(FLAGS) $(INLUDE_FOLDERS) -o $(OUTPUT)


$(O_FILES): $(CPP_FILES) $(HEADERS)
	echo "--------------------------"
	echo "STEP[]: CREATE SUB FOLDERS"
	echo "--------------------------"
	for element in $(O_DIRS); do echo "Creating dir" $$element; mkdir -p $$element; done

	echo "--------------------------"
	echo "STEP[]: COMPILE"
	echo "--------------------------"
	for element in $(CPP_FILES);\
	do\
		echo "Compiling" $$element;\
		g++ -c $$element $(FLAGS) $(INLUDE_FOLDERS) -o $@;\
	done

.SILENT: