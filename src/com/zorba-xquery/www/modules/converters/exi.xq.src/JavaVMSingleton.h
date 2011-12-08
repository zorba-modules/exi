/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef JAVA_VM_SINGELTON
#define JAVA_VM_SINGELTON

#include <jni.h>
#include <zorba/config.h>

namespace zorba { namespace exi {

  class VMOpenException {};

  class JavaVMSingleton {
  public:
    static JavaVMSingleton* getInstance();
    static void destroyInstance();
    virtual ~JavaVMSingleton();
    JavaVM* getVM();
    JNIEnv* getEnv();
  protected:
    JavaVMSingleton(const char* classPath);
    static JavaVMSingleton* instance;
    static void throwError(std::string aName);
    static std::string findExificient();

    JavaVM* m_vm;
    JNIEnv* m_env;
  };

  class JavaException {
  };

  ZORBA_DLL_PUBLIC void global_func();

}} //namespace zorba, xslfo

#endif // JAVA_VM_SINGELTON