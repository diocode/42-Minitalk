![so_long_banner-03](https://github.com/diocode/42-So_long/assets/107859177/f2d4d204-c35c-4eef-bb63-09aea6376882)

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/evaluated-17%20%2F%2004%20%2F%202023-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/badge/score-104%20%2F%20100-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/last-commit/diocode/philosophers?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/diogo-gsilva' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#norminette">Norminette</a>
</p>

## ABOUT ([Subject](/.github/en.subject.pdf))

The project involves creating a client-server communication program that relies exclusively on UNIX signals, specifically SIGUSR1 and SIGUSR2, for communication. The server starts first, rapidly displays received strings, and thoroughly manages errors. A bonus aspect includes implementing message acknowledgment and Unicode character support.

<a href="/.github/en.subject.pdf">Click here</a> for the subject of this project.

<br>

## HOW TO USE
#### COMPILATION AND EXECUTION
#### 1º - Clone the repository
```bash
$ git clone git@github.com:diocode/42-Minitalk.git
```

#### 2º - Enter the project folder and run `make` or `make bonus`
```bash
$ ./cd 42-Minitalk
$ ./make
$ ./make bonus
```

#### 3º - Launch the program
> You need to launch both the `server` and `client` in separate terminals for the program to work properly
#### Mandatory:
> Launch the `server` first to get the `PID`
```bash
$ ./server
```
> Then launch the `client` using the `PID` from server
```bash
$ ./client [PID] [message]
```
#### Bonus:
> Launch the `server_bonus` first to get the `PID`
```bash
$ ./server_bonus
```
> Then launch the `client_bonus` using the `PID` from server
```bash
$ ./client_bonus [PID] [message]
```

<br>

#### MAKEFILE COMMANDS
`make` or `make all` - Compile program **mandatory** files.

`make bonus` - Compile program **bonus** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

<br>

## NORMINETTE
At 42 School, projects are generally expected to adhere to the Norm, the school's coding standard:

```
- No for, do while, switch, case or goto are allowed
- No more than 25 lines per function and 5 functions per file
- No assigns and declarations in the same line (unless static)
- No more than 5 variables in 1 function
... 
```

* [Norminette](https://github.com/42School/norminette) - Tool by 42, to respect the code norm. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`
