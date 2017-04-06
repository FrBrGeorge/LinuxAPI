all: shm1-ownerS shm1-owner shm1-user in.txt mmcopy

shm1-owner: shm1-owner.c

shm1-ownerS: shm1-ownerS.c

shm1-user: shm1-user.c

mmcopy:	mmcopy.c

in.txt:
	@echo "This is" >$@
	echo "a message." >>$@

clean:
	rm -f shm1-ownerS shm1-owner shm1-user mmcopy in.txt out.txt a.out
