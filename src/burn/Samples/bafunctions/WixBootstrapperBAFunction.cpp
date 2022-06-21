// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.

#include "precomp.h"
#include "BalBaseBaFunctions.h"

class CWixBootstrapperBAFunction : public BalBaseBaFunctions
{
public:

    CWixBootstrapperBAFunction(
		__in IBootstrapperApplication* pMainBA
        , __in IBootstrapperEngine* pEngine
        )
    {
		m_pMainBA = pMainBA;
        m_pEngine = pEngine;
    }

    ~CWixBootstrapperBAFunction()
    {
        m_pEngine = nullptr;
        m_pMainBA = nullptr;
    }

protected:
	IBootstrapperEngine* m_pEngine = nullptr;
    IBootstrapperApplication* m_pMainBA = nullptr;
};


extern "C" HRESULT WINAPI CreateBaFunctions(
	__in IBootstrapperEngine* pEngine,
	__in const BOOTSTRAPPER_COMMAND* pCommand,
	__in IBootstrapperApplication* pMainBA,
	__out IBootstrapperApplication** ppApplication
    )
{
    HRESULT hr = S_OK;
    CWixBootstrapperBAFunction* pBAFunction = nullptr;

    // This is required to enable logging functions
    BalInitialize(pEngine);

    pBAFunction = new CWixBootstrapperBAFunction(pMainBA, pEngine);
    ExitOnNull(pBAFunction, hr, E_OUTOFMEMORY, "Failed to create new bootstrapper BA function object.");

    *ppApplication = pBAFunction;
    pBAFunction = nullptr;

LExit:
    delete pBAFunction;
    return hr;
}
