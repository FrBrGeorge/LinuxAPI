LDFLAGS=-static

all:	forkexec-all
	@echo
	@echo "	Images:"
	@ls -m *.gz
	@echo "	Use:"
	@echo "./run image_name [init_binary]"
	@echo

%.root:	%.list allfiles
	rm -rf "$@"
	mkdir -p "$@"
	./allfiles $< | cpio -pLd "$@"

%.cpio.gz:	%.root
	( cd $<; find .| cpio -o -H newc ) | gzip > $@
	rm -rf $<

shell:	shell.cpio.gz
	@./show shell
	@echo "./run shell <whatever>"

list:
	for F in *.cpio.gz; do echo "	$$F:"; ./show $$F; done

.PHONY: fork-fs exec-fs init-fs test-fs clean readfile-fs all clean

forkexec-all:	init-fs exec-fs fork-fs test-fs readfile-fs

fork-fs:	forkmess forkexec forkwait child forkenv childe fork.cpio.gz

exec-fs:	exec child exec.cpio.gz

init-fs:	init init.cpio.gz

test-fs:	test.cpio.gz

readfile-fs:	readfile readfile.cpio.gz

clean:
	rm -rf *.root
	rm -f *.gz *.tmp $(patsubst %.c,%,$(wildcard *.c))
