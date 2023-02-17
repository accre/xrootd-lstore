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

#include "XrdVersion.hh"
#include "XrdSys/XrdSysError.hh"
#include "XrdOuc/XrdOucTrace.hh"
#include "XrdLStore/XrdLStoreXAttr.hh"

XrdSysError XrdLStoreXattrEroute(0);
XrdOucTrace XrdLStoreXattrTrace(&XrdLStoreXattrEroute);

extern "C"
{
  XrdSysXAttr*
  XrdSysGetXAttrObject(XrdSysError  *errP,
                       const char   *config_fn,
                       const char   *parms)
  {
    // herald - figure out what this is
    XrdLStoreXattrEroute.SetPrefix("lstorexattr_");
    XrdLStoreXattrEroute.logger(errP->logger());
    XrdLStoreXattrEroute.Say("++++++ XrdLStoreXattr");
    // set parameters
    try {
      // no-op here for now
      ;
    } catch (std::exception &e) {
      XrdLStoreXattrEroute.Say("LStoreXattr loading failed with exception. Check the syntax of parameters : ", parms);
      return 0;
    }
    return new XrdLStoreXAttr();
  }
}

XrdLStoreXAttr::XrdLStoreXAttr() {}

XrdLStoreXAttr::~XrdLStoreXAttr() {}

int XrdLStoreXAttr::Del(const char *Aname, const char *Path, int fd) {
  // TODO: Implement
  return -ENOTSUP;
}

void XrdLStoreXAttr::Free(AList *aPL) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreXAttr::Get(const char *Aname, void *Aval, int Avsz,
                   const char *Path,  int fd) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreXAttr::List(AList **aPL, const char *Path, int fd, int getSz) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreXAttr::Set(const char *Aname, const void *Aval, int Avsz,
                      const char *Path,  int fd,  int isNew) {
  // TODO: Implement
  return -ENOTSUP;
}

XrdVERSIONINFO(XrdSysGetXAttrObject, XrdLStoreXAttr);
