echo "INFO: assume you have afl-gcc and QSYM, please set AFL_PREFIX for AFL and QSYM_PREFIX for QSYM in this script. "
export WORKDIR='workdirs/QSYM'
mkdir $WORKDIR/in
mkdir $WORKDIR/out
export AFL_PREFIX='../afl-2.52b'
$AFL_PREFIX/afl-gcc -g -O3 -Wall -fno-omit-frame-pointer -c stutter_All_for_QSYM_libFuzzer_AFL.c -o $WORKDIR/test.o
$AFL_PREFIX/afl-gcc -g $WORKDIR/test.o -o $WORKDIR/test

echo 'INFO: afl-fuzz run in background '
export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_CPUFREQ=1
echo 'Hello World.' > $WORKDIR/in/hello_world.txt
$AFL_PREFIX/afl-fuzz -M afl-master -i $WORKDIR/in -o $WORKDIR/out -- $WORKDIR/test @@ > /dev/null 2>&1 &
sleep 1
$AFL_PREFIX/afl-fuzz -S afl-slave  -i $WORKDIR/in -o $WORKDIR/out -- $WORKDIR/test @@ > /dev/null 2>&1 &

echo 'INFO: build normal test'
mkdir $WORKDIR/normal
gcc -g -O3 -Wall -fno-omit-frame-pointer -c stutter_All_for_QSYM_libFuzzer_AFL.c -o $WORKDIR/normal/test.o
gcc -g $WORKDIR/normal/test.o -o $WORKDIR/normal/test

sleep 1
echo 'INFO: run QSYM'
export QSYM_PREFIX='/workdir/qsym'
$QSYM_PREFIX/bin/run_qsym_afl.py -a afl-slave -o $WORKDIR/out -n qsym -- $WORKDIR/normal/test @@
