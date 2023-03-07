#-------------------------------------------------------------------------------
# Helper macros
#-------------------------------------------------------------------------------
%if %{?fedora}%{!?fedora:0} >= 22
    %define use_libc_semaphore 1
%else
    %define use_libc_semaphore 0
%endif

%if %{?rhel:1}%{!?rhel:0}
    %if %{rhel} > 7
        %define use_cmake3 0
    %else
        %define use_cmake3 1
    %endif
%else
    %define use_cmake3 0
%endif

#-------------------------------------------------------------------------------
# Package definitions
#-------------------------------------------------------------------------------
Name:		xrootd-lstore
Version:	0.0.1
Release:	1%{?dist}
Summary:	LStore plugin for XRootD

Group:		System Environment/Daemons
License:	LGPLv3+
URL:		https://github.com/accre/xrootd-lstore


# git clone http://github.com/accre/xrootd-lstore.git xrootd-lstore
# cd xrootd-lstore
# git-archive master | gzip -9 > ~/rpmbuild/SOURCES/xrootd-lstore.tar.gz
Source0: xrootd-lstore.tar.gz	

BuildRoot: %{_tmppath}/%{name}-root

%if %{use_cmake3}
BuildRequires: cmake3
%else
BuildRequires: cmake
%endif

BuildRequires: lstore-devel
BuildRequires: apr-devel
BuildRequires: zeromq-devel
BuildRequires: apr-util-devel

Requires: lstore
Requires: xrootd
Requires: xrootd-server
Requires: xrootd-server-libs
Requires: xrootd-client
Requires: xrootd-client-libs

%description
xrootd-lstore is an OSS layer plug-in for the XRootD server for interfacing
with the LStore storage framework.

%prep
%setup -c -n xrootd-lstore


%build

mkdir build
pushd build

%if %{use_cmake3}
cmake3 \
%else
cmake  \
%endif

       -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=RelWithDebInfo \
      ../

make -i VERBOSE=1 %{?_smp_mflags}
popd

%install
pushd xrootd-ceph
pushd  build
make install DESTDIR=%{buildroot}
popd

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%{_libdir}/libXrdLStore-5.so
%{_libdir}/libXrdLStoreXattr-5.so

%changelog
* Tue Mar 07 2023 Eric Appelt <eric.a.appelt@vanderbilt.edu>
- Initial Release
