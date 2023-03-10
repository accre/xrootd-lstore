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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "XrdLStore/XrdLStoreOssDF.hh"
#include "XrdSys/XrdSysError.hh"
#include "XrdOuc/XrdOucTrace.hh"

extern XrdSysError XrdLStoreEroute;

XrdLStoreOssDF::XrdLStoreOssDF(XrdLStoreOss *lstoreOss) : m_fd(-1) {}

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


//------------------------------------------------------------------------------
// File based methods
//------------------------------------------------------------------------------

int XrdLStoreOssDF::Open(const char *path, int flags, mode_t mode, XrdOucEnv &env) {
  XrdLStoreEroute.Say("Opening a file...");
  m_fd = open(path, flags);
  return XrdOssOK;
}

int XrdLStoreOssDF::Close(long long *retsz) {
  XrdLStoreEroute.Say("Closing a file...");
  return close(m_fd);
}

ssize_t XrdLStoreOssDF::Read(off_t offset, size_t blen) {
  // TODO: Implement
  XrdLStoreEroute.Say("Calling the read without a buffer, what do I do here???");
  return -ENOTSUP;
}

ssize_t XrdLStoreOssDF::Read(void *buff, off_t offset, size_t blen) {
  XrdLStoreEroute.Say("Reading (pread)...");
  return pread(m_fd, buff, blen, offset);
}

int XrdLStoreOssDF::Read(XrdSfsAio *aiop) {
  // TODO: Implement
  XrdLStoreEroute.Say("Calling the async read, what do I do here???");
  return -ENOTSUP;
}

ssize_t XrdLStoreOssDF::ReadRaw(void *buff, off_t offset, size_t blen) {
  // TODO: Implement
  XrdLStoreEroute.Say("Calling the read raw, what do I do here???");
  return -ENOTSUP;
}

int XrdLStoreOssDF::Fstat(struct stat *buff) {
  XrdLStoreEroute.Say("Calling FStat...");
  return fstat(m_fd, buff);
}

ssize_t XrdLStoreOssDF::Write(const void *buff, off_t offset, size_t blen) {
  // TODO: Implement
  XrdLStoreEroute.Say("Calling Write, what do I do here???");
  return -ENOTSUP;
}

int XrdLStoreOssDF::Write(XrdSfsAio *aiop) {
  // TODO: Implement
  return -ENOTSUP;
}

int XrdLStoreOssDF::Fsync() {
  // TODO: Implement
  XrdLStoreEroute.Say("Calling FSync, what do I do here???");
  return -ENOTSUP;
}

int XrdLStoreOssDF::Ftruncate(unsigned long long len) {
  // TODO: Implement
  return -ENOTSUP;
}
