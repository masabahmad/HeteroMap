SUBDIRS= examples

CRONO_DIR=$(PWD)

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $(CRONO_DIR)/apps/$$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $(CRONO_DIR)/apps/$$dir; \
	done
