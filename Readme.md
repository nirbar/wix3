# Panel::Software Customized WiX Edition

[Panel::Software](http://www.panel-sw.co.il) provides a customized edition of WiX built on top of WiX 3.11.2 with the following changes

- [Bundle/@RunAsAdmin](https://github.com/wixtoolset/issues/issues/5309) attribute created a bootstrapper that requires elevation when launched
- [RemotePayload](https://wixtoolset.org/documentation/manual/v3/xsd/wix/remotepayload.html) can be specified on any package payload rather than the main setup file
- Add [heat.exe](https://wixtoolset.org/documentation/manual/v3/overview/heat.html) harvest type "payload_dir" to harvest a PayloadGroup. Specify _-url link_ to set base DownloadUrl for remote paylodas
- Fix WiX issue [6144](https://github.com/wixtoolset/issues/issues/6144): Support multiple attached containers in bundles. Allow bootstrappers larger than 2GB
- Fix WiX issue [6174](https://github.com/wixtoolset/issues/issues/6174): Fix discovery of payloads with no container that need to be assigned to the default container
- Changes by WiX up to build 3.14.0.4118
- Build for .NET Framework 4.0

# WiX Toolset on GitHub
The WiX Toolset builds Windows installation packages from XML source code. The toolset supports a command-line environment that developers may integrate into their build processes to build Windows Installer (MSI) packages and executable bundles. The WiX GitHub project hosts the WiX source code Git repositories. The following links will take you to more details:

## [WiX Toolset home page](http://wixtoolset.org/)
## [WiX Toolset stable and weekly releases](http://wixtoolset.org/releases/)
## [Files bugs and feature requests for WiX Toolset](http://wixtoolset.org/bugs/)
## [WiX Toolset manuals and documentation links](http://wixtoolset.org/documentation/manual/)
## [About development on the WiX Toolset](http://wixtoolset.org/development/)
