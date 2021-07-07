

O_FILES:= Example.o

CPP_FILES:= Example.cpp



compile : $(O_FILES)
	g++ $^ -o Exaple.exe -ggdb

.*o : .*cpp
	g++ -c $^ -o $@ -ggdb


.SILENT: