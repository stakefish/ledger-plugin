[![Ensure compliance with Ledger guidelines](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/guidelines_enforcer.yml/badge.svg?branch=develop)](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/guidelines_enforcer.yml)
[![Compilation & tests](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/build_and_functional_tests.yml/badge.svg?branch=develop)](https://github.com/LedgerHQ/app-plugin-boilerplate/actions/workflows/build_and_functional_tests.yml)

# stakefish plugin

This repo is a fork from Ledger's [app-plugin-boilerplate](https://github.com/LedgerHQ/app-plugin-boilerplate).

It was created following the
[plugin guide](https://developers.ledger.com/docs/dapp/embedded-plugin/code-overview/).

To build and test the plugin, use the [Ledger's VSCode developer tools extension](https://marketplace.visualstudio.com/items?itemName=LedgerHQ.ledger-dev-tools). You need to first copy the Ethereum plugin builds inside the `tests/ethereum_build` as mentioned in the README file inside the `tests` folder. After that just run the command '_Build_' in the Ledger extension and then '_Run tests_'.

### Loading on a physical device

This step will vary slightly depending on your platform.

:information_source: Your physical device must be connected, unlocked and the screen showing the dashboard (not inside an application).

**Linux (Ubuntu)**

First make sure you have the proper udev rules added on your host :

```shell
# Run these commands on your host, from the app's source folder.
sudo cp .vscode/20-ledger.ledgerblue.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
```

Then once you have [opened a terminal](#with-a-terminal) in the `app-builder` image and [built the app](#compilation-and-load) for the device you want, run the following command :

```shell
# Run this command from the app-builder container terminal.
make load    # load the app on a Nano S by default
```

[Setting the BOLOS_SDK environment variable](#compilation-and-load) will allow you to load on whichever supported device you want.

**macOS / Windows (with PowerShell)**

:information_source: It is assumed you have [Python](https://www.python.org/downloads/) installed on your computer.

Run these commands on your host from the app's source folder once you have [built the app](#compilation-and-load) for the device you want :

```shell
# Install Python virtualenv
python3 -m pip install virtualenv
# Create the 'ledger' virtualenv
python3 -m virtualenv ledger
```

Enter the Python virtual environment

- macOS : `source ledger/bin/activate`
- Windows : `.\ledger\Scripts\Activate.ps1`

```shell
# Install Ledgerblue (tool to load the app)
python3 -m pip install ledgerblue
# Load the app.
python3 -m ledgerblue.runScript --scp --fileName bin/app.apdu --elfFile bin/app.elf
```
