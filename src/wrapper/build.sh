gcc -g -c -Wall -fPIC -I/usr/lib/jvm/java-17-openjdk/include/ -I/usr/lib/jvm/java-17-openjdk/include/linux/ -I../../build/generated/sources/headers/java/main/ ./*.c
gcc -shared ./*.o -o ../../run/dust/internal/wrapper.so
rm ./*.o