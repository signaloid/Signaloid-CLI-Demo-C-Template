[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-dark-latest.png#gh-dark-mode-only" alt="[Add to signaloid.io]" height="30">](https://github.com/signaloid/Signaloid-CLI-Demo-C-Template#gh-dark-mode-only)
[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-light-latest.png#gh-light-mode-only" alt="[Add to signaloid.io]" height="30">](https://github.com/signaloid/Signaloid-CLI-Demo-C-Template#gh-light-mode-only)


# Template for CLI tool with single `main()`
This template is a minimal working C demo used for creating a web app via the [Signaloid CLI Tool](https://github.com/signaloid/signaloid-cli-tool). 


## Requirements
The `signaloid-cli` tool requires the [Signaloid-Demo-CommonUtilityRoutines](https://github.com/signaloid/Signaloid-Demo-CommonUtilityRoutines) routines command-line argument parsing and the ability to print to `json` format.

## Usage:
```
Command-line arguments:
[-k [Input value of the demo. Can be a single value or a Ux String.]
```
For more details on Ux Strings, visit the [Signaloid public documentation page](https://docs.signaloid.io/docs/hardware-api/ux-data-format/).



## Cloning the Repository 
The correct way to clone this repository is:
```
git clone --recursive https://github.com/signaloid/Signaloid-CLI-Demo-C-Template.git
```
To update all submodules
```
git pull --recurse-submodules
git submodule update --remote --recursive
```
If you forgot to clone with `--recursive`, and end up with empty submodule directories, you can remedy this with
```
git submodule update --init --recursive
```
