watch_dog.bin:watch_dog.S
	arm-linux-gcc -g -c -o watch_dog.o watch_dog.S
	arm-linux-ld -Ttext 0x00 -g watch_dog.o -o watch_dog_elf
	arm-linux-objcopy -O binary -S watch_dog_elf watch_dog.bin

clean:
	rm -rf watch_dog.bin *.o watch_dog_elf
