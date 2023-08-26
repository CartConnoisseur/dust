nasm -felf64 *.asm
gcc -shared ./*.o -o ../../run/dust/asmmod.so

rm ./*.o