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

#ifndef __XRD_LSTORE_OSS_DF_HH__
#define __XRD_LSTORE_OSS_DF_HH__

#include "XrdOss/XrdOss.hh"
#include "XrdLStore/XrdLStoreOss.hh"

//------------------------------------------------------------------------------
//! This class implements XrdOssDF interface for usage with an LStore filesystem.
//!
//! TODO: Talk about configuration, etc, once that is figured out
//!
//! Note that the definition of a default via the ofs.osslib directive may
//! clash with one used in a ofs.xattrlib directive. In case both directives
//! have a default and they are different, the behavior is not defined.
//! In case one of the two only has a default, it will be applied for both plugins.
//------------------------------------------------------------------------------

class XrdLStoreOssDF : public XrdOssDF {
public:

  XrdLStoreOssDF(XrdLStoreOss *lstoreoss);
  virtual ~XrdLStoreOssDF() {};

  // Directory-oriented operations
  virtual int Opendir(const char *, XrdOucEnv &);
  virtual int Readdir(char *buff, int blen);

  //File-oriented operations
  virtual int Open(const char *path, int flags, mode_t mode, XrdOucEnv &env);
  virtual int Close(long long *retsz=0);
  virtual ssize_t Read(off_t offset, size_t blen);
  virtual ssize_t Read(void *buff, off_t offset, size_t blen);
  virtual int     Read(XrdSfsAio *aiop);
  virtual ssize_t ReadRaw(void *, off_t, size_t);
  virtual int Fstat(struct stat *buff);
  virtual ssize_t Write(const void *buff, off_t offset, size_t blen);
  virtual int Write(XrdSfsAio *aiop);
  virtual int Fsync(void);
  virtual int Ftruncate(unsigned long long);

}


#endif /* __XRD_LSTORE_OSS_DF_HH__ */
