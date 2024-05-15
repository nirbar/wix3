// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.

#include <windows.h>
#include <msiquery.h>

#include "IBootstrapperEngine.h"
#include "IBootstrapperApplication.h"

#include "balutil.h"
#include "balretry.h"

class BalBaseBaFunctions : public IBootstrapperApplication
{
public: // IUnknown
    virtual STDMETHODIMP QueryInterface(
        __in REFIID riid,
        __out LPVOID *ppvObject
        )
    {
        if (!ppvObject)
        {
            return E_INVALIDARG;
        }

        *ppvObject = NULL;

        if (::IsEqualIID(__uuidof(IBootstrapperApplication), riid))
        {
            *ppvObject = static_cast<IBootstrapperApplication*>(this);
        }
        else if (::IsEqualIID(IID_IUnknown, riid))
        {
            *ppvObject = static_cast<IUnknown*>(this);
        }
        else // no interface for requested iid
        {
            return E_NOINTERFACE;
        }

        AddRef();
        return S_OK;
    }

    virtual STDMETHODIMP_(ULONG) AddRef()
    {
        return ::InterlockedIncrement(&this->m_cReferences);
    }

    virtual STDMETHODIMP_(ULONG) Release()
    {
        long l = ::InterlockedDecrement(&this->m_cReferences);
        if (0 < l)
        {
            return l;
        }

        delete this;
        return 0;
    }

public: // IBootstrapperApplication
    virtual STDMETHODIMP OnStartup()
    {
        return S_OK;
    }

    virtual STDMETHODIMP_(int) OnShutdown()
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnSystemShutdown(
        __in DWORD /*dwEndSession*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(int) OnDetectBegin(
        __in BOOL /*fInstalled*/,
        __in DWORD /*cPackages*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDetectForwardCompatibleBundle(
        __in_z LPCWSTR /*wzBundleId*/,
        __in BOOTSTRAPPER_RELATION_TYPE /*relationType*/,
        __in_z LPCWSTR /*wzBundleTag*/,
        __in BOOL /*fPerMachine*/,
        __in DWORD64 /*dw64Version*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(int) OnDetectUpdateBegin(
        __in_z LPCWSTR /*wzUpdateLocation*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(int) OnDetectUpdate(
        __in_z LPCWSTR /*wzUpdateLocation*/,
        __in DWORD64 /*dw64Size*/,
        __in DWORD64 /*dw64Version*/,
        __in_z LPCWSTR /*wzTitle*/,
        __in_z LPCWSTR /*wzSummary*/,
        __in_z LPCWSTR /*wzContentType*/,
        __in_z LPCWSTR /*wzContent*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(void) OnDetectUpdateComplete(
        __in HRESULT /*hrStatus*/,
        __in_z_opt LPCWSTR /*wzUpdateLocation*/
        )
    {
    }

    virtual STDMETHODIMP_(int) OnDetectCompatiblePackage(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzCompatiblePackageId*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDetectPriorBundle(
        __in_z LPCWSTR /*wzBundleId*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDetectPackageBegin(
        __in_z LPCWSTR /*wzPackageId*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDetectRelatedBundle(
        __in_z LPCWSTR /*wzBundleId*/,
        __in BOOTSTRAPPER_RELATION_TYPE /*relationType*/,
        __in_z LPCWSTR /*wzBundleTag*/,
        __in BOOL /*fPerMachine*/,
        __in DWORD64 /*dw64Version*/,
        __in BOOTSTRAPPER_RELATED_OPERATION /*operation*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDetectRelatedMsiPackage(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzProductCode*/,
        __in BOOL /*fPerMachine*/,
        __in DWORD64 /*dw64Version*/,
        __in BOOTSTRAPPER_RELATED_OPERATION /*operation*/
        ) 
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDetectTargetMsiPackage(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzProductCode*/,
        __in BOOTSTRAPPER_PACKAGE_STATE /*patchState*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDetectMsiFeature(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzFeatureId*/,
        __in BOOTSTRAPPER_FEATURE_STATE /*state*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(void) OnDetectPackageComplete(
        __in_z LPCWSTR /*wzPackageId*/,
        __in HRESULT /*hrStatus*/,
        __in BOOTSTRAPPER_PACKAGE_STATE /*state*/
        )
    {
    }

    virtual STDMETHODIMP_(void) OnDetectComplete(
        __in HRESULT /*hrStatus*/
        )
    {
    }

    virtual STDMETHODIMP_(int) OnPlanBegin(
        __in DWORD /*cPackages*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnPlanRelatedBundle(
        __in_z LPCWSTR /*wzBundleId*/,
        __inout BOOTSTRAPPER_REQUEST_STATE* /*pRequestedState*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnPlanPackageBegin(
        __in_z LPCWSTR /*wzPackageId*/, 
        __inout BOOTSTRAPPER_REQUEST_STATE* /*pRequestState*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnPlanCompatiblePackage(
        __in_z LPCWSTR /*wzPackageId*/,
        __inout BOOTSTRAPPER_REQUEST_STATE* /*pRequestedState*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnPlanTargetMsiPackage(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzProductCode*/,
        __inout BOOTSTRAPPER_REQUEST_STATE* /*pRequestedState*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnPlanMsiFeature(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzFeatureId*/,
        __inout BOOTSTRAPPER_FEATURE_STATE* /*pRequestedState*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(void) OnPlanPackageComplete(
        __in_z LPCWSTR /*wzPackageId*/,
        __in HRESULT /*hrStatus*/,
        __in BOOTSTRAPPER_PACKAGE_STATE /*state*/,
        __in BOOTSTRAPPER_REQUEST_STATE /*requested*/,
        __in BOOTSTRAPPER_ACTION_STATE /*execute*/,
        __in BOOTSTRAPPER_ACTION_STATE /*rollback*/
        )
    {
    }

    virtual STDMETHODIMP_(int) OnPlanMsiTransaction(
        __in_z LPCWSTR /*wzTransactionId*/,
        __inout BOOL* /*pfTransaction*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnPlanMsiTransactionCommit(
        __in_z LPCWSTR /*wzTransactionId*/,
        __in DWORD /*dwPackageCount*/,
        __in BOOL /*fPlanned*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(void) OnPlanComplete(
        __in HRESULT /*hrStatus*/
        )
    {
    }

    virtual STDMETHODIMP_(int) OnApplyBegin()
    {
        return IDNOACTION;
    }

    // DEPRECATED: this will be merged with OnApplyBegin in wix4.
    virtual STDMETHODIMP_(void) OnApplyPhaseCount(
        __in DWORD /*dwPhaseCount*/
        )
    {
    }

    virtual STDMETHODIMP_(int) OnElevate()
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnRegisterBegin()
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(void) OnRegisterComplete(
        __in HRESULT /*hrStatus*/
        )
    {
        return;
    }

    virtual STDMETHODIMP_(void) OnUnregisterBegin()
    {
        return;
    }

    virtual STDMETHODIMP_(void) OnUnregisterComplete(
        __in HRESULT /*hrStatus*/
        )
    {
        return;
    }

    virtual STDMETHODIMP_(int) OnApplyComplete(
        __in HRESULT /*hrStatus*/,
        __in BOOTSTRAPPER_APPLY_RESTART /*restart*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnCacheBegin()
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnCachePackageBegin(
        __in_z LPCWSTR /*wzPackageId*/,
        __in DWORD /*cCachePayloads*/,
        __in DWORD64 /*dw64PackageCacheSize*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnCacheAcquireBegin(
        __in_z LPCWSTR /*wzPackageOrContainerId*/,
        __in_z_opt LPCWSTR /*wzPayloadId*/,
        __in BOOTSTRAPPER_CACHE_OPERATION /*operation*/,
        __in_z LPCWSTR /*wzSource*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnCacheAcquireProgress(
        __in_z LPCWSTR /*wzPackageOrContainerId*/,
        __in_z_opt LPCWSTR /*wzPayloadId*/,
        __in DWORD64 /*dw64Progress*/,
        __in DWORD64 /*dw64Total*/,
        __in DWORD /*dwOverallPercentage*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnCacheAcquireComplete(
        __in_z LPCWSTR /*wzPackageOrContainerId*/,
        __in_z_opt LPCWSTR /*wzPayloadId*/,
        __in HRESULT /*hrStatus*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(int) OnCacheVerifyBegin(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzPayloadId*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnCacheVerifyComplete(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzPayloadId*/,
        __in HRESULT /*hrStatus*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(int) OnCachePackageComplete(
        __in_z LPCWSTR /*wzPackageId*/,
        __in HRESULT /*hrStatus*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(void) OnCacheComplete(
        __in HRESULT /*hrStatus*/
        )
    {
    }

    virtual STDMETHODIMP_(int) OnExecuteBegin(
        __in DWORD /*cExecutingPackages*/
        )
    {
        return IDNOACTION;
    }

    STDMETHODIMP_(void) OnMsiTransactionBegin(
        __in_z LPCWSTR /*wzTransactionId*/
        ) override
    {
        return;
    }

    STDMETHODIMP_(void) OnMsiTransactionCommit(
        __in_z LPCWSTR /*wzTransactionId*/,
        __inout BOOTSTRAPPER_APPLY_RESTART* /*pRestart*/
        ) override
    {
        return;
    }

    STDMETHODIMP_(void) OnMsiTransactionRollback(
        __in_z LPCWSTR /*wzTransactionId*/,
        __inout BOOTSTRAPPER_APPLY_RESTART* /*pRestart*/
        ) override
    {
        return;
    }

    STDMETHODIMP_(int) OnMsiTransactionComplete(
        __in_z LPCWSTR /*wzTransactionId*/,
        __in MSITRANSACTIONSTATE /*eState*/,
        __in HRESULT /*hrStatus*/
    ) override
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnExecutePackageBegin(
        __in_z LPCWSTR /*wzPackageId*/,
        __in BOOL /*fExecute*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnExecutePatchTarget(
        __in_z LPCWSTR /*wzPackageId*/,
        __in_z LPCWSTR /*wzTargetProductCode*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnError(
        __in BOOTSTRAPPER_ERROR_TYPE /*errorType*/,
        __in_z LPCWSTR /*wzPackageId*/,
        __in DWORD /*dwCode*/,
        __in_z LPCWSTR /*wzError*/,
        __in DWORD /*dwUIHint*/,
        __in DWORD /*cData*/,
        __in_ecount_z_opt(cData) LPCWSTR* /*rgwzData*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(int) OnProgress(
        __in DWORD /*dwProgressPercentage*/,
        __in DWORD /*dwOverallProgressPercentage*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDownloadPayloadBegin(
        __in_z LPCWSTR /*wzPayloadId*/,
        __in_z LPCWSTR /*wzPayloadFileName*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnDownloadPayloadComplete(
        __in_z LPCWSTR /*wzPayloadId*/,
        __in_z LPCWSTR /*wzPayloadFileName*/,
        __in HRESULT /*hrStatus*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnExecuteProgress(
        __in_z LPCWSTR /*wzPackageId*/,
        __in DWORD /*dwProgressPercentage*/,
        __in DWORD /*dwOverallProgressPercentage*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnExecuteMsiMessage(
        __in_z LPCWSTR /*wzPackageId*/,
        __in INSTALLMESSAGE /*mt*/,
        __in UINT /*uiFlags*/,
        __in_z LPCWSTR /*wzMessage*/,
        __in DWORD /*cData*/,
        __in_ecount_z_opt(cData) LPCWSTR* /*rgwzData*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(int) OnExecuteFilesInUse(
        __in_z LPCWSTR /*wzPackageId*/,
        __in DWORD /*cFiles*/,
        __in_ecount_z(cFiles) LPCWSTR* /*rgwzFiles*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnEmbeddedCustomMessage(
        __in_z LPCWSTR /*wzPackageId*/,
        __in DWORD /*dwCode*/,
        __in_z LPCWSTR /*wzMessage*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnExecutePackageComplete(
        __in_z LPCWSTR /*wzPackageId*/,
        __in HRESULT /*hrExitCode*/,
        __in BOOTSTRAPPER_APPLY_RESTART /*restart*/,
        __in int nRecommendation
        )
    {
        return nRecommendation;
    }

    virtual STDMETHODIMP_(void) OnExecuteComplete(
        __in HRESULT /*hrStatus*/
        )
    {
    }

    virtual STDMETHODIMP_(int) OnResolveSource(
        __in_z LPCWSTR /*wzPackageOrContainerId*/,
        __in_z_opt LPCWSTR /*wzPayloadId*/,
        __in_z LPCWSTR /*wzLocalSource*/,
        __in_z_opt LPCWSTR /*wzDownloadSource*/
        )
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(int) OnLaunchApprovedExeBegin()
    {
        return IDNOACTION;
    }

    virtual STDMETHODIMP_(void) OnLaunchApprovedExeComplete(
        __in HRESULT /*hrStatus*/,
        __in DWORD /*dwProcessId*/
        )
    {
    }
private:
    long m_cReferences;
};

extern "C" typedef HRESULT(WINAPI* PFN_BAFUNCTIONS_CREATE)(
    __in IBootstrapperEngine* pEngine,
    __in const BOOTSTRAPPER_COMMAND* pCommand,
    __in IBootstrapperApplication* pMainBA,
    __out IBootstrapperApplication** ppApplication
    );
