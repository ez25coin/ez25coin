Repository Tools
---------------------

### [Developer tools](/contrib/devtools) ###
Specific tools for developers working on this repository.
Contains the script `github-merge.py` for merging GitHub pull requests securely and signing them using GPG.

### [Verify-Commits](/contrib/verify-commits) ###
Tool to verify that every merge commit was signed by a developer using the above `github-merge.py` script.

### [Linearize](/contrib/linearize) ###
Construct a linear, no-fork, best version of the blockchain.

### [Qos](/contrib/qos) ###

A Linux bash script that will set up traffic control (tc) to limit the outgoing bandwidth for connections to the EZ25COIN network. This means one can have an always-on ez25coind instance running, and another local ez25coind/ez25coin-qt instance which connects to this node and receives blocks from it.

### [Seeds](/contrib/seeds) ###
Utility to generate the pnSeed[] array that is compiled into the client.

Build Tools and Keys
---------------------

### Packaging ###
The [Debian](/contrib/debian) subfolder contains the copyright file.

All other packaging related files can be found in the [ez25coin-core/packaging](https://github.com/ez25coin-core/packaging) repository.

### [Gitian-descriptors](/contrib/gitian-descriptors) ###
Files used during the gitian build process. For more information about gitian, see the [the EZ25COIN Core documentation repository](https://github.com/ez25coin-core/docs).

### [Gitian-keys](/contrib/gitian-keys)
PGP keys used for signing EZ25COIN Core [Gitian release](/doc/release-process.md) results.

### [MacDeploy](/contrib/macdeploy) ###
Scripts and notes for Mac builds. 

### [Gitian-build](/contrib/gitian-build.py) ###
Script for running full Gitian builds.

Test and Verify Tools 
---------------------

### [TestGen](/contrib/testgen) ###
Utilities to generate test vectors for the data-driven EZ25COIN tests.

### [Verify Binaries](/contrib/verifybinaries) ###
This script attempts to download and verify the signature file SHA256SUMS.asc from ez25coin.org.