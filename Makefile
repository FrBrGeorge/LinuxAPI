LDFLAGS=-static

%.root:	%.list allfiles
	rm -rf "$@"
	mkdir -p "$@"
	./allfiles $< | cpio -pLd "$@"

%.cpio.gz:	%.root
	( cd $<; find .| cpio -o -H newc ) | gzip > $@
	rm -rf $<

run:	all
	@echo
	@echo "	Images:"
	@ls -m *.gz
	@echo "	Use:"
	@echo "./run image_name [init_binary]"
	@echo

all:	init-fs exec-fs fork-fs test-fs

fork-fs:	forkmess fork.cpio.gz

exec-fs:	exec child exec.cpio.gz

init-fs:	init init.cpio.gz

test-fs:	test.cpio.gz

clean:
	rm -rf *.root
	rm -f *.gz *.tmp $(patsubst %.c,%,$(wildcard *.c))
