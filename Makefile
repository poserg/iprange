PROGRAM_NAME = prog
SRC = source.l
OBJ = $(addsuffix .o, $(basename $(SRC)))
all : $(PROGRAM_NAME)
	
$(PROGRAM_NAME) : $(OBJ)
	$(CC) $^ -o $@

.o.c :
	$(CC) $< -ll -o $@

.PHONY : all clean

clean : 
	$(RM) $(PROGRAM_NAME) $(OBJ) source.c
