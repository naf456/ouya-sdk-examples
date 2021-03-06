#ifndef __ORG_JSON_JSONARRAY_JSONARRAY_H__
#define __ORG_JSON_JSONARRAY_JSONARRAY_H__

#include <string>

namespace org_json_JSONObject
{
	class JSONObject;
}

struct _JNIEnv;
typedef _JNIEnv JNIEnv;

class _jclass;
typedef _jclass* jclass;

namespace org_json_JSONArray
{
	class JSONArray
	{
	public:
		JSONArray(jobject jsonArray);
		static int InitJNI(JNIEnv* env);
		jobject GetInstance() const;
		int length();
		org_json_JSONObject::JSONObject getJSONObject(int index);
		int getInt(int index);
		std::string getString(int index);
	private:
		static JNIEnv* _env;
		static jclass _jcJsonArray;
		static jmethodID _mGetInt;
		static jmethodID _mGetJsonObject;
		static jmethodID _mGetString;
		static jmethodID _mLength;
		jobject _instance;
	};
}

#endif