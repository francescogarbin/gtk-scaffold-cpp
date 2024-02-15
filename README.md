# GTK Scaffold C++
A GTK 4 desktop application written in C++ 17 that serves as scaffold for desktop
software designed for the Gnome environment.

![scaffoild](https://github.com/francescogarbin/gtk-scaffold-cpp/assets/571018/a76c1968-a446-404a-b097-81c9e28f0959)

The app provides all the UI widgets of a typical desktop application such as:
- three panes layout
- status bar
- toolbar
- menu button with menu items
- about dialog box
- preferences dialog box (empty of course)

Use and reuse this scaffolding app for your projects, it's released
under a pretty generous license.

The build system is Ninja/Meson and can be compiled onto any modern Linux
version.

### Prerequisites
Make sure to install:
- Meson with all required components, check https://mesonbuild.com/Quick-guide.html
- gtkmm4, check https://gtkmm.org/en/download.html
- glib, check https://tldp.org/LDP/lfs/5.0/html/chapter05/glibc.html
- gcc and the usual C++ development tools for Linux

### Building GTK Scaffold C++
Compile from terminal with the followings:
<pre>$ cd /path/to/source/root
$ meson setup builddir && cd builddir
$ meson compile
$ meson test
</pre>

### Getting support

For support and suggestions do not hesitate to touch base with me at
francescogarbin@gmail.com, I'll be happy to hear from you :-)
