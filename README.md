# xkb-keyboard-indicator

XKB Keyboard indicator. It's indicator in Unity and KDE and regular systray application in other DE/WMs.

## Status

Currently only indicator and initial settings dialog are available.

## TODO

[x] Migrate to CMake from plain old Makefile
[ ] BUG: Sometimes settings are changed from outside (manual re-applying is needed)

## Installation

    # build
    mkdir build
    cd build
    cmake ..
    make

    # copy settings schema
    sudo sudo cp -f data/xki.gschema.xml /usr/share/glib-2.0/schemas
    sudo glib-compile-schemas /usr/share/glib-2.0/schemas

    # run
    ./src/xki

Only manual installation is available at the moment. You may copy `src/xki` to somewhere in your path (e.g. `/usr/local/bin`).

## Usage

### Simple

Use settings dialog to set basic layouts and options.

### Advanced

Set `layouts` and `options` in `/app/xki/` in gsettings (e.g., via `dconf-editor`).

## Requirements

You'll need CMake, GTK+ 3, GLib, LibXklavier and AppIndicator3-0.1.

    sudo apt-get install cmake libgtk-3-dev libglib2.0-dev libxklavier-dev libappindicator3-dev

## License

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
