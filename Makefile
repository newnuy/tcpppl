all:
	cd chapter04  &&  $(MAKE)
	cd chapter05  &&  $(MAKE)


.PHONY: clean
clean:
	cd chapter04  &&  $(MAKE) clean
	cd chapter05  &&  $(MAKE) clean
