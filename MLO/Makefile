.PHONY: all clean

COMMON = common

# add your projects to be compiled
PROJECTS = 00.stuck

DIRS := $(COMMON) $(PROJECTS)

all:  $(DIRS)
	for dir in $(DIRS); do \
                $(MAKE) -C $$dir; \
	done 

clean: 
	for dir in $(DIRS); do \
		$(MAKE) -C $$dir clean; \
	done
