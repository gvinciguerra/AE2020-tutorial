# AE2020 Tutorial

This repository, made for the students of the [Algorithm Engineering course](http://didawiki.di.unipi.it/doku.php/magistraleinformaticanetworking/ae/ae2020/start) at the University of Pisa, contains code and instructions to set up an environment to experiment with the [Succinct Data Structure Library](https://github.com/simongog/sdsl-lite) (sdsl).

## Prerequisites

We recommend using the CLion IDE. More experienced users are free to use their preferred environment.

CLion includes a free 30-day trial, but you can [apply for free educational subscription](https://www.jetbrains.com/shop/eform/students) by either using your @studenti.unipi.it mail address or by logging in with your GitHub Student account.

### macOS

Open the terminal, run `xcode-select --install` and follow the instructions. If the command outputs "xcode-select: error: command line tools are already installed" you are ok.

Then, download CLion for macOS [here](https://www.jetbrains.com/clion/download/#section=mac) and copy it to your Applications folder.

### Linux

You need to install GCC version 4.9 or higher. On Debian/Ubuntu it suffices to run `sudo apt-get update && sudo apt-get install build-essential`.

Then, install CLion either [as a snap package](https://snapcraft.io/clion) or [via the tarball](https://www.jetbrains.com/help/clion/installation-guide.html#standalone).

### Windows 10

We recommend the use of the Windows Subsystem for Linux (WSL).
It allows you to program using CLion on Windows, and then to compile/run your code on a Linux distribution running alongside your traditional Windows desktop.

Download CLion for Windows [here](https://www.jetbrains.com/clion/download/#section=windows). Refer to [this guide](https://www.jetbrains.com/help/clion/how-to-use-wsl-development-environment-in-clion.html) for installing WSL and configuring CLion.

## Building and running the code

1. Click "Open or Import" on the CLion's [Welcome screen](https://www.jetbrains.com/help/clion/welcome-screen.html).
2. Select the directory that contains this README.
3. Wait that the IDE and CMake load the project (check the status bar at the bottom of the window).
4. Click ![run](https://www.jetbrains.com/help/img/idea/2020.2/icons.actions.execute.svg).

An output pane should show up with the following content:

```
/AE2020-tutorial/cmake-build-debug/tutorial
57
1 1 2 3 5 8

Process finished with exit code 0
```
