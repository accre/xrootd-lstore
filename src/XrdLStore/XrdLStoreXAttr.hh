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

#ifndef __XRD_LSTORE_XATTR_HH__
#define __XRD_LSTORE_XATTR_HH__

#include <XrdSys/XrdSysXAttr.hh>

//------------------------------------------------------------------------------
//! This class implements XrdSysXAttr interface for usage with an LStore filesystem.
//!
//! TODO: Talk about configuration, etc, once that is figured out
//!
//! Note that the definition of a default via the ofs.xattrlib directive may
//! clash with one used in a ofs.osslib directive. In case both directives
//! have a default and they are different, the behavior is not defined.
//! In case one of the two only has a default, it will be applied for both plugins.
//------------------------------------------------------------------------------

class XrdLStoreXAttr : public XrdXAttr {
public:

  XrdLStoreXAttr();
  virtual ~XrdLStoreXAttr() {};

  virtual int Del(const char *Aname, const char *Path, int fd=-1);

  virtual void Free(AList *aPL);

  virtual int Get(const char *Aname, void *Aval, int Avsz,
                  const char *Path,  int fd=-1);

  virtual int List(AList **aPL, const char *Path, int fd=-1, int getSz=0);

  virtual int Set(const char *Aname, const void *Aval, int Avsz,
                  const char *Path,  int fd=-1,  int isNew=0);
}


#endif /* __XRD_LSTORE_XATTR_HH__ */
