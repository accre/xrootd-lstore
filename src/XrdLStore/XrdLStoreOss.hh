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

#ifndef __LSTORE_OSS_HH__
#define __LSTORE_OSS_HH__

#include <string>
#include <XrdOss/XrdOss.hh>

//------------------------------------------------------------------------------
//! This class implements XrdOss interface for usage with an LStore filesystem.
//! It should be loaded via the ofs.osslib directive.
//!
//! TODO: Explain how to connect to a given LStore server through configuration
//!
//! Note that the definition of a default via the ofs.osslib directive may
//! clash with one used in a ofs.xattrlib directive. In case both directives
//! have a default and they are different, the behavior is not defined.
//! In case one of the two only has a default, it will be applied for both plugins.
//------------------------------------------------------------------------------

class XrdLStoreOss : public XrdOss {
public:
  XrdLStoreOss(const char *, XrdSysError &);
  virtual ~XrdLStoreOss();

  int Configure(const char *, XrdSysError &);

  virtual int     Chmod(const char *, mode_t mode, XrdOucEnv *eP=0);
  virtual int     Create(const char *, const char *, mode_t, XrdOucEnv &, int opts=0);
  virtual int     Init(XrdSysLogger *, const char*);
  virtual int     Mkdir(const char *, mode_t mode, int mkpath=0, XrdOucEnv *eP=0);
  virtual int     Remdir(const char *, int Opts=0, XrdOucEnv *eP=0);
  virtual int     Rename(const char *, const char *, XrdOucEnv *eP1=0, XrdOucEnv *eP2=0);
  virtual int     Stat(const char *, struct stat *, int opts=0, XrdOucEnv *eP=0);
  virtual int     StatFS(const char *path, char *buff, int &blen, XrdOucEnv *eP=0);
  virtual int     StatVS(XrdOssVSInfo *sP, const char *sname=0, int updt=0);
  virtual int     Truncate(const char *, unsigned long long, XrdOucEnv *eP=0);
  virtual int     Unlink(const char *path, int Opts=0, XrdOucEnv *eP=0);
  virtual XrdOssDF *newDir(const char *tident);
  virtual XrdOssDF *newFile(const char *tident);

};

class XrdLStoreOssDF : public XrdOssDF {
public:

  XrdLStoreOssDF(XrdLStoreOss *lstoreoss);
  virtual ~XrdLStoreOssDir() {};

  // Directory-oriented operations
  virtual int Opendir(const char *, XrdOucEnv &);
  virtual int Readdir(char *buff, int blen);
  virtual int Close(long long *retsz=0);

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

#endif /* __LSTORE_OSS_HH__ */
