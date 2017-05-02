Q ?= @
DESTDIR?=../bin


EXE		= http_blink
CC		= gcc
iNCLUDE		= -I.
CFLAGS		= -Wformat=2 -Wall -Wextra -Winline $(INCLUDE) -pipe -fPIC

LIBS		= -lwiringPi -lpthread -lcrypt -lrt -lm


SRC		= server.c utils.c \
		  urls.c

HEADERS 	= $(shell ls *.h)

OBJ     	= $(SRC:.c=.o)

all:		$(EXE)

$(EXE): $(OBJ)
	$Q echo "[COMPILING]"
	$Q $(CC) -g -o $(EXE) $(OBJ) $(LIBS)

.c.o:
	$Q $(CC) $(CFLAGS) -c $< -o $@
	$Q echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	$Q echo "[Clean]"
	$Q rm -f $(OBJ) $(OBJ_I2C) *~ core tags Makefile.bak $(EXE)

.PHONY: install
install: $(EXE)
	$Q echo "INSTALL"
	$Q mv $< $(DESTDIR)

.PHONY: uninstall
uninstall:
	$Q echo "[Uninstall]"
	$Q rm -f $(DESTDIR)/*
