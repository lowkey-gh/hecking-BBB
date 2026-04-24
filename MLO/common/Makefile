CC      = arm-none-linux-gnueabihf-gcc


SRC := $(wildcard *.c)

OBJDIR := obj
OBJ := $(patsubst %.c,$(OBJDIR)/%.o, $(SRC))

.PHONY : all clean

all: $(OBJDIR) $(OBJ)


$(OBJDIR):
	mkdir -p $(OBJDIR)



$(OBJDIR)/%.o: %.c
	$(CC) -c $< -o $@


clean:
	@rm -rf $(OBJDIR)
