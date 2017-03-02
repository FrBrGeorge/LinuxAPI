LDFLAGS=-static

%.root:	%.list allfiles
	rm -rf "$@"
	mkdir -p "$@"
	./allfiles $< | cpio -pLd "$@"

%.cpio.gz:	%.root
	( cd $<; find .| cpio -o -H newc ) | gzip > $@

all:	init test.cpio.gz

init:	init.c

clean:
	rm -rf *.root
	rm -f *.gz init *.tmp
