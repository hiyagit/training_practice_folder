cmd_/home/training/hiya/eldd/sample/example.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -z noexecstack   --build-id  -T ./scripts/module-common.lds -o /home/training/hiya/eldd/sample/example.ko /home/training/hiya/eldd/sample/example.o /home/training/hiya/eldd/sample/example.mod.o;  true