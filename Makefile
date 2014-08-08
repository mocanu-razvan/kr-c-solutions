DIRS = $(wildcard ex*)

.PHONY: all $(DIRS)

all: $(DIRS)

$(DIRS):
	$(MAKE) -C $@ -f ../Makefile.Exercise $@