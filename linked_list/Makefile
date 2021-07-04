C_COMPILER := gcc
CPP_COMPILER := g++
LINKER := g++
C_FLAGS := -std=c99\

CPP_FLAGS := -std=c++17\

COMMON_FLAGS := -ggdb\

GLOBAL_INC := 
OUTPUT_DIR := Build
OUTPUT_NAME := main

FOLDER_INCLUDE:= -I ./\
-I ./.vscode\

CPP := .//16D_list.cpp\

C := 
SRC_DIR := ./ ./.vscode 


O := $(OUTPUT_DIR)/.//16D_list.o\

all: clean compile


clean:
	echo "------------------------------------"
	echo " STEP[]: Cleaning Folder $(OUTPUT_DIR)     "
	echo "------------------------------------"
	rm -rf $(OUTPUT_DIR)
	sleep 0.5



compile: echo_compile mkdir $(O)
	echo "------------------------------------"
	echo " STEP[]: LINKING INTO EXE           "
	echo "------------------------------------"
	sleep 0.5
	$(LINKER) $(O) $(COMMON_FLAGS) -o $(OUTPUT_DIR)/$(OUTPUT_NAME).exe
mkdir : 
	for dir in $(SRC_DIR); do mkdir -p $(OUTPUT_DIR)/$$dir; done

echo_compile : 
	echo "------------------------------------"
	echo " STEP[]: COMPILING SOURCE FILES     "
	echo "------------------------------------"
	sleep 0.5

$(OUTPUT_DIR)/.//16D_list.o : .//16D_list.cpp .//linked_list.hpp 
	echo "Compiling C++ source file:16D_list.cpp"
	$(CPP_COMPILER) $(CPP_FLAGS) $(COMMON_FLAGS) $(GLOBAL_INC) $(FOLDER_INCLUDE) -o $@ -c .//16D_list.cpp



.SILENT:

