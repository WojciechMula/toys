#include <math.h>

const char* fpclassifyf_str(const float x) {
	switch (fpclassify(x)) {
		case FP_NAN:
			return "NaN";

		case FP_INFINITE:
			return "infinite";

		case FP_ZERO:
			return "zero";

		case FP_SUBNORMAL:
			return "denormalized";

		case FP_NORMAL:
			return "normalized";

		default:
			return "<unknown>";
	}
}

