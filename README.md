# Second-semester coursework

Small C++ and Python exercises from the second semester. Each source file is a
standalone program.

## Programs

| C++ source | Exercise | Input / output |
| --- | --- | --- |
| [ctverec.cpp](ctverec.cpp) | Find a square among points | Point count and coordinates on stdin |
| [diff.cpp](diff.cpp) | Insertion/deletion diff | Length, string, length, string on stdin |
| [kvadrantova_komprese.cpp](kvadrantova_komprese.cpp) | Quadrant-compression DP | PBM-style header, square dimensions, binary pixels on stdin |
| [plot.cpp](plot.cpp) | Fence-vertex ordering | Point count and coordinates on stdin |
| [roztrzity_profesor.cpp](roztrzity_profesor.cpp) | Paper-shuffling exercise | Reads `papiry.in`, writes `papiry.out` |
| [sazba.cpp](sazba.cpp) | Word-wrap cost minimization | Three integers `L N R`, then `N` words on stdin |
| [spolocny_podretezec.cpp](spolocny_podretezec.cpp) | Common-subsequence reconstruction | Two lengths, then two strings on stdin; writes `out` |
| [tecky_a_zavorky.cpp](tecky_a_zavorky.cpp) | Number encoding with dots and parentheses | Reads `cisla.in`, writes `cisla.out` |

| Python source | Exercise | Usage |
| --- | --- | --- |
| [eratosthenes.py](eratosthenes.py) | Count primes up to an upper bound | Upper bound on stdin |
| [justify.py](justify.py) | Text justification | Width argument; paragraphs on stdin |
| [multiplication_table.py](multiplication_table.py) | Multiplication table | Integer argument |
| [multiplication_table_oneliner.py](multiplication_table_oneliner.py) | One-line version of the table | Integer argument |
| [postfix_calc.py](postfix_calc.py) | Integer postfix calculator | One expression per stdin line |
| [weather.py](weather.py) | Query and graph local weather data | JSON file argument; commands on stdin |

`diff.cpp` is the original coursework version. The maintained
[Diff repository](https://github.com/1Kori256/Diff) contains the later CLI and
formatter improvements.

## Build C++

Requires GCC or Clang and CMake 3.16+. Some exercises use variable-length arrays,
so the build enables GNU C++17 extensions.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 2
```

Executables are placed in `build/`. To build only one exercise:

```sh
cmake --build build --target ctverec
```

For file-based exercises, copy the sample inputs and run from the build folder:

```sh
cp cisla.in papiry.in build/
cd build
./tecky_a_zavorky
./roztrzity_profesor
```

Generated outputs then stay in `build/`. The root `.in`, `.out`, and `out` files
are historical samples kept with the coursework.

## Run Python

Uses Python 3 and its standard library.

```sh
python3 multiplication_table.py 7
printf '2 3 +\n' | python3 postfix_calc.py
printf '100\n' | python3 eratosthenes.py
printf 'Text to justify over several lines.\n' | python3 justify.py 20
```

`weather.py` expects a JSON mapping of city → `YYYYMMDD` → measurements
(`temp`, `relhum`, `ap`). For example, its query syntax is
`temp city:Prague date:20230101`; the corresponding dataset must be supplied.

CI builds all eight C++ programs on Linux/macOS and checks Python syntax.
