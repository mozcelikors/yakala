# yakala
A visual helper tool for Linux: Show system statistics, search for files, search for networks, and modify your aliases.

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

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/Selection_004.png)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/image916.png)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/image2022.png)

![alt text](https://raw.githubusercontent.com/mozcelikors/yakala/master/docs/img/image2575.png)


## Contributions

Contributions are more than welcome. Please create a descriptive pull request.
