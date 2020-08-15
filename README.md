# s-mutt
_A secure profile system for the Mutt text-based mail client_
## Installation
> TL;DR `./configure && make && sudo make install`. \
To install, first make sure that you have Mutt and ncurses installed: \
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
_Solus_
```sh-script
$ sudo eopkg it mutt ncurses-devel
```
To install, use the tried-and-true combination of `./configure`, `make` and `make install`. \
To uninstall, use `make uninstall`. If you used a custom `PREFIX` with `make install`, be sure to use that here too. \
The default `PREFIX` is `/usr`. \
<br/><br/>
_S-Mutt has been tested on Fedora, macOS El Capitan, MX Linux, Solus and Android._

