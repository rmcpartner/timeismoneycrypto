
Debian
====================
This directory contains files used to package timeismoneyd/timeismoney-qt
for Debian-based Linux systems. If you compile timeismoneyd/timeismoney-qt yourself, there are some useful files here.

## timeismoney: URI support ##


timeismoney-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install timeismoney-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your timeismoneyqt binary to `/usr/bin`
and the `../../share/pixmaps/timeismoney128.png` to `/usr/share/pixmaps`

timeismoney-qt.protocol (KDE)

