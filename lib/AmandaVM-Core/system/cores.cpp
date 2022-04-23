/*
 * Copyright (C) 2022 Javier Marrero
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <amanda-vm/System.h>
#include <amanda-vm-c/sdk-definitions.h>

#ifdef _W32
#   include <windows.h>
#elif defined(MACOS)
#   include <sys/param.h>
#   include <sys/sysctl.h>
#else
#   include <unistd.h>
#endif

sdk_ullong_t amanda::core::getNumberOfAvailableCores()
{
    sdk_ullong_t result = 1;
#ifdef _W32
    // Windows specific code.

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    result = systemInfo.dwNumberOfProcessors;
#elif defined(MACOS)
    // MacOSX specific code

    int nm[2] = {0};
    size_t len = 4;
    uint32_t count = 0;

    nm[0] = CTL_HW; nm[1] = HW_AVAILCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);

    if (count < 1)
    {
        nm[1] = HW_NCPU;
        sysctl(nm, 2, &count, &len, NULL, 0);
        if (count < 1) { count = 1; }
    }

    result = count;
#else
    // POSIX
    result = sysconf(_SC_NPROCESSORS_ONLN);

#endif

    return result;
}
