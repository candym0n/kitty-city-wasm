# Kitty City (in C++)
- Visit https://candyman.pink/kitty-city/tutorial.html to find out how to play
- Graphics / Audio / Frontend stuff is all HTML / Javascript
- Backend is Node.js
- All the game logic is C++
- Makefile and Python for builds
- C++ compiles with Web Assembly

## Why?
- Kitty City is already implemented in https://candyman.pink/kitty-city, but as you can see, there are a LOT of issues
    - Everything is in a single file
    - Only two comments - one of them being "Never revisit"
    - No source control
    - 2000+ lines of unreadable code (in a single file)
    - Probably more problems (feel free to submit a pull request)
- The problem
    - Everything is dynamically typed, so it is hard to edit and everything is sort of hacky
    - Unless I write weird /** */ comments ANY IDE I use does not really work
    - Things (can) get a little slow now and then...
## The solution
- Write everything in TypeScript!
    - Pros
        - Statically typed
    - Cons
        - Slower
        - Literally compile to a dynamically typed language (?!?)
        - I STILL need to type /** */ comments!
- Write everything in C++
    - Pros
        - Statically typed
        - Faster
        - Better comments
        - Better organization
        - More control
        - More flexability
        - Probably more
    - Cons
        - Needs to be compiled (same with TypeScript)
        - Could lead to a sudden and inexplicable craving for grilled cheese sandwiches

## How?
- Game Engine (written in C++)
- Build script (written in Python)
- Graphics / Audio (written in Javascript)

## How to contribute?
- Subscribe to [Kitty City](https://www.youtube.com/@ScroogeMcCat?sub_confirmation=1.)
- Visit https://candyman.pink
- Add more features to the Game Engine
- Document stuff
- Search for issues / bugs
- Optimize

# What do I need to run this locally?
- Please make sure [Python](https://www.python.org/) is installed
- Please make sure you have [Emscripen](https://emscripten.org/docs/getting_started/downloads.html) installed
- Please ensure you have a browser that supports WebAssembly.
- Make would be nice (you don't need it)
- A good attitude
- Run the following command if you have make:
`
make
`
- Or if you don't
`
python3 build.py
`
- But the Makefile has clean functionality (add that to python if you want, but I find typing make is easier)

- To run it please enter the public directory and type
`
python3 -m http.server 8080
`
