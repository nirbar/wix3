# Panel::Software Customized WiX Edition

[Panel::Software](http://www.panel-sw.com) provides a customized edition of WiX built on top of WiX 3.11.2 with the following changes

- Fix WiX issue [6252](https://github.com/wixtoolset/issues/issues/6252): Fix reboot with related bundles when "-norestart" is specified on command line
- [Bundle/@RunAsAdmin](https://github.com/wixtoolset/issues/issues/5309) attribute creates a bootstrapper that requires elevation when launched
- Support [MSI transactions](https://github.com/wixtoolset/issues/issues/5386): Execute multiple MSI/MSP packages as an atomic package with unified commit/rollback behavior.
- Add attribute MediaTemplate/@AggressiveSmartCabbing:
  Whether or not to reuse equivalent files' cab entry. Versioned files are considered equivalent if they have equal name, size, version, and language. Unversioned files are considered equivalent if they have equal size and MD5 hash value.
  When a file is found to have an equivalent, it is placed in the same cab file and it's source is changed to the same source, so WiX built-in Smart Cabbing reuses the same cab entry for both files. 
  AggressiveSmartCabbing only works on compressed, non-patch-added, and not merged-moduled files.
- Support canceling the build when using MSBuild
- [RemotePayload](https://wixtoolset.org/documentation/manual/v3/xsd/wix/remotepayload.html) can be specified on any package payload rather than the main setup file
- Add [heat.exe](https://wixtoolset.org/documentation/manual/v3/overview/heat.html) harvest type "payload_dir" to harvest a PayloadGroup. Specify _-url link_ to set base DownloadUrl for remote payloads
- Fix WiX issue [6144](https://github.com/wixtoolset/issues/issues/6144): Support multiple attached containers in bundles. Enables bootstrappers larger than 2GB
- Fix WiX issue [6174](https://github.com/wixtoolset/issues/issues/6174): Fix bloated bootstrapper when authoring detached containers
- Fix Wix issue [6309](https://github.com/wixtoolset/issues/issues/6309): Fix non-vital rollback boundary handling of failures.
- Fix WiX issue [6298](https://github.com/wixtoolset/issues/issues/6298): Fix extracting bootstrappers with detached containers
- Fix WiX issue [6348](https://github.com/wixtoolset/issues/issues/6348): Fix .NET chaining response to files-in-use message.
- Fix WiX issue [6450](https://github.com/wixtoolset/issues/issues/6450): Support multiple firewall rules with the same name.
- When using MSBuild HarvestDirectory target, support generating a random preprocessor variable
- Changes by WiX up to git commit 376423b8101f4b59ee865e8a255cfe190fa5a7f1
- Build for .NET Framework 4.0

# WiX Toolset on GitHub
The WiX Toolset builds Windows installation packages from XML source code. The toolset supports a command-line environment that developers may integrate into their build processes to build Windows Installer (MSI) packages and executable bundles. The WiX GitHub project hosts the WiX source code Git repositories. The following links will take you to more details:

## [WiX Toolset home page](http://wixtoolset.org/)
## [WiX Toolset stable and weekly releases](http://wixtoolset.org/releases/)
## [Files bugs and feature requests for WiX Toolset](http://wixtoolset.org/bugs/)
## [WiX Toolset manuals and documentation links](http://wixtoolset.org/documentation/manual/)
## [About development on the WiX Toolset](http://wixtoolset.org/development/)
