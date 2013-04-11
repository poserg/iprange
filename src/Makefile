CFLAGS = -MMD $(addprefix -I, $(DDIR) .)
SOURCE := parser.y source.l main.c
OBJ = $(addprefix $(DDIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCE)))))
ifeq (0, $(MAKELEVEL))
PROGRAM_NAME := iprange
DDIR = .
endif
ifndef complete
CFLAGS += -g -pg
endif

all : $(PROGRAM_NAME)

$(PROGRAM_NAME) : $(OBJ)
	cc $^ /usr/local/lib/libredblack.a $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(DDIR)/%.o : %.c 
	$(CC) -c $(CFLAGS) -o $@ $<

$(DDIR)/%.c $(DDIR)/%.h: %.y
	$(YACC) -o $@ $<

$(DDIR)/%.c : %.l
	$(LEX) -o$@ $<

.SECONDARY : $(OBJ:.o=.c)

.PHONY : all clean debug

clean :
	$(RM) *.d *.o parser.h parser.c source.c $(PROGRAM_NAME) list gmon.out

-include $(DDIR)/*.d

