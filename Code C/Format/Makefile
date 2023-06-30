IDIR =../Header
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=Source
LDIR =lib

_DEPS = compare.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o compare.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
