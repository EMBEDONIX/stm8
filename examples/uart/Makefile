PNAME = uart
IDIR = ../include
ODIR = bin
CC = sdcc
CFLAGS = -I$(IDIR)

all:
	mkdir -p $(ODIR)
	$(CC) $(PNAME).c -lstm8 -mstm8 $(CFLAGS) --out-fmt-ihx -o"./$(ODIR)/"

.PHONY: clean

clean:
	rm -rf $(ODIR)
flash:
	stm8flash -cstlinkv2 -pstm8s003 -w$(ODIR)/$(PNAME).ihx
