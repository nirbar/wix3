<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:nuspec="http://schemas.microsoft.com/packaging/2013/01/nuspec.xsd"
                xmlns:msxsl="urn:schemas-microsoft-com:xslt" exclude-result-prefixes="msxsl nuspec">
    <xsl:output method="xml" indent="yes"/>
    <xsl:param name="NUSPEC_VS_VERSION" select="2017"/>

    <xsl:template match="@* | node()">
        <xsl:copy>
            <xsl:apply-templates select="@* | node()"/>
        </xsl:copy>
    </xsl:template>

    <xsl:template match="//nuspec:file[contains(./@src, '\2017\')]">
        <nuspec:file>
            <xsl:attribute name="src">
                <xsl:value-of select="concat( substring-before(./@src, '\2017\'), '\', $NUSPEC_VS_VERSION, '\', substring-after(./@src, '\2017\'))"/>
            </xsl:attribute>
            <xsl:attribute name="target">
                <xsl:value-of select="concat( substring-before(./@target, '\vs2017\'), '\vs', $NUSPEC_VS_VERSION, '\', substring-after(./@target, '\vs2017\'))"/>
            </xsl:attribute>
        </nuspec:file>
    </xsl:template>
</xsl:stylesheet>