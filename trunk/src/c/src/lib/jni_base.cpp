/* This source file is part of XBiG
 *     (XSLT Bindings Generator)
 * For the latest info, see http://sourceforge.net/projects/xbig/
 *
 * Copyright (c) 2005 netAllied GmbH, Tettnang
 * Also see acknowledgements in Readme.html
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307, USA, or go to
 * http://www.gnu.org/copyleft/lesser.txt.
 */
#include <jni_base.h>

#include <iostream>

#ifdef WIN32
#include <windows.h>
#endif

std::string org::xbig::jni::to_stdstring(JNIEnv* env, jstring jString) {
#ifdef WIN32
	const char* c_str = env->GetStringChars(jString, 0);
    const std::wstring wideString((const wchar_t*)c_str);
    char * dest = new char[ wideString.length() + 1 ];
    WideCharToMultiByte( CP_ACP, 0, wideString.c_str(), (int) wideString.length(),
                         dest, (int) wideString.length(), NULL, NULL );
    dest[ wideString.length() ] = 0; // null termination
    std::string returnValue( dest );
    delete[] dest;
    env->ReleaseStringChars(jString, c_str);
    return returnValue;
#else
    const char* c_str = env->GetStringUTFChars(jString, 0);
    std::string std_str(c_str);
    env->ReleaseStringUTFChars(jString, c_str);
    return std_str;
#endif
}

std::wstring org::xbig::jni::to_stdwstring(JNIEnv* env, jstring jString) {
#ifdef WIN32
	const char* c_str = env->GetStringChars(jString, 0);
    std::wstring std_wstr((const wchar_t* ) c_str);
    env->ReleaseStringChars(jString, c_str);
    return std_wstr;
#else
	const char* c_str = env->GetStringUTFChars(jString, 0);
	std::wstring std_wstr((const wchar_t* ) c_str);
    env->ReleaseStringUTFChars(jString, c_str);
    return std_wstr;
#endif
}

char* org::xbig::jni::to_cstring(JNIEnv* env, jstring jString) {
	// TODO platform specific conversion
	char* c_str = (char*)env->GetStringUTFChars(jString, 0);
	return c_str;
}


jstring org::xbig::jni::to_jstring(JNIEnv* env, const std::string& str) {
	// TODO platform specific conversion
	return env->NewStringUTF(str.c_str());
}


jstring org::xbig::jni::to_jstring(JNIEnv* env, const char* str) {
	// TODO platform specific conversion
	return env->NewStringUTF(str);
}

jstring org::xbig::jni::to_jstring(JNIEnv* env, const std::wstring& str) {
#ifdef WIN32
	return env->NewString((const jchar*)str.c_str(), str.length());
#else
	return env->NewStringUTF((const char*)str.c_str());
#endif
}
