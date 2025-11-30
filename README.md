# .dev

A collection of code examples and experiments organized by programming language.

[![Build and Run Examples](https://github.com/benpm/.dev/actions/workflows/build-and-run.yml/badge.svg)](https://github.com/benpm/.dev/actions/workflows/build-and-run.yml)

## Languages

### C (`c/`)
- `angles` - atan2 function examples
- `AstonishingSqueakyBusinesses` - C example
- `Bad-Comparison` - C example
- `cursed-C-reverse-array-indexing` - Array indexing tricks
- `execvp` - Process execution example
- `ExpertOverdueStatistics` - C example
- `extractexponent` - Exponent extraction
- `FirebrickConsiderableGigahertz` - C example
- `GiftedYellowgreenEmulation` - Drawing example
- `LightsalmonTrivialDoom` - C example
- `RedundantUnawareProgramminglanguages` - C example
- `RipeMajesticLinks` - C example
- `RipeMajesticLinks-1` - C example
- `SpatialTeemingAccounting` - C example
- `WigglyImaginativeWatch` - C example
- `WrathfulLoathsomeCalculators` - C example

### C++ (`cpp/`)
- `booleanordering` - Boolean ordering experiments
- `C20` - C++20 symmetric pairing function
- `doubleinheritance` - Double inheritance example
- `FastRaggedLibrary` - C++ example
- `FunctionalRotatingInstructions` - C++ example
- `LightblueMotionlessHexagons` - C++ example
- `Reference-Slicing` - Reference slicing demonstration
- `sharedptrfunkiness` - Shared pointer experiments
- `slot-trie` - Slot trie data structure
- `symmetric-pairing-function` - Symmetric pairing function
- `templatededuction` - Template deduction examples
- `transformmap` - Transform map examples
- `Type-safe-shared-methods` - Type-safe method examples
- `typechecking` - Type checking examples
- `typemap` - Type map examples
- `unorderedsetcollisions` - Unordered set collision examples
- `WideSparseKilobyte` - C++ example

### JavaScript (`javascript/`)
- `Array-Interpose` - Array interposition utility
- `constanttimeneighborfindingquadtrees` - Quadtree neighbor finding
- `kaboomtest` - Kaboom.js game framework test
- `linearquadtree` - Linear quadtree implementation
- `rectangledist` - Rectangle distance calculations

### Python (`python/`)
- `AggressiveHummingConferences` - Regex parsing example
- `HastyOnlyMemorypool` - Matplotlib plotting
- `largesttwofactors` - Largest two factors algorithm
- `loganhelp` - Function examples
- `RecklessElatedCallback` - Python syntax example
- `ShockedSoupyCoordinate` - Python example
- `signeddist` - Signed distance function
- `spherecoords` - Spherical coordinate conversion

### Rust (`rust/`)
- `vecsnstuff` - Rust Hello World

### Nim (`nim/`)
- `EqualBeautifulDebugging` - Nim counting example

## Building and Running

The GitHub Actions workflow automatically builds and runs all examples on every push. View the execution logs at the [GitHub Pages site](https://benpm.github.io/.dev/).

### Local Development

**C:**
```bash
gcc -o main c/<example>/main.c -lm && ./main
```

**C++:**
```bash
g++ -std=c++20 -o main cpp/<example>/main.cpp && ./main
```

**JavaScript:**
```bash
node javascript/<example>/index.js
```

**Python:**
```bash
python python/<example>/main.py
```

**Rust:**
```bash
cd rust/<example> && cargo run
```

**Nim:**
```bash
nim compile --run nim/<example>/main.nim
```
