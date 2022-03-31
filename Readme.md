# Panel::Software Customized WiX Edition

[Panel::Software](http://www.panel-sw.com) provides a customized edition of WiX built on top of WiX 3.11.2 with the following changes

- [6252](https://github.com/wixtoolset/issues/issues/6252): Fix reboot with related bundles when "-norestart" is specified on command line
- [Bundle/@RunAsAdmin](https://github.com/wixtoolset/issues/issues/5309) attribute creates a bootstrapper that requires elevation when launched
- Support [MSI transactions](https://github.com/wixtoolset/issues/issues/5386): Execute multiple MSI/MSP packages as an atomic package with unified commit/rollback behavior.
- Add attribute MediaTemplate/@AggressiveSmartCabbing:
  Whether or not to reuse equivalent files' cab entry. Versioned files are considered equivalent if they have equal name, size, version, and language. Unversioned files are considered equivalent if they have equal size and MD5 hash value.
  When a file is found to have an equivalent, it is placed in the same cab file and it's source is changed to the same source, so WiX built-in Smart Cabbing reuses the same cab entry for both files. 
  AggressiveSmartCabbing only works on compressed, non-patch-added, and not merged-moduled files.
- [6521](https://github.com/wixtoolset/issues/issues/6521): Support auto-assign of payloads to containers in bundles.
- Support canceling the build when using MSBuild
- [RemotePayload](https://wixtoolset.org/documentation/manual/v3/xsd/wix/remotepayload.html) can be specified on any package payload rather than the main setup file
- Add [heat.exe](https://wixtoolset.org/documentation/manual/v3/overview/heat.html) harvest type "payload_dir" to harvest a PayloadGroup. Specify _-url link_ to set base DownloadUrl for remote payloads
- [6144](https://github.com/wixtoolset/issues/issues/6144): Support multiple attached containers in bundles. Enables bootstrappers larger than 2GB
- [6174](https://github.com/wixtoolset/issues/issues/6174): Fix bloated bootstrapper when authoring detached containers
- [6309](https://github.com/wixtoolset/issues/issues/6309): Fix non-vital rollback boundary handling of failures.
- [6298](https://github.com/wixtoolset/issues/issues/6298): Fix extracting bootstrappers with detached containers
- [6348](https://github.com/wixtoolset/issues/issues/6348): Fix .NET chaining response to files-in-use message.
- [6450](https://github.com/wixtoolset/issues/issues/6450): Support multiple firewall rules with the same name.
- [6472](https://github.com/wixtoolset/issues/issues/6472): Bundle can install multi-instance MSI packages. See [Authoring Multiple Instances with Instance Transforms](https://docs.microsoft.com/en-us/windows/win32/msi/authoring-multiple-instances-with-instance-transforms).
- [5220](https://github.com/wixtoolset/issues/issues/5220): Automatically add logging flag for any burn ExePackage and related bundles
- [1488](https://github.com/wixtoolset/issues/issues/1488): Add -inc "**.pat1;**.pat2" and -exc "**.pat3;**.pat4" options to heat dir to include and exclude files matching widlcard patterns
- Add -ssub flag to heat dir to harvest files in top folder only and skip subfolders
- Add binder variables: !(bind.packageVersion.Major.ID), !(bind.packageVersion.Minor.ID), !(bind.packageVersion.Build.ID), !(bind.packageVersion.Revision.ID)
- Util extension PermissionEx: Registry permissions are inheritable
- When using MSBuild HarvestDirectory target, support generating a random preprocessor variable
- Add attribute Chain/@Restart: "yes" to force restart; "no" to disable restart
- Add command line flag "-autorestart" to restart if needed
- wixstdba: Specifying "-forcerestart' on the command line forces reboot at the end of the installation
- Changes by WiX up to git commit 376423b8101f4b59ee865e8a255cfe190fa5a7f1
- Build for .NET Framework 4.0

# WiX Toolset on GitHub
The WiX Toolset builds Windows installation packages from XML source code. The toolset supports a command-line environment that developers may integrate into their build processes to build Windows Installer (MSI) packages and executable bundles. The WiX GitHub project hosts the WiX source code Git repositories. The following links will take you to more details:

## [WiX Toolset home page](http://wixtoolset.org/)
## [WiX Toolset stable and weekly releases](http://wixtoolset.org/releases/)
## [Files bugs and feature requests for WiX Toolset](http://wixtoolset.org/bugs/)
## [WiX Toolset manuals and documentation links](http://wixtoolset.org/documentation/manual/)
## [About development on the WiX Toolset](http://wixtoolset.org/development/)
