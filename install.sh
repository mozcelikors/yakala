#!/bin/bash

# Installes prerequisites and builds 'yakala'

## Check for the distro
if [ -f /etc/os-release ]; then
    # freedesktop.org and systemd
    . /etc/os-release
    OS=$NAME
    VER=$VERSION_ID
elif type lsb_release >/dev/null 2>&1; then
    # linuxbase.org
    OS=$(lsb_release -si)
    VER=$(lsb_release -sr)
elif [ -f /etc/lsb-release ]; then
    # For some versions of Debian/Ubuntu without lsb_release command
    . /etc/lsb-release
    OS=$DISTRIB_ID
    VER=$DISTRIB_RELEASE
elif [ -f /etc/debian_version ]; then
    # Older Debian/Ubuntu/etc.
    OS=Debian
    VER=$(cat /etc/debian_version)
elif [ -f /etc/SuSe-release ]; then
    # Older SuSE/etc.
    ...
elif [ -f /etc/redhat-release ]; then
    # Older Red Hat, CentOS, etc.
    ...
else
    # Fall back to uname, e.g. "Linux <version>", also works for BSD, etc.
    OS=$(uname -s)
    VER=$(uname -r)
fi

echo "Checking for required packages..."

## Check for qt5-default
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' qt5-default | grep "install ok installed")
echo "Checking for qt5-default: $PKG_OK"
if [ "" == "$PKG_OK" ]; then
  echo "No qt5. Setting up qt5."
  sudo apt-get --force-yes --yes install qt5-default
fi

## Check for nmap
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' 'nmap' | grep "install ok installed")
echo "Checking for nmap: $PKG_OK"
if [ "" == "$PKG_OK" ]; then
  echo "No nmap. Setting up nmap."
  sudo apt-get --force-yes --yes install nmap
fi

## Make
echo "Compiling yakala..."
qmake yakala.pro -r -spec linux-g++-64 CONFIG+=debug
rm -rf build && mkdir -p build
make
make install

echo "Done. Run the executable in build/yakala."
echo "If you like it, set up an alias for it ;)"
