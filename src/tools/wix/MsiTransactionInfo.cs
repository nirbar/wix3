// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.

namespace Microsoft.Tools.WindowsInstallerXml
{
    using System;

    /// <summary>
    /// Rollback boundary info for binding Bundles.
    /// </summary>
    internal class MsiTransactionInfo
    {
        public enum TransactionBitness
        {
            None,
            X86,
            X64,
        }
        
        public MsiTransactionInfo(string id)
        {
            this.Default = true;
            this.Id = id;
            this.LogPathVariable = "WixBundleLog_" + id;
        }

        public MsiTransactionInfo(Row row)
        {
            this.Id = row[0].ToString();
            LogPathVariable = row[15] as string;
            this.SourceLineNumbers = row.SourceLineNumbers;
            Bitness = TransactionBitness.None;
        }

        public bool Default { get; private set; }
        public string Id { get; private set; }
        public string LogPathVariable { get; private set; }
        public SourceLineNumberCollection SourceLineNumbers { get; private set; }
        public string EndTransactionId { get; set; }
        public TransactionBitness Bitness { get; set; }
    }
}
