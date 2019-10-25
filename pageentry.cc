// Copyright 2009-2019 NTESS. Under the terms
// of Contract DE-NA0003525 with NTESS, the U.S.
// Government retains certain rights in this software.
//
// Copyright (c) 2009-2019, NTESS
// All rights reserved.
//
// Portions are copyright of other developers:
// See the file CONTRIBUTORS.TXT in the top level directory
// the distribution for more information.
//
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.

#include <sst/core/sst_config.h>  // unused header

#include "pageentry.h"
#include <memEvent.h>

using namespace std;
using namespace SST;
using namespace SST::MemHierarchy;
using namespace SST::Cassini;

CassiniPageEntry::CassiniPageEntry(Addr vPageStart, Addr pPageStart, uint64_t pageLen) {
    virtualPageStart = vPageStart;
    physicalPageStart = pPageStart;
    pageLength = pageLen;
    allowExec = true;
    allowRead = true;
    allowWrite = true;
}

auto CassiniPageEntry::readAllowed() -> bool { return allowRead; }

auto CassiniPageEntry::writeAllowed() -> bool { return allowWrite; }

auto CassiniPageEntry::execAllowed() -> bool { return allowExec; }

void CassiniPageEntry::markReadAllowed() { allowRead = true; }

void CassiniPageEntry::markWriteAllowed() { allowWrite = true; }

void CassiniPageEntry::markExecAllowed() { allowExec = true; }

auto CassiniPageEntry::getVirtualPageStart() -> Addr { return virtualPageStart; }

auto CassiniPageEntry::getPhysicalPageStart() -> Addr { return physicalPageStart; }

auto CassiniPageEntry::getPageLength() -> uint64_t { return pageLength; }
