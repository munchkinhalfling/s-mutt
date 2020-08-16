#!/bin/bash
# Install the binary package
prefix=${1:-/usr/local}
echo -e '\e[32mInstalling binaries...\e[0m'
echo -e '\e[1;32m% \e[2;33mcp smutt $prefix/bin/\e[0m'
cp smutt $prefix/bin/
echo -e '\e[1;32m% \e[2;33mcp smutt.genconf $prefix/bin/\e[0m'
cp smutt.genconf $prefix/bin/