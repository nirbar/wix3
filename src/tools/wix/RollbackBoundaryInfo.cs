// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.

namespace Microsoft.Tools.WindowsInstallerXml
{
    using System;

    /// <summary>
    /// Rollback boundary info for binding Bundles.
    /// </summary>
    internal class RollbackBoundaryInfo
    {
        public RollbackBoundaryInfo(string id, YesNoType transaction)
        {
            this.Default = true;
            this.Id = id;
            this.Vital = YesNoType.Yes;
            this.Transaction = transaction;
            if (YesNoType.Yes == Transaction)
            {
                this.LogPathVariable = "WixBundleLog_" + id;
            }
        }

        public RollbackBoundaryInfo(Row row)
        {
            this.Id = row[0].ToString();

            this.Vital = (null == row[10] || 1 == (int)row[10]) ? YesNoType.Yes : YesNoType.No;
            this.Transaction = (1 == row[23] as int?) ? YesNoType.Yes : YesNoType.No;
            if (YesNoType.Yes == Transaction)
            {
                LogPathVariable = row[15] as string;
            }
            this.SourceLineNumbers = row.SourceLineNumbers;
        }

        public bool Default { get; private set; }
        public string Id { get; private set; }
        public YesNoType Vital { get; private set; }
        public YesNoType Transaction { get; private set; }
        public string LogPathVariable { get; private set; }
        public SourceLineNumberCollection SourceLineNumbers { get; private set; }
    }
}
