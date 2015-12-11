# Common Makefile for exercises.

# Defines CFLAGS and the default and `clean` targets.

# Makefiles from each exercise directory include this
# Makefile and define the XTARGET variable to be the
# target to build the respective exercise.

# Use kernel name to detect Cygwin or MinGW.
WIN32 = $(shell uname -s 2>/dev/null | egrep 'CYGWIN|MINGW')

# Define the binary file name. On Windows,
# a file with an `.exe` extension will be
# generated.
ifneq (,$(WIN32))
	XBIN = $(XTARGET).exe
else
	XBIN = $(XTARGET)
endif

CFLAGS = -std=c90 -pedantic -Wall -Wextra -g

.PHONY: clean

# The default target builds the exercise using implicit rules.
$(XTARGET):

clean:
	$(RM) $(XBIN)