all: qemu_launch

C_FILES=./kernel.c ./console/console.c
O_FILES=${C_FILES:.c=.o}

qemu_launch: os.bin
	qemu-system-i386 -drive format=raw,file=$<,index=0,if=floppy

os.bin: boot.bin kernel.bin
	cat $^ > $@

boot.bin: boot.asm
	nasm $< -f bin -o $@

kernel.bin: kernel-entry.o ${O_FILES}
	ld -m elf_i386 -s -o $@ -Ttext 0x1000 $^ --oformat binary

kernel-entry.o: kernel-entry.elf
	nasm $< -f elf -o $@

kernel.o: kernel.c
	gcc -Iinclude -fno-pie -m32 -ffreestanding -c ${@:.o=.c} -o $@

console/console.o: console/console.c
	gcc -Iinclude -fno-pie -m32 -ffreestanding -c $< -o $@

clean:
	$(RM) *.o *.bin console/*.o
