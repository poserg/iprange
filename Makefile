PROGRAM_NAME = prog
SRC = parser.y source.l main.c
OBJ = $(addsuffix .o, $(basename $(SRC)))
CC = g++
CFLAGS = -MMD
all : $(PROGRAM_NAME)
	
$(PROGRAM_NAME) : $(OBJ)
	$(CC) $^ -o $@

.PHONY : all clean

.SECONDARY : parser.c source.c
	
clean : 
	$(RM) $(PROGRAM_NAME) $(OBJ) parser.c y.tab.h lex.yy.c source.c a.out *.d parser.t*

-include *.d
