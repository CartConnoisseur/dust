gcc -g -c -Wall -fPIC -I/usr/lib/jvm/java-17-openjdk/include/ -I/usr/lib/jvm/java-17-openjdk/include/linux/ ./*.c
gcc -shared ./*.o -o ../../run/dust/internal/core.so
rm ./*.o