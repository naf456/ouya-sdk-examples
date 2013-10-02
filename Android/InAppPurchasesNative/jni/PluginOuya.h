#ifndef __PLUGIN_OUYA_H__
#define __PLUGIN_OUYA_H__

#include "CallbacksFetchGamerUUID.h"
#include "CallbacksRequestProducts.h"
#include "CallbacksRequestPurchase.h"
#include "CallbacksRequestReceipts.h"

#include <string>
#include <vector>

#include <nv_and_util/nv_native_app_glue.h>
#include <jni.h>

class UI;

class PluginOuya
{
public:

	bool Initialized;

	PluginOuya();

	void FindClass(JNIEnv* env, const std::string& className, jclass* jc);

	void CacheClasses(JNIEnv* env);

	void SetApp(struct android_app* app);

	void Initialize();

	void SetDeveloperId(const std::string& developerId);

	void AsyncSetDeveloperId();

	void AsyncOuyaFetchGamerUUID(CallbacksFetchGamerUUID* callbacksFetchGamerUUID);

	void AsyncOuyaRequestProducts(CallbacksRequestProducts* callbacksRequestProducts, const std::vector<std::string>& productIds);

	void AsyncOuyaRequestPurchase(CallbacksRequestPurchase* callbacksRequestPurchase, const std::string& purchasable);

	void AsyncOuyaRequestReceipts(CallbacksRequestReceipts* callbacksRequestReceipts);

private:

	std::string m_developerId;

	// cached references
	jclass jc_AsyncCppOuyaSetDeveloperId;
	jclass jc_AsyncCppOuyaFetchGamerUUID;
	jclass jc_AsyncCppOuyaRequestProducts;
	jclass jc_AsyncCppOuyaRequestPurchase;
	jclass jc_AsyncCppOuyaRequestReceipts;
};

#endif