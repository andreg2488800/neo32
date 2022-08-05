//
// Copyright (c) 2017-2022, Manticore Software LTD (https://manticoresearch.com)
// Copyright (c) 2001-2016, Andrew Aksyonoff
// Copyright (c) 2008-2016, Sphinx Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org
//

#pragma once

#include <utility>
#include "ints.h"

/// generic bytes of chars array
using ByteBlob_t = std::pair<const BYTE*, int>;

inline bool IsNull ( const ByteBlob_t& dBlob )		{ return !dBlob.second; }
inline bool IsFilled ( const ByteBlob_t& dBlob )	{ return dBlob.first && dBlob.second > 0; }
inline bool IsValid ( const ByteBlob_t& dBlob )	{ return IsNull ( dBlob ) || IsFilled ( dBlob ); }

/// blob of chars with length (for zero-copy string processing)
using Str_t = std::pair<const char*, int>;
const Str_t dEmptyStr { "", 0 };

// Str_t stuff
inline bool IsEmpty ( const Str_t& dBlob ) { return dBlob.second == 0; }
inline bool IsFilled ( const Str_t& dBlob ) { return dBlob.first && dBlob.second > 0; }
inline Str_t FromBytes ( const ByteBlob_t& sData ) { return { (const char*)sData.first, sData.second }; }
Str_t FromSz ( const char* szString ); // { return { szString, szString ? (int)strlen ( szString ) : 0 }; }

struct CSphString;
Str_t FromStr ( const CSphString& sString ); // { return { sString.cstr(), (int)sString.Length() }; }
#define FROMS( STR ) Str_t { STR, sizeof ( STR ) - 1 }

/// name+int pair
using CSphNamedInt = std::pair<CSphString, int>;

/// period of time in us
struct timespan_t
{
	int64_t m_iVal;
	explicit timespan_t ( int64_t iVal ) noexcept
		: m_iVal ( iVal ) {};
};

/// timestamp in us
struct timestamp_t
{
	int64_t m_iVal;
	explicit timestamp_t ( int64_t iVal ) noexcept
		: m_iVal ( iVal ) {};
};

#include "blobs_impl.h"