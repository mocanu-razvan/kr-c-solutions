# A space separated list of all exercises.
DIRS = $(wildcard ex*)
MAKEFLAGS = --no-print-directory

.PHONY: all clean $(DIRS)

# The default target.
all: $(DIRS)

# Execute the `clean` target for all exercise Makefiles.
clean:
	@for x in $(DIRS); do $(MAKE) -C $$x clean; done

# Make exercises by using the Makefile in each directory.
# The target is the same as the directory's name.
$(DIRS):
	@$(MAKE) -C $@ $@