test:
	cd tests && make test

clean: 
	cd tests && make clean

%.test:
	cd tests && make $@
