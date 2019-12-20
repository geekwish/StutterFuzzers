echo "INFO: assume you are in klee docker container !"
clang -I/home/klee/klee_src/include -emit-llvm -g -O0 -Xclang -disable-O0-optnone -c stutter_All_for_klee.c -o workdirs/klee/test.bc
cd workdirs/klee/
klee test.bc

