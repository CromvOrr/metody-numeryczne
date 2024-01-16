CC := g++
FLAGS := -o

SORT := "num1-sort.cpp"
CSORT := "num1-sort.o"

SRC_A := "num1a.cpp"
CSRC_A := "num1a.o"
SRC_B := "num1b.cpp"
CSRC_B := "num1b.o"

FLOAT_FILE_A := "data_float_a.dat"
DOUBLE_FILE_A := "data_double_a.dat"
FLOAT_SORTED_FILE_A := "data_float_sorted_a.dat"
DOUBLE_SORTED_FILE_A := "data_double_sorted_a.dat"

FLOAT_FILE_B := "data_float_b.dat"
DOUBLE_FILE_B := "data_double_b.dat"
FLOAT_SORTED_FILE_B := "data_float_sorted_b.dat"
DOUBLE_SORTED_FILE_B := "data_double_sorted_b.dat"

run:
	$(CC) $(SRC_A) $(FLAGS) $(CSRC_A)
	./$(CSRC_A)
	$(CC) $(SRC_B) $(FLAGS) $(CSRC_B)
	./$(CSRC_B)
	$(CC) $(SORT) $(FLAGS) $(CSORT)
	./$(CSORT) $(FLOAT_FILE_A) $(FLOAT_SORTED_FILE_A)
	./$(CSORT) $(DOUBLE_FILE_A) $(DOUBLE_SORTED_FILE_A)
	./$(CSORT) $(FLOAT_FILE_B) $(FLOAT_SORTED_FILE_B)
	./$(CSORT) $(DOUBLE_FILE_B) $(DOUBLE_SORTED_FILE_B)

clean:
	rm *.dat *.o