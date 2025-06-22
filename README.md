[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![License](https://img.shields.io/badge/License-Boost_1.0-lightblue.svg)](https://www.boost.org/LICENSE_1_0.txt)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![License: CC BY-SA 4.0](https://img.shields.io/badge/License-CC_BY--SA_4.0-lightgrey.svg)](https://creativecommons.org/licenses/by-sa/4.0/)
# Lake is a clone of [Makefile](https://makefile.site/)

With lake, you can combine your work in any programming language you want into a single command.

# Lake is currently available on 3 systems
+ Windows
+ Linux
+ Mac (soon)

# Installing
## in Windows
```
git clone https://github.com/xurshidjohn/lake.git
```
### and open git bash
```
cd Downloads && cd lake-main/lake-main && bash ./install.sh
```

## in Linux

```
git clone https://github.com/xurshidjohn/lake.git
```
### and open terminal
```
cd lake && bash ./install.sh
```

# How to using Lake
### this code in build.lake file
```
[compile] = <gcc index.c -o app>
[run] = <./app>
[clear] = <rm app>
```

### and Terminal:
```
$ lake compile
$ lake run 
```
