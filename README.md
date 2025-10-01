# OpenGL-Starter
Starter project with **OpenGL**, **SDL3**, and **GLEW** for Linux.

This is a minimal setup to quickly get started with OpenGL development using SDL3 as the windowing/input library and GLEW for managing OpenGL extensions.

## Prerequisites
Make sure you have the C++ development tools installed (compiler, CMake, etc.).

### Install Required Packages
**Arch Linux**
```bash
sudo pacman -S base-devel cmake sdl3 glew
```
**Ubuntu / Debian**
```bash
sudo apt update
sudo apt install build-essential cmake libsdl3-dev libglew-dev
```
**Fedora**
```bash
sudo dnf install @development-tools cmake SDL3 glew
```
## Usage
1. Clone the repository
```bash
git clone https://github.com/Parven05/OpenGL-Starter.git
```
2. Build & Run
```bash
# Generate cmake files (recommended run it once) 
./rebuild.sh
# Build & run exe file
./build.sh
```
*Note: make sure to remove dummy files before or after compiling the project*
