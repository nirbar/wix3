// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.

namespace WixTest.Tests.Burn
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using Microsoft.Win32;
    using WixTest.Verifiers;
    using Xunit;

    public class TransactionTests : BurnTests
    {
        [NamedFact]
        [Priority(2)]
        [Description("Installs a bundle and controls the feature state for install/uninstall.")]
        [RuntimeTest]
        public void Burn_Install()
        {
            // Build the packages.
            string packageA = new PackageBuilder(this, "A").Build().Output;
            string packageB = new PackageBuilder(this, "B").Build().Output;
            string packageC = new PackageBuilder(this, "C").Build().Output;

            // Create the named bind paths to the packages.
            Dictionary<string, string> bindPaths = new Dictionary<string, string>();
            bindPaths.Add("packageA", Path.GetDirectoryName(packageA));
            bindPaths.Add("packageB", Path.GetDirectoryName(packageB));
            bindPaths.Add("packageC", Path.GetDirectoryName(packageC));

            string bundleA = new BundleBuilder(this, "BundleA") { BindPaths = bindPaths, Extensions = Extensions }.Build().Output;

            string packageASourceCodeInstalled = this.GetTestInstallFolder(@"A\A.wxs");
            string packageBSourceCodeInstalled = this.GetTestInstallFolder(@"B\B.wxs");
            string packageCSourceCodeInstalled = this.GetTestInstallFolder(@"C\C.wxs");

            // Source file should *not* be installed
            Assert.False(File.Exists(packageASourceCodeInstalled), String.Concat("Package A payload should not have been there before install from: ", packageASourceCodeInstalled));
            Assert.False(File.Exists(packageBSourceCodeInstalled), String.Concat("Package B payload should not have been there before install from: ", packageBSourceCodeInstalled));
            Assert.False(File.Exists(packageCSourceCodeInstalled), String.Concat("Package C payload should not have been there before install from: ", packageCSourceCodeInstalled));

            BundleInstaller install = new BundleInstaller(this, bundleA).Install();

            // Source file should be installed
            Assert.True(File.Exists(packageASourceCodeInstalled), String.Concat("Should have found Package A payload installed at: ", packageASourceCodeInstalled));
            Assert.True(File.Exists(packageBSourceCodeInstalled), String.Concat("Should have found Package B payload installed at: ", packageBSourceCodeInstalled));
            Assert.True(File.Exists(packageCSourceCodeInstalled), String.Concat("Should have found Package C payload installed at: ", packageCSourceCodeInstalled));


            // Uninstall everything.
            install.Uninstall();

            // Source file should *not* be installed
            Assert.False(File.Exists(packageASourceCodeInstalled), String.Concat("Package A payload should have been removed by uninstall from: ", packageASourceCodeInstalled));
            Assert.False(File.Exists(packageBSourceCodeInstalled), String.Concat("Package B payload should have been removed by uninstall from: ", packageBSourceCodeInstalled));
            Assert.False(File.Exists(packageCSourceCodeInstalled), String.Concat("Package C payload should have been removed by uninstall from: ", packageCSourceCodeInstalled));

            this.Complete();
        }
    }
}