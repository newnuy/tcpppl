all:
	cd chapter04  &&  $(MAKE)
	cd chapter05  &&  $(MAKE)
	cd chapter06  &&  $(MAKE)
	cd chapter07  &&  $(MAKE)


.PHONY: clean
clean:
	cd chapter04  &&  $(MAKE) clean
	cd chapter05  &&  $(MAKE) clean
	cd chapter06  &&  $(MAKE) clean
	cd chapter07  &&  $(MAKE) clean
