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

#include "XrdCeph/XrdLStoreOssDF.hh"
#include "XrdSys/XrdSysError.hh"
#include "XrdOuc/XrdOucTrace.hh"

XrdLStoreOssDF::XrdLStoreOssDF(XrdLStoreOss *cephOss) {}

//------------------------------------------------------------------------------
// Directory based methods
//------------------------------------------------------------------------------

int XrdLStoreOssDF::Opendir(const char *path, XrdOucEnv &env) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOssDF::Readdir(char *buff, int blen) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOssDF::Close(long long *retsz) {
  // TODO: Implement
  return -ENOTSUP;
}


//------------------------------------------------------------------------------
// File based methods
//------------------------------------------------------------------------------
