XENO_CONFIG := /usr/xenomai/bin/xeno-config
CFLAGS := $(shell $(XENO_CONFIG) --alchemy --cflags)
LDFLAGS := $(shell $(XENO_CONFIG) --alchemy --ldflags)
CC := $(shell $(XENO_CONFIG) --cc)

EXECUTABLE :=xemomaitest

all: $(EXECUTABLE)

%: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)