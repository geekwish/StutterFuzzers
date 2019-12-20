echo "INFO: require clang which support -fsanitize=fuzzer !"
echo "compile stutter_libFuzzer.c to test file"
clang -g -O2 -fno-omit-frame-pointer -fsanitize=fuzzer -c stutter_libFuzzer_and_AFL.c -o workdirs/libFuzzer/test.o
cd workdirs/libFuzzer/
clang++ -fsanitize=fuzzer test.o -o test
./test
