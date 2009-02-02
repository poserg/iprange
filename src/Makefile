#CC = g++
CFLAGS = -MMD $(addprefix -I, $(DDIR) .)
SOURCE := parser.y source.l main.c
OBJ = $(addprefix $(DDIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCE)))))
ifeq (0, $(MAKELEVEL))
PROGRAM_NAME := iprange
DDIR = .
endif

all : $(PROGRAM_NAME)

$(PROGRAM_NAME) : $(OBJ)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(DDIR)/%.o : %.c 
	$(CC) -c $(CFLAGS) -o $@ $<

$(DDIR)/%.c $(DDIR)/%.h: %.y
	$(YACC) -o $@ $<

$(DDIR)/%.c : %.l
	$(LEX) -o $@ $< 

.SECONDARY : $(OBJ:.o=.c)

.PHONY : all clean

clean :
	$(RM) *.d *.o parser.h parser.c source.c $(PROGRAM_NAME) 

-include $(DDIR)/*.d

