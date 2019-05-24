# s-mutt
_A secure profile system for the Mutt text-based mail client_
## Installation
To install, first make sure that you have Mutt installed:<br/>
_Fedora_
```sh-script
$ sudo dnf install mutt
```
_Debian_
```sh-script
$ sudo apt-get install mutt
```
Then, remove your `~/.muttrc`. Create a directory called `~/mutt-config`. Then, symlink the `smutt` and `genconf/genconf` executables to somewhere in your PATH as `smutt` and `smutt.genconf`, respectively.
Then, launch s-mutt using the command `smutt`. At the first prompt, type **`new`** to create a new profile. Follow the on-screen prompts to create a new profile.
Then, relaunch s-mutt and type the name of your new profile at the first prompt. Type your Gmail password at the second prompt. Then, it will launch Mutt.
