GEN=*-*[^.]? *.txt
JUNK=o oo ooo o.* a.out
all: shm1-ownerS shm1-owner shm1-user shm1-userS in.txt mm-copy sock-client sock-server

shm1-owner: shm1-owner.c

shm1-ownerS: shm1-ownerS.c

shm1-user: shm1-user.c

shm1-userS: shm1-userS.c

sock-client: sock-client.c

sock-server: sock-server.c

mm-copy:	mm-copy.c

in.txt:
	@echo "This is" >$@
	echo "a message." >>$@

clean:
	rm -f ${GEN} ${JUNK}
