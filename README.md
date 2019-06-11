# s-mutt
_A secure profile system for the Mutt text-based mail client_
## Installation
_If you have MX-Linux, skip to the next section._
To install, first make sure that you have Mutt and ncurses installed:<br/>
_Fedora/RedHat_
```sh-script
$ sudo dnf install mutt
$ sudo dnf install libncurses-devel
```
_Debian_
```sh-script
$ sudo apt-get install mutt
$ sudo apt-get install libncurses5-dev
```
To install, simply cd into the directory where you downloaded s-mutt and run either `make install-intel` or `make install-arm`, whichever architecture your computer has.
## Installation on MX-Linux
To install on MX-Linux, run the `install.mx` file. Don't even install the packages beforehand; the script handles all that.
<br/><br/>
_S-Mutt has been tested on Fedora, macOS El Capitan, MX Linux and Android._

