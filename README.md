# yakala
A visual helper tool for GNU/Linux. Made with love.

## Features 

* Show system statistics: CPU, Memory, Disk stats and system information
* Search for files
* Search for networks
* SSH into networks
* See active TCP/UDP sockets
* Modify your aliases
* Search and kill processes
* List environment variables

New features involve (as of Feb 15, 2018):

* SSHing into networks
* Listing activeTCP/UDP sockets

## Animation

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/peek.gif)

## Compiling

```bash
git clone https://github.com/mozcelikors/yakala
cd yakala && ./install.sh
```

or Manually install:

```bash
git clone https://github.com/mozcelikors/yakala
cd yakala
qmake yakala.pro -r -spec linux-g++-64 CONFIG+=debug
mkdir -p build
make
```


## Running

Installation script (first method) will automatically create a desktop icon for you. You can use that icon or execute the following to run Yakala:

```bash
cd <yakala-dir>/build
sudo ./yakala
```

## Screenshots

Here are some of the screenshots:

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/Selection_005.png)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/Selection_004.png)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/image916.png)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/image2022.png)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/image2575.png)


## Contributions

Contributions are more than welcome. Please create a descriptive pull request.
