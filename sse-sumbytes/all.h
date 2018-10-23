#pragma once

#include "scalar.h"
#include "sse.h"
#include "sse_sadbw.h"
#include "sse_16bit.h"
#include "sse_8bit.h"

#ifdef HAVE_AVX2
#include "avx2.h"
#include "avx2_sadbw.h"
#include "avx2_16bit.h"
#endif
