#!/bin/bash

gcc -o ./target/app.out `pkg-config --cflags gtk+-3.0` `pkg-config --cflags gtk-vnc-2.0` ./src/*.c `pkg-config --libs gtk+-3.0` `pkg-config --libs gtk-vnc-2.0` -Wno-deprecated-declarations
cp -r ./src/images ./src/icons ./src/ui.glade ./target
