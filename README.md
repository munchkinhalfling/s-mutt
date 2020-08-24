# s-mutt
_A secure profile system for the Mutt text-based mail client_
## Installation
### Via [`hubcap`](https://github.com/munchkinhalfling/hubcap) ((npm)[https://npmjs.com/@munchkinhalfling/hubcap])
Simply run:
```sh
$ sudo hubcap install munchkinhalfling/s-mutt
```
Then, `smutt` and `smutt.genconf` will be available in `/usr/bin`.
### From source (Linux, macOS, Unix)
See `INSTALL`.
### From binary release (smutt-xxx-bin.tar.gz) (Linux only)
Unzip the downloaded package, `cd` into the generated directory and run `sudo ./install.sh` to install.
## Dependencies
- The `mutt` mail client (usually in a package called `mutt`)
- Ncurses (use the development package, e.g. `ncurses-devel`, `libncurses-devel`, `libncurses5-dev`, etc.)

_S-Mutt has been tested on Fedora, macOS El Capitan, MX Linux, Solus and Android._

