//------------------------------------------------------------------------------
// Copyright (c) 2023 by Vanderbilt University
//------------------------------------------------------------------------------
// This file is part of a third-party plugin to the XRootD software suite.
//
// XRootD is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// XRootD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with XRootD.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <stdio.h>
#include <string>
#include <fcntl.h>

#include "XrdOuc/XrdOucEnv.hh"
#include "XrdSys/XrdSysError.hh"
#include "XrdOuc/XrdOucTrace.hh"
#include "XrdOuc/XrdOucStream.hh"
#include "XrdOuc/XrdOucName2Name.hh"
#ifdef XRDLSTORE_SUBMODULE
#include "XrdOuc/XrdOucN2NLoader.hh"
#else
#include "private/XrdOuc/XrdOucN2NLoader.hh"
#endif
#include "XrdVersion.hh"
#include "XrdLStore/XrdLStoreOss.hh"

XrdVERSIONINFO(XrdOssGetStorageSystem, XrdLStoreOss);

XrdSysError XrdLStoreEroute(0);
XrdOucTrace XrdLStoreTrace(&XrdLStoreEroute);

XrdLStoreOss::XrdLStoreOss(const char *configfn, XrdSysError &Eroute) {
  Configure(configfn, Eroute);
}

XrdLStoreOss::~XrdLStoreOss() {
}


int XrdLStoreOss::Configure(const char *configfn, XrdSysError &Eroute) {
   int NoGo = 0;

   // If there is a config file, then read it
   XrdOucEnv myEnv;
   XrdOucStream Config(&Eroute, getenv("XRDINSTANCE"), &myEnv, "=====> ");
   if (configfn && *configfn) {
     int cfgFD;
     if ((cfgFD = open(configfn, O_RDONLY, 0)) < 0) {
       Eroute.Emsg("Config", errno, "opening config file", configfn);
       return 1;
     }
     Config.Attach(cfgFD);

     // Eventually we'll read something meaningful out of the config, perhaps?
     // for now return test message if a test parameter was read
     char *var;
     while((var = Config.GetMyFirstWord())) {
       if (!strncmp(var, "lstore.testvar", 14)) {
         var = Config.GetWord();
         if (var) {
           Eroute.Emsg("Config", "Got a value for lstore.testvar", configfn, var);
         }
       }
     }

     // Fail on any config file io errors
     int retc = Config.LastError();
     if (retc) {
       NoGo = Eroute.Emsg("Config", -retc, "reading config file",
                          configfn);
     }
     Config.Close();
  }
  return NoGo;
}

int XrdLStoreOss::Chmod(const char *path, mode_t mode, XrdOucEnv *envP) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::Create(const char *tident, const char *path, mode_t access_mode,
                    XrdOucEnv &env, int Opts) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::Init(XrdSysLogger *logger, const char* configFn) {
  // Eventually init LStore connection here???
  return 0;
}


int XrdLStoreOss::Mkdir(const char *path, mode_t mode, int mkpath, XrdOucEnv *envP) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::Remdir(const char *path, int Opts, XrdOucEnv *eP) {
  // TODO: Implement
  return -ENOTSUP;
} 

int XrdLStoreOss::Rename(const char *from, const char *to,
                    XrdOucEnv *eP1, XrdOucEnv *eP2) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::Stat(const char *, struct stat *, int opts=0, XrdOucEnv *eP=0) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::StatFS(const char *path, char *buff, int &blen, XrdOucEnv *eP) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::StatVS(XrdOssVSInfo *sP, const char *sname, int updt) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::Truncate (const char* path, unsigned long long size,
                          XrdOucEnv* env) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOss::Unlink(const char *path, int Opts, XrdOucEnv *env) {
  // TODO: Implement
  return -ENOTSUP;
}

XrdOssDF* XrdLStoreOss::newDir(const char *tident) {
  return new XrdLStoreOssDF(this);
}

XrdOssDF* XrdLStoreOss::newFile(const char *tident) {
  return new XrdLStoreOssDF(this);
}
