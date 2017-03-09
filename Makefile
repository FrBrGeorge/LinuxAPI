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

all:	init-fs exec-fs fork-fs test-fs readfile-fs

list:
	for F in *.cpio.gz; do echo "	### $$F"; zcat < $$F | cpio -itv; done

.PHONY: fork-fs exec-fs init-fs test-fs clean

fork-fs:	forkmess forkwait forkexec child fork.cpio.gz

exec-fs:	exec child exec.cpio.gz

init-fs:	init init.cpio.gz

test-fs:	test.cpio.gz

readfile-fs:	readfile readfile.cpio.gz

clean:
	rm -rf *.root
	rm -f *.gz *.tmp $(patsubst %.c,%,$(wildcard *.c))
