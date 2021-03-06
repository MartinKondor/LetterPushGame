<p align="center">
    <img src="docs/images/readme.png" width="250" style="box-shadow: 1px 2px 50px rgb(70, 70, 70);">
</p>

# LetterPushGame
[![version](https://img.shields.io/badge/version-v1.2-green.svg)](https://github.com/MartinKondor/LetterPushGame)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://github.com/MartinKondor/LetterPushGame)
[![GitHub Issues](https://img.shields.io/github/issues/MartinKondor/LetterPushGame.svg)](https://github.com/MartinKondor/LetterPushGame/issues)
![Contributions welcome](https://img.shields.io/badge/contributions-welcome-orange.svg)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

Simple console based game built in C++ for windows.

## How to play

The game starts with a grid of characters on the screen, there are 3 kinds:

- **Obstacles** which you can't move, can't go over and generally they do nothing. (#)
- **Letters** simple letters from the alphabet, these can be pushed anywhere on the grid plane.
- **Player** the only character you can move and push the letters with. (@)

Your task is to move all the letters on the plane in a way that they spell out the original word.

For example "a# bc" is not correct but "abc" is.

## Getting Started

### Prerequisites

* Windows 7/8/8.1/10 operating system
* GCC Compiler with C++ 17

## Deployment

If the building was successful and the `bin/game.exe` file were created but the game didn't start or it immediatly crashed, then copy the `libgcc_s_sjlj-1.dll` dll file to the `bin` directory and try again.

## Built With

* [GCC](https://gcc.gnu.org/) - Compiler used

## Contributing

This project is open for any kind of contribution from anyone.

### Steps

1. Fork this repository
2. Create a new branch (optional)
3. Clone it
4. Make your changes
5. Upload them
6. Make a pull request here

## Authors

* **[Martin Kondor](https://github.com/MartinKondor)**

<p align="center"><a href="https://www.patreon.com/bePatron?u=17006186" data-patreon-widget-type="become-patron-button"><img width="222" class="img-responsive" alt="Become a Patron!" title="Become a Patron!" src="https://martinkondor.github.io/img/become_a_patron_button.png"></a></p>

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
