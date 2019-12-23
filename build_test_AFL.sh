export PREFIX='../afl-2.52b'
echo "INFO: assume you have afl-gcc , please set PREFIX for AFL in this script. "
$PREFIX/afl-gcc -g -O3 -Wall -fno-omit-frame-pointer -c stutter_AFL.c -o workdirs/AFL/test.o
#$PREFIX/afl-gcc -g -O3 -Wall -fno-omit-frame-pointer -c stutter_libFuzzer_and_AFL.c -o workdirs/AFL/test.o
cd workdirs/AFL/
mkdir in out
echo 'Hello World.' > in/hello_world.txt
$PREFIX/afl-gcc -g test.o -o test
export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1
$PREFIX/afl-fuzz -i in -o out -- ./test @@
