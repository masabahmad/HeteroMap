SUBDIRS= examples predictors

HET_DIR=$(PWD)

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $(HET_DIR)/$$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $(HET_DIR)/$$dir; \
	done
