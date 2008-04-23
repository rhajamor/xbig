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
	const std::wstring wideString((const wchar_t*)env->GetStringChars(jString, JNI_FALSE)); // false: create a copy
        char * dest = new char[ wideString.length() + 1 ];
        WideCharToMultiByte( CP_ACP, 0, wideString.c_str(), (int) wideString.length(),
                             dest, (int) wideString.length(), NULL, NULL );
        dest[ wideString.length() ] = 0; // null termination
        std::string returnValue( dest );
        delete[] dest;
        return returnValue;
#else
	const char* c_str = env->GetStringUTFChars(jString, JNI_FALSE); // false: create a copy
	return std::string(c_str);
#endif
}

std::wstring org::xbig::jni::to_stdwstring(JNIEnv* env, jstring jString) {
	const wchar_t* c_str = (const wchar_t* ) env->GetStringChars(jString, JNI_FALSE); // false: create a copy
 	return std::wstring(c_str);
}

char* org::xbig::jni::to_cstring(JNIEnv* env, jstring jString) {
	// TODO platform specific conversion
	char* c_str = (char*)env->GetStringUTFChars(jString, JNI_FALSE); // false: create a copy
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
	return env->NewString((const jchar*)str.c_str(), str.length());
}
