#pragma once

#ifndef ainline
	#define ainline inline __attribute__((always_inline))
#endif
#ifndef sainline
	#define sainline static inline__attribute__((always_inline))
#endif
