gcc -g -c -Wall -fPIC -I../../src/core/ ./*.c
gcc -shared ./*.o -o ../../run/dust/cmod.so
rm ./*.o
