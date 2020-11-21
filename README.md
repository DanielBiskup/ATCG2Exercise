## Install build dependencies (Ubuntu 20.10 groovy)
```bash
sudo apt-get install build-essential gdb libx11-dev xorg-dev libglu1-mesa-dev
sudo snap install cmake --classic
```

## Setup
- clone this repository using the `--recursive` flag, i.e. for HTTPS do
`git clone --recursive https://github.com/intrinsicD/ATCG2Exercise.git`
- run `bash init.sh`, which create the `./bin` directory and monkey patch `./external/spectra/CMakeLists.txt`

## (Optional) Updating OpenGL version
If you whish to update the OpenGL version used you can orient yourself on the following steps:
- go to the website **https://glad.dav1d.de/** and download the glad files
  - Language **C/C++**
  - use specification **OpenGL**
  - Profile **Core**
  - API gl **Version 4.6** if possible, but at least **Version 4.1**
  - Options mark **Generate a loader**
- add the **glad.{c, h}** files to *external/glad*
- add the **KHR** folder to *external/*

## Compilation
- to compile please add a `/build` folder
- from that folder run `cmake ..`
- then run `make`
  - if you want to build in parallel please run `make -j 5` for building with 5 cores
- you can run the executable by executing it from inside the `./bin` directory. I.e. `cd ./bin` followed by `./bcg_viewer`

## Usage
- Quit: Strg/Ctrl+Q
- Scale Points: Strg + Mouse wheel
- Zoom Camera: Mouse wheel
- Rotate Camera: Mouse left drag
- Move Camera in Plane: Mouse middle drag
- Move Camera Forward/Left/Backward/Right: W/A/S/D
- Reset Camera: R
- Left Click: Select
- Curve:
  - Left Click: Add point
  - Right Click: End point
  - Strg Press: Fix Camera
