# yakala
A visual helper tool for GNU/Linux. Made with love.

## Features 

* Show system statistics: CPU, Memory, Disk stats and system information
* Visualize recent CPU and Memory activity
* Search for files
* Search for networks
* SSH into networks
* See active TCP/UDP sockets
* Modify your aliases
* Search and kill processes
* List environment variables

New features involve (as of Feb 15, 2018):

* File browsing
* Visualize recent CPU and Memory activity
* SSHing into networks
* Listing activeTCP/UDP sockets

## Download using Debian/Ubuntu PPA:

```bash
sudo add-apt-repository ppa:mozcelikors/yakala
sudo apt-get update
sudo apt-get install yakala
```

## Animations

### System Information:

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/peekx1.gif)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/peek2.gif)

### Network:

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/peekx2.gif)

### File Searching:

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/peekx3.gif)

### Processes, Aliases, Variables:

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/peekx4.gif)

## Compiling from Source

```bash
git clone https://github.com/mozcelikors/yakala
cd yakala && ./install.sh
```

## Running

Installation script will automatically create a desktop icon for you. You can use that icon or execute the following to run Yakala:

```bash
cd <yakala-dir>/build
sudo ./yakala
```

## Contributions

Contributions are more than welcome. Please create a descriptive pull request.
