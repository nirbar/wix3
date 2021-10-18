// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.

namespace Microsoft.Tools.WindowsInstallerXml
{
    /// <summary>
    /// MSI instance info for binding Bundles.
    /// </summary>
    internal class MsiInstanceInfo : Row
    {
        public MsiInstanceInfo(Row msiInstanceRow) : base(msiInstanceRow)
        {
            this.InstancePackageId = (string)msiInstanceRow[0];
            this.ParentPackageId = (string)msiInstanceRow[1];
            this.InstanceId = (string)msiInstanceRow[2];
        }

        public string InstancePackageId { get; set; }
        public string ParentPackageId { get; set; }
        public string InstanceId { get; set; }
    }
}
