TARGET = vm/vm
OBJS   = vm/main.o vm/stackvm.o
CC     = cc
CFLAGS += -O2 -MD


$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CFLAGSDEF) $< -o $@

-include *.d

.PHONY: clean
clean:
	rm -f vm/*.d vm/*.o vm/vm
