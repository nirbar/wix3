// Copyright (c) .NET Foundation and contributors. All rights reserved. Licensed under the Microsoft Reciprocal License. See LICENSE.TXT file in the project root for full license information.

#include "precomp.h"

class CWixBootstrapperBAFunction : public IBootstrapperApplication
{
public:

	STDMETHODIMP OnStartup()
	{
		return S_OK;
	}

	int STDMETHODCALLTYPE OnShutdown()
	{
		return ERROR_SUCCESS;
	}

	int STDMETHODCALLTYPE OnSystemShutdown(
		__in DWORD dwEndSession,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectBegin(
		__in BOOL fInstalled,
		__in DWORD cPackages
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectForwardCompatibleBundle(
		__in_z LPCWSTR wzBundleId,
		__in BOOTSTRAPPER_RELATION_TYPE relationType,
		__in_z LPCWSTR wzBundleTag,
		__in BOOL fPerMachine,
		__in DWORD64 dw64Version,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectUpdateBegin(
		__in_z LPCWSTR wzUpdateLocation,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectUpdate(
		__in_z_opt LPCWSTR wzUpdateLocation,
		__in DWORD64 dw64Size,
		__in DWORD64 dw64Version,
		__in_z_opt LPCWSTR wzTitle,
		__in_z_opt LPCWSTR wzSummary,
		__in_z_opt LPCWSTR wzContentType,
		__in_z_opt LPCWSTR wzContent,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnDetectUpdateComplete(
		__in HRESULT hrStatus,
		__in_z_opt LPCWSTR wzUpdateLocation
		){ return; }

	int STDMETHODCALLTYPE OnDetectRelatedBundle(
		__in_z LPCWSTR wzBundleId,
		__in BOOTSTRAPPER_RELATION_TYPE relationType,
		__in_z LPCWSTR wzBundleTag,
		__in BOOL fPerMachine,
		__in DWORD64 dw64Version,
		__in BOOTSTRAPPER_RELATED_OPERATION operation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectPackageBegin(
		__in_z LPCWSTR wzPackageId
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectCompatiblePackage(
		__in_z LPCWSTR wzPackageId,
		__in_z LPCWSTR wzCompatiblePackageId
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectRelatedMsiPackage(
		__in_z LPCWSTR wzPackageId,
		__in_z LPCWSTR wzProductCode,
		__in BOOL fPerMachine,
		__in DWORD64 dw64Version,
		__in BOOTSTRAPPER_RELATED_OPERATION operation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectTargetMsiPackage(
		__in_z LPCWSTR wzPackageId,
		__in_z LPCWSTR wzProductCode,
		__in BOOTSTRAPPER_PACKAGE_STATE patchState
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnDetectMsiFeature(
		__in_z LPCWSTR wzPackageId,
		__in_z LPCWSTR wzFeatureId,
		__in BOOTSTRAPPER_FEATURE_STATE state
		){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnDetectPackageComplete(
		__in_z LPCWSTR wzPackageId,
		__in HRESULT hrStatus,
		__in BOOTSTRAPPER_PACKAGE_STATE state
		){ return; }

	void STDMETHODCALLTYPE OnDetectComplete(
		__in HRESULT hrStatus
		){ return; }

	int STDMETHODCALLTYPE OnPlanBegin(
		__in DWORD cPackages
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnPlanRelatedBundle(
		__in_z LPCWSTR wzBundleId,
		__inout BOOTSTRAPPER_REQUEST_STATE* pRequestedState
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnPlanPackageBegin(
		__in_z LPCWSTR wzPackageId,
		__inout BOOTSTRAPPER_REQUEST_STATE* pRequestedState
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnPlanCompatiblePackage(
		__in_z LPCWSTR wzPackageId,
		__inout BOOTSTRAPPER_REQUEST_STATE* pRequestedState
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnPlanTargetMsiPackage(
		__in_z LPCWSTR wzPackageId,
		__in_z LPCWSTR wzProductCode,
		__inout BOOTSTRAPPER_REQUEST_STATE* pRequestedState
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnPlanMsiFeature(
		__in_z LPCWSTR wzPackageId,
		__in_z LPCWSTR wzFeatureId,
		__inout BOOTSTRAPPER_FEATURE_STATE* pRequestedState
		){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnPlanPackageComplete(
		__in_z LPCWSTR wzPackageId,
		__in HRESULT hrStatus,
		__in BOOTSTRAPPER_PACKAGE_STATE state,
		__in BOOTSTRAPPER_REQUEST_STATE requested,
		__in BOOTSTRAPPER_ACTION_STATE execute,
		__in BOOTSTRAPPER_ACTION_STATE rollback
		){ return; }

	void STDMETHODCALLTYPE OnPlanComplete(
		__in HRESULT hrStatus
		){ return; }

	int STDMETHODCALLTYPE OnApplyBegin(){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnApplyPhaseCount(
		__in DWORD dwPhaseCount
		){ return; }

	int STDMETHODCALLTYPE OnElevate(){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnProgress(
		__in DWORD dwProgressPercentage,
		__in DWORD dwOverallPercentage
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnError(
		__in BOOTSTRAPPER_ERROR_TYPE errorType,
		__in_z_opt LPCWSTR wzPackageId,
		__in DWORD dwCode,
		__in_z_opt LPCWSTR wzError,
		__in DWORD uiFlags,
		__in DWORD cData,
		__in_ecount_z_opt(cData) LPCWSTR* rgwzData,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnRegisterBegin(){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnRegisterComplete(
		__in HRESULT hrStatus
		){ return; }

	int STDMETHODCALLTYPE OnCacheBegin(){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnCachePackageBegin(
		__in_z LPCWSTR wzPackageId,
		__in DWORD cCachePayloads,
		__in DWORD64 dw64PackageCacheSize
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnCacheAcquireBegin(
		__in_z_opt LPCWSTR wzPackageOrContainerId,
		__in_z_opt LPCWSTR wzPayloadId,
		__in BOOTSTRAPPER_CACHE_OPERATION operation,
		__in_z LPCWSTR wzSource
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnCacheAcquireProgress(
		__in_z_opt LPCWSTR wzPackageOrContainerId,
		__in_z_opt LPCWSTR wzPayloadId,
		__in DWORD64 dw64Progress,
		__in DWORD64 dw64Total,
		__in DWORD dwOverallPercentage
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnResolveSource(
		__in_z LPCWSTR wzPackageOrContainerId,
		__in_z_opt LPCWSTR wzPayloadId,
		__in_z LPCWSTR wzLocalSource,
		__in_z_opt LPCWSTR wzDownloadSource
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnCacheAcquireComplete(
		__in_z_opt LPCWSTR wzPackageOrContainerId,
		__in_z_opt LPCWSTR wzPayloadId,
		__in HRESULT hrStatus,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnCacheVerifyBegin(
		__in_z_opt LPCWSTR wzPackageOrContainerId,
		__in_z_opt LPCWSTR wzPayloadId
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnCacheVerifyComplete(
		__in_z_opt LPCWSTR wzPackageOrContainerId,
		__in_z_opt LPCWSTR wzPayloadId,
		__in HRESULT hrStatus,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnCachePackageComplete(
		__in_z LPCWSTR wzPackageId,
		__in HRESULT hrStatus,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnCacheComplete(
		__in HRESULT hrStatus
		){ return; }

	int STDMETHODCALLTYPE OnExecuteBegin(
		__in DWORD cExecutingPackages
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnExecutePackageBegin(
		__in_z LPCWSTR wzPackageId,
		__in BOOL fExecute
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnExecutePatchTarget(
		__in_z LPCWSTR wzPackageId,
		__in_z LPCWSTR wzTargetProductCode
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnExecuteProgress(
		__in_z LPCWSTR wzPackageId,
		__in DWORD dwProgressPercentage,
		__in DWORD dwOverallPercentage
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnExecuteMsiMessage(
		__in_z LPCWSTR wzPackageId,
		__in INSTALLMESSAGE mt,
		__in UINT uiFlags,
		__in_z LPCWSTR wzMessage,
		__in DWORD cData,
		__in_ecount_z_opt(cData) LPCWSTR* rgwzData,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnExecuteFilesInUse(
		__in_z LPCWSTR wzPackageId,
		__in DWORD cFiles,
		__in_ecount_z(cFiles) LPCWSTR* rgwzFiles
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnExecutePackageComplete(
		__in_z LPCWSTR wzPackageId,
		__in HRESULT hrStatus,
		__in BOOTSTRAPPER_APPLY_RESTART restart,
		__in int nRecommendation
		){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnExecuteComplete(
		__in HRESULT hrStatus
		){ return; }

	void STDMETHODCALLTYPE OnUnregisterBegin(){ return; }

	void STDMETHODCALLTYPE OnUnregisterComplete(
		__in HRESULT hrStatus
		){ return; }

	int STDMETHODCALLTYPE OnApplyComplete(
		__in HRESULT hrStatus,
		__in BOOTSTRAPPER_APPLY_RESTART restart
		){ return ERROR_SUCCESS; }

	int STDMETHODCALLTYPE OnLaunchApprovedExeBegin(){ return ERROR_SUCCESS; }

	void STDMETHODCALLTYPE OnLaunchApprovedExeComplete(
		__in HRESULT hrStatus,
		__in DWORD dwProcessId
		){ return; }

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
    }

	/* IUnknown */
	HRESULT STDMETHODCALLTYPE QueryInterface(
		__in REFIID riid,
		__out void **ppvObject
	)
	{
		*ppvObject = nullptr;
		return S_OK;
	}

	ULONG STDMETHODCALLTYPE AddRef()
	{
		return 0;
	}
	
	ULONG STDMETHODCALLTYPE Release()
	{
		return 0;
	}

private:
	IBootstrapperEngine* m_pEngine;
	IBootstrapperApplication* m_pMainBA
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
