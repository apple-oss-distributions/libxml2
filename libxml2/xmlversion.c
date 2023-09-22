/*
 * xmlversion.c: libxml2 utility functions for versioning
 *
 * For license and disclaimer see the license and disclaimer of
 * libxml2.
 *
 * ddkilzer@apple.com
 */

#include "xmlversionInternal.h"

#ifdef __APPLE__
#include <dispatch/dispatch.h>
#include <mach-o/dyld_priv.h>
#endif

bool linkedOnOrAfterFall2022OSVersions(void)
{
#ifdef FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION
    return true;
#elif defined(LIBXML_LINKED_ON_OR_AFTER_MACOS13_IOS16_WATCHOS9_TVOS16)
    static bool result;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        result = dyld_program_minos_at_least(dyld_fall_2022_os_versions);
    });
    return result;
#else
    return true;
#endif
}
