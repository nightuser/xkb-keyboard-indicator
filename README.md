# xkb-keyboard-indicator
XKB Keyboard indicator for Unity.

## Status

Currently only indicator is avaiable.

## Usage

Set xorg xkb settings via `xorg.conf` of `setxkbmap`.

Example (English and Russian layouts with Caps-toggle):

    setxkbmap -layout "us,ru"
    setxkbmap -option "grp:caps_toggle,grp_led:scroll"

## Requirements

You need GTK+3.0, GLIB-2.0, libXKlavier and libAppIndicator3.

    sudo apt-get install libgtk-3-dev libglib2.0-dev libxklavier-dev libappindicator3-dev
