VNC_CLIENT

Description
It's an VNC client used to connect to machine that are providing VNC server connection on port 5900.
Port may be changed in source. Currently it's static.
Application is based on GTK3 and gtk-vnc libraries. It uses dynamically linked libraries so thoselibraries are a must on target device.

Useful links:
https://docs.gtk.org/gtk3/
https://wiki.gnome.org/Projects/gtk-vnc
https://lazka.github.io/pgi-docs/GtkVnc-2.0/index.html

How to use?
1. Compile application
2. Open application
3. Provide target IP address
![obraz](https://github.com/aborowy1/vnc_client/assets/72155321/01b0ca4c-fe09-4e8f-bd62-82267d00e703)
5. Click "Connect"
6. Provide password if any, if no need of password leave empty
![obraz](https://github.com/aborowy1/vnc_client/assets/72155321/d4780cbf-14b4-4298-a1e4-492c25d3bf28)
8. Click "Unlock"
9. Wait for connection
![obraz](https://github.com/aborowy1/vnc_client/assets/72155321/54087714-b330-49e2-aa35-2ac24402d7d9)
10. To disconnect close an app

To do in the future:
- option to change port,
- add additional buttons to manage disconnecting,
- changing order of passing password (to avoid providing password if the targetmachine does not require it).

AB 2024
