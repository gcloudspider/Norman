cpu_mode.bin:cpu_mode.S
	arm-linux-gcc -g -c -o cpu_mode.o cpu_mode.S
	arm-linux-ld -Ttext 0x000 -g cpu_mode.o -o cpu_mode_elf
	arm-linux-objcopy -O binary -S cpu_mode_elf cpu_mode.bin

clean:
	rm -rf cpu_mode.bin *.o cpu_mode_elf
