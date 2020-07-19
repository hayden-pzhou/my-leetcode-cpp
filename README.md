# my-leetcode-solutions

### Other lang(s) solutions

[golang](go/)

[rust-lang](rust/)

### C++ solutions

Better to use CMake ( >= 3.12), C++14 (gcc >= 5.0, Clang >= 3.4, MSVC >= 19.0/VS2015)

- run `./clean.sh` before generating or updating makefile from CMake, because last CMake cache may block updating of some changes.
- run `cmake .` to generate or update makefile using CMake.
- run `make` to compile all source codes in `src/`, the executable binary files will be stored in `bin/`
- `cd` to `bin/` and verify manually
- run `make clean` to delete all binary files in `bin/`

### XXX

- graph/topological: 206, 210
- tire tree: 208, 211, 212
- dp: 198, 213
- kmp:
