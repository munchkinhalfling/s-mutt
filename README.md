# s-mutt
_A secure profile system for the Mutt text-based mail client_
## Installation
### Via [`app`](https://github.com/munchkinhalfling/app) (Prefered over `hubcap`)
Just run:
```sh
$ app install munchkinhalfling/s-mutt
```
Then, `smutt` and `smutt.genconf` will be available in `~/.local/bin`.
### Via [`hubcap`](https://github.com/munchkinhalfling/hubcap) ((npm)[https://npmjs.com/@munchkinhalfling/hubcap])
Simply run:
```sh
$ sudo hubcap install munchkinhalfling/s-mutt
```
Then, `smutt` and `smutt.genconf` will be available in `/usr/bin`.
### From source
Install [bettermake](https://github.com/munchkinhalfling/bettermake). \
Then, clone this repository and run:
```sh
$ bettermake
$ prefix=/usr sudo bettermake build install
```
This will make `smutt` and `smutt.genconf` available in `/usr/bin`.
## Dependencies
- The `mutt` mail client (usually in a package called `mutt`)
- Ncurses (use the development package, e.g. `ncurses-devel`, `libncurses-devel`, `libncurses5-dev`, etc.)

_S-Mutt has been tested on Fedora, macOS El Capitan, MX Linux, Solus, Pop!\_OS and Android._

